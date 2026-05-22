"""
Mode switching logic for the Parallel Idea Engine
"""

from mode import EngineMode, CURRENT_MODE

def should_run_exploration():
    return CURRENT_MODE == EngineMode.PARALLEL_EXPLORATION

def should_run_chatbot():
    return CURRENT_MODE == EngineMode.LIGHT_CHATBOT

def switch_to_exploration():
    from mode import set_mode
    set_mode(EngineMode.PARALLEL_EXPLORATION)

def switch_to_chatbot():
    from mode import set_mode
    set_mode(EngineMode.LIGHT_CHATBOT)