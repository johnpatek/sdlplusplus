#include "sdlpp/event.h"

int sdlpp::audio_device_event::get_type() const
{
    return _type;
}
    
void sdlpp::audio_device_event::set_type(int type)
{
    _type = type;
}

std::chrono::time_point<
    std::chrono::high_resolution_clock> sdlpp::audio_device_event::get_timestamp() const
{
    return _timestamp;
}

void sdlpp::audio_device_event::set_timestamp(const std::chrono::time_point<
    std::chrono::high_resolution_clock>& timestamp)
{
    _timestamp = timestamp;
}

int sdlpp::audio_device_event::get_which() const
{
    return _which;
}

void sdlpp::audio_device_event::set_which(int which)
{
    _which = which;
}

bool sdlpp::audio_device_event::is_capture() const
{
    return _capture;
}

void sdlpp::audio_device_event::set_capture(bool capture)
{
    _capture = capture;
}