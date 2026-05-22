"""
Notification layer for the Parallel Idea Engine.

Supports multiple channels using lightweight, reliable methods.
"""

import json
import socket
import urllib.request
from typing import Optional


class Notifier:
    def __init__(self, channel: str = "console", config: Optional[dict] = None):
        self.channel = channel
        self.config = config or {}

    def send(self, message: str):
        if self.channel == "console":
            self._send_console(message)
        elif self.channel == "discord":
            self._send_discord(message)
        elif self.channel == "irc":
            self._send_irc(message)
        elif self.channel == "telegram":
            self._send_telegram(message)
        elif self.channel == "email":
            self._send_email(message)
        else:
            print(f"[Notification:{self.channel}] {message}")

    # --- Console ---
    def _send_console(self, message: str):
        print(f"[Idea Engine] {message}")

    # --- Discord (Webhook) ---
    def _send_discord(self, message: str):
        webhook_url = self.config.get("discord_webhook")
        if not webhook_url:
            print("[Discord] No webhook URL configured")
            return

        payload = {"content": message}
        data = json.dumps(payload).encode("utf-8")
        req = urllib.request.Request(webhook_url, data=data, headers={"Content-Type": "application/json"})

        try:
            with urllib.request.urlopen(req, timeout=10) as response:
                if response.status != 204:
                    print(f"[Discord] Webhook failed: {response.status}")
        except Exception as e:
            print(f"[Discord] Error: {e}")

    # --- IRC ---
    def _send_irc(self, message: str):
        server = self.config.get("irc_server", "irc.libera.chat")
        port = self.config.get("irc_port", 6667)
        nick = self.config.get("irc_nick", "parallella_bot")
        channel = self.config.get("irc_channel")

        if not channel:
            print("[IRC] No channel configured")
            return

        try:
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.connect((server, port))
            sock.send(f"NICK {nick}\r\n".encode())
            sock.send(f"USER {nick} 0 * :Parallel Idea Engine\r\n".encode())
            sock.send(f"JOIN {channel}\r\n".encode())
            sock.send(f"PRIVMSG {channel} :{message}\r\n".encode())
            sock.close()
        except Exception as e:
            print(f"[IRC] Error: {e}")

    # --- Telegram (stub) ---
    def _send_telegram(self, message: str):
        token = self.config.get("telegram_token")
        chat_id = self.config.get("telegram_chat_id")
        if not token or not chat_id:
            print("[Telegram] Token or chat_id not configured")
            return
        # TODO: Implement using requests + Telegram Bot API
        print(f"[Telegram] Would send: {message}")

    # --- Email (stub) ---
    def _send_email(self, message: str):
        # TODO: Implement using smtplib
        print(f"[Email] Would send: {message}")