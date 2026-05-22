"""
Decision logic for when to surface output in different modes.
"""

import time
from datetime import datetime, timedelta

last_user_interaction = datetime.now()

def update_last_interaction():
    global last_user_interaction
    last_user_interaction = datetime.now()

def should_send_checkin() -> bool:
    """Send a casual check-in if user has been quiet for a while"""
    hours_since = (datetime.now() - last_user_interaction).total_seconds() / 3600
    return hours_since > 48  # 2 days

def should_run_deep_exploration() -> bool:
    """Run full parallel exploration more frequently"""
    return True  # For now, always run exploration in background

def get_mode_priority():
    """Return which mode should take priority right now"""
    if should_send_checkin():
        return "chatbot"
    return "exploration"