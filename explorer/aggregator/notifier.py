"""
Notification layer for the Parallel Idea Engine.
Supports multiple channels (Telegram, Email, X, Discord, etc.)
"""

class Notifier:
    def __init__(self, channel="console"):
        self.channel = channel

    def send(self, message: str):
        if self.channel == "console":
            print(f"[Notification] {message}")
        elif self.channel == "telegram":
            # TODO: Implement Telegram bot
            pass
        elif self.channel == "email":
            # TODO: Implement SMTP
            pass
        else:
            print(f"[Notification:{self.channel}] {message}")