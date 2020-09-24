#ifndef SDLPP_EVENT_H
#define SDLPP_EVENT_H
#include "common.h"

namespace sdlpp
{

enum event_types
{
    AUDIODEVICEADDED,
    AUDIODEVICEREMOVED,
    CONTROLLERAXISMOTION,
    CONTROLLERBUTTONDOWN,
    CONTROLLERBUTTONUP,
    CONTROLLERDEVICEADDED,
    CONTROLLERDEVICEREMOVED,
    CONTROLLERDEVICEREMAPPED,
    DOLLARGESTURE,
    DOLLARRECORD,
    DROPFILE,
    DROPTEXT,
    DROPBEGIN,
    DROPCOMPLETE,
    FINGERMOTION,
    FINGERDOWN,
    FINGERUP,
    KEYDOWN,
    KEYUP,
    JOYAXISMOTION,
    JOYBALLMOTION,
    JOYHATMOTION,
    JOYBUTTONDOWN,
    JOYBUTTONUP,
    JOYDEVICEADDED,
    JOYDEVICEREMOVED,
    MOUSEMOTION,
    MOUSEBUTTONDOWN,
    MOUSEBUTTONUP,
    MOUSEWHEEL,
    MULTIGESTURE,
    QUIT,
    TEXTEDITING,
    TEXTINPUT,
    WINDOWEVENT
};

class audio_device_event
{
public:
    audio_device_event() = default;
    
    audio_device_event(const audio_device_event& event) = default;
    
    audio_device_event(audio_device_event&& event) = default;

    int get_type() const;
    
    void set_type(int type);

    std::chrono::time_point<
        std::chrono::high_resolution_clock> get_timestamp() const;

    void set_timestamp(const std::chrono::time_point<
        std::chrono::high_resolution_clock>& timestamp);

    int get_which() const;

    void set_which(int which);

    bool is_capture() const;

    void set_capture(bool capture);

private:
    int _type;
    std::chrono::time_point<std::chrono::high_resolution_clock> _timestamp;
    int _which;
    bool _capture;
};

class controller_axis_event
{

};

class controller_button_event
{

};

class controller_device_event
{

};

class dollar_gesture_event
{

};

class drop_event
{

};

class touch_finger_event
{

};

class keyboard_event
{

};

class joy_axis_event
{

};

class joy_ball_event
{

};

class joy_hat_event
{

};

class joy_button_event
{

};

class joy_device_event
{

};

class mouse_motion_event
{

};

class mouse_button_event
{

};

class mouse_wheel_event
{

};

class multi_gesture_event
{

};

class quit_event
{

};

// TODO: SDL_SysWMEvent

class text_editing_event
{

};

class text_input_event
{

};

// TODO: SDL_UserEvent ??

class window_event
{

};

#define DEFINE_CALLBACK_TYPE(EVENT_TYPE) \
    typedef std::function<void( ## EVENT_TYPE ## _event&)> EVENT_TYPE ## _callback_t

DEFINE_CALLBACK_TYPE(audio_device);
DEFINE_CALLBACK_TYPE(controller_axis);
DEFINE_CALLBACK_TYPE(controller_button);
DEFINE_CALLBACK_TYPE(controller_device);
DEFINE_CALLBACK_TYPE(dollar_gesture);
DEFINE_CALLBACK_TYPE(drop);
DEFINE_CALLBACK_TYPE(touch_finger);
DEFINE_CALLBACK_TYPE(keyboard);
DEFINE_CALLBACK_TYPE(joy_axis);
DEFINE_CALLBACK_TYPE(joy_ball);
DEFINE_CALLBACK_TYPE(joy_hat);
DEFINE_CALLBACK_TYPE(joy_button);
DEFINE_CALLBACK_TYPE(joy_device);
DEFINE_CALLBACK_TYPE(mouse_motion);
DEFINE_CALLBACK_TYPE(mouse_button);
DEFINE_CALLBACK_TYPE(mouse_wheel);
DEFINE_CALLBACK_TYPE(multi_gesture);
DEFINE_CALLBACK_TYPE(quit);
DEFINE_CALLBACK_TYPE(text_editing);
DEFINE_CALLBACK_TYPE(text_input);
DEFINE_CALLBACK_TYPE(window);
}

#endif