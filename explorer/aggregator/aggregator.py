"""
Parallel Idea Aggregator v0.4

Collects results from all Epiphany cores, deduplicates,
scores them, and forwards high-value ideas to Grok.
Also handles light chatbot check-ins.
"""

import time
from typing import List
from shared_memory import EpiphanyMemoryReader
from decision import should_send_checkin, get_mode_priority
from chatbot_prompts import get_checkin_prompt
from grok_client import GrokClient

class Idea:
    def __init__(self, text: str, source_core: int, confidence: float):
        self.text = text
        self.source_core = source_core
        self.confidence = confidence
        self.grok_score = 0.0

    def __repr__(self):
        return f"Idea(core={self.source_core}, conf={self.confidence:.2f}): {self.text[:60]}..."


class IdeaAggregator:
    def __init__(self):
        self.seen = set()
        self.pending: List[Idea] = []
        self.high_value: List[Idea] = []
        self.mem_reader = EpiphanyMemoryReader()
        self.grok = GrokClient()

    def collect_results(self):
        """Read new results from Epiphany shared memory"""
        self.mem_reader.open()
        # TODO: Parse actual shared memory
        self.mem_reader.close()

    def deduplicate(self):
        unique = []
        for idea in self.pending:
            key = idea.text[:40]
            if key not in self.seen:
                self.seen.add(key)
                unique.append(idea)
        self.pending = unique

    def evaluate_with_grok(self):
        for idea in self.pending:
            if idea.confidence > 0.75:
                idea.grok_score = 0.85
                self.high_value.append(idea)

    def handle_chatbot_mode(self):
        if should_send_checkin():
            prompt = get_checkin_prompt()
            result = self.grok.evaluate_ideas([prompt])
            if result:
                print(f"[Chatbot] {result[0]['refined_text']}")

    def notify_user(self):
        if self.high_value:
            print(f"[Aggregator] Found {len(self.high_value)} interesting ideas")
            for idea in self.high_value:
                print(f"  → {idea}")
            self.high_value.clear()

    def run_loop(self, interval: int = 30):
        while True:
            mode = get_mode_priority()

            if mode == "chatbot":
                self.handle_chatbot_mode()
            else:
                self.collect_results()
                self.deduplicate()
                self.evaluate_with_grok()
                self.notify_user()

            time.sleep(interval)