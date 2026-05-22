"""
Parallel Idea Aggregator v0.2

Collects results from all Epiphany cores, deduplicates,
scores them, and forwards high-value ideas to Grok.
"""

import time
from typing import List, Dict

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

    def collect_results(self):
        """Read new results from Epiphany shared memory (stub)"""
        # TODO: Implement actual shared memory read
        pass

    def deduplicate(self):
        """Remove duplicate or near-duplicate ideas"""
        unique = []
        for idea in self.pending:
            key = idea.text[:40]  # crude dedup
            if key not in self.seen:
                self.seen.add(key)
                unique.append(idea)
        self.pending = unique

    def evaluate_with_grok(self):
        """Send promising ideas to Grok for deeper evaluation"""
        # TODO: Call Grok OAuth endpoint
        for idea in self.pending:
            if idea.confidence > 0.75:
                idea.grok_score = 0.85  # placeholder
                self.high_value.append(idea)

    def notify_user(self):
        """Push high-value ideas to user"""
        if self.high_value:
            print(f"[Aggregator] Found {len(self.high_value)} interesting ideas")
            for idea in self.high_value:
                print(f"  → {idea}")
            self.high_value.clear()

    def run_loop(self, interval: int = 30):
        """Main loop"""
        while True:
            self.collect_results()
            self.deduplicate()
            self.evaluate_with_grok()
            self.notify_user()
            time.sleep(interval)