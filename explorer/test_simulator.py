#!/usr/bin/env python3
"""
Simple simulator to test the aggregator without real hardware.
"""

import time
from aggregator.aggregator import IdeaAggregator, Idea

def simulate():
    agg = IdeaAggregator()

    # Simulate results from 16 cores
    for core in range(16):
        idea = Idea(
            text=f"Simulated idea from core {core}",
            source_core=core,
            confidence=0.6 + (core % 5) * 0.07
        )
        agg.pending.append(idea)

    agg.deduplicate()
    agg.evaluate_with_grok()
    agg.notify_user()

if __name__ == "__main__":
    simulate()