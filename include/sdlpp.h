#ifndef SDLPP_H
#define SDLPP_H
#include "sdlpp/common.h"
#include "sdlpp/event.h"

namespace sdlpp
{

enum subsystem_flags
{
    NONE,
    TIMER,
    AUDIO,
    VIDEO,
    JOYSTICK,
    HAPTIC,
    GAMECONTROLLER,
    EVENTS,
    EVERYTHING
};

class system
{
private:
    bool _initialized;
    bool _event_loop_open;
    std::future<void> _future;
public:

    system();
    
    system(int flags);
    
    ~system();

    void initialize(int flags);
    
    void set_audio_device_callback(const audio_device_callback_t& callback);

    void set_controller_axis_callback(const controller_axis_callback_t& callback);

    void set_controller_button_callback(const controller_button_callback_t& callback);

    void set_controller_device_callback(const controller_device_callback_t& callback);

    void set_dollar_gesture_callback(const dollar_gesture_callback_t& callback);

    void set_drop_callback(const drop_callback_t& callback);

    void set_touch_finger_callback(const touch_finger_callback_t& callback);

    void set_keyboard_callback(const keyboard_callback_t& callback);

    void set_joy_axis_callback(const joy_axis_callback_t& callback);

    void set_joy_ball_callback(const joy_ball_callback_t& callback);

    void set_joy_hat_callback(const joy_hat_callback_t& callback);

    void set_joy_button_callback(const joy_button_callback_t& callback);

    void set_joy_device_callback(const joy_device_callback_t& callback);

    void set_mouse_motion_callback(const mouse_motion_callback_t& callback);

    void set_mouse_button_callback(const mouse_button_callback_t& callback);

    void set_mouse_wheel_callback(const mouse_wheel_callback_t& callback);

    void set_multi_gesture_callback(const multi_gesture_callback_t& callback);

    void set_quit_callback(const quit_callback_t& callback);

    void set_text_editing_callback(const text_editing_callback_t& callback);

    void set_text_input_callback(const text_input_callback_t& callback);

    void set_window_callback(const window_callback_t& callback);
    
    void open_event_loop() noexcept;
    
    void close_event_loop();

private:
    #define DECLARE_CALLBACK(EVENT_TYPE) \
        EVENT_TYPE ## _callback_t _ ## EVENT_TYPE ## _callback
    
    DECLARE_CALLBACK(audio_device);
    DECLARE_CALLBACK(controller_axis);
    DECLARE_CALLBACK(controller_button);
    DECLARE_CALLBACK(controller_device);
    DECLARE_CALLBACK(dollar_gesture);
    DECLARE_CALLBACK(drop);
    DECLARE_CALLBACK(touch_finger);
    DECLARE_CALLBACK(keyboard);
    DECLARE_CALLBACK(joy_axis);
    DECLARE_CALLBACK(joy_ball);
    DECLARE_CALLBACK(joy_hat);
    DECLARE_CALLBACK(joy_button);
    DECLARE_CALLBACK(joy_device);
    DECLARE_CALLBACK(mouse_motion);
    DECLARE_CALLBACK(mouse_button);
    DECLARE_CALLBACK(mouse_wheel);
    DECLARE_CALLBACK(multi_gesture);
    DECLARE_CALLBACK(quit);
    DECLARE_CALLBACK(text_editing);
    DECLARE_CALLBACK(text_input);
    DECLARE_CALLBACK(window);
};

}
#endif