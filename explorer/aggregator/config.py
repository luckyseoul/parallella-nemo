"""
Configuration for the Parallel Idea Engine
"""

class EngineConfig:
    def __init__(self):
        self.poll_interval = 30          # seconds between aggregator runs
        self.min_confidence = 0.70       # threshold to forward to Grok
        self.notification_channel = "console"
        self.grok_model = "grok-4.3"
        self.max_ideas_per_cycle = 8

    def load_from_file(self, path: str):
        # TODO: Support JSON/YAML config files
        pass

CONFIG = EngineConfig()