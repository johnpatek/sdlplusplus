#include "sdlpp.h"
#include <SDL.h>

// BEGIN HELPER FUNCTIONS

#define CREATE_EVENT(TYPE)                                           \
    static void create_ ## TYPE ## _event(                           \
        sdlpp:: ## TYPE ## _event& event,                            \
        const SDL_Event& data)

static int get_event_type(const SDL_Event& event)
{
    int result;
#define SDL_TO_SDLPP_EVENT(EVENT)                                     \
    if(event.type == SDL_ ## EVENT)                                   \
    {                                                                 \
        result = sdlpp::event_types:: ## EVENT;                       \
    }
    SDL_TO_SDLPP_EVENT(AUDIODEVICEADDED)
    SDL_TO_SDLPP_EVENT(AUDIODEVICEREMOVED)
    SDL_TO_SDLPP_EVENT(CONTROLLERAXISMOTION)
    SDL_TO_SDLPP_EVENT(CONTROLLERBUTTONDOWN)
    SDL_TO_SDLPP_EVENT(CONTROLLERBUTTONUP)
    SDL_TO_SDLPP_EVENT(CONTROLLERDEVICEADDED)
    SDL_TO_SDLPP_EVENT(CONTROLLERDEVICEREMOVED)
    SDL_TO_SDLPP_EVENT(CONTROLLERDEVICEREMAPPED)
    SDL_TO_SDLPP_EVENT(DOLLARGESTURE)
    SDL_TO_SDLPP_EVENT(DOLLARRECORD)
    SDL_TO_SDLPP_EVENT(DROPFILE)
    SDL_TO_SDLPP_EVENT(DROPTEXT)
    SDL_TO_SDLPP_EVENT(DROPBEGIN)
    SDL_TO_SDLPP_EVENT(DROPCOMPLETE)
    SDL_TO_SDLPP_EVENT(FINGERMOTION)
    SDL_TO_SDLPP_EVENT(FINGERDOWN)
    SDL_TO_SDLPP_EVENT(FINGERUP)
    SDL_TO_SDLPP_EVENT(KEYDOWN)
    SDL_TO_SDLPP_EVENT(KEYUP)
    SDL_TO_SDLPP_EVENT(JOYAXISMOTION)
    SDL_TO_SDLPP_EVENT(JOYBALLMOTION)
    SDL_TO_SDLPP_EVENT(JOYHATMOTION)
    SDL_TO_SDLPP_EVENT(JOYBUTTONDOWN)
    SDL_TO_SDLPP_EVENT(JOYBUTTONUP)
    SDL_TO_SDLPP_EVENT(JOYDEVICEADDED)
    SDL_TO_SDLPP_EVENT(JOYDEVICEREMOVED)
    SDL_TO_SDLPP_EVENT(MOUSEMOTION)
    SDL_TO_SDLPP_EVENT(MOUSEBUTTONDOWN)
    SDL_TO_SDLPP_EVENT(MOUSEBUTTONUP)
    SDL_TO_SDLPP_EVENT(MOUSEWHEEL)
    SDL_TO_SDLPP_EVENT(MULTIGESTURE)
    SDL_TO_SDLPP_EVENT(QUIT)
    SDL_TO_SDLPP_EVENT(TEXTEDITING)
    SDL_TO_SDLPP_EVENT(TEXTINPUT)
    SDL_TO_SDLPP_EVENT(WINDOWEVENT)
    return result;
}

CREATE_EVENT(audio_device)
{
    const SDL_AudioDeviceEvent& sdl_event = data.adevice;
    event.set_type(get_event_type(data));
    event.set_timestamp(std::chrono::high_resolution_clock::now());
    event.set_which(static_cast<int>(sdl_event.which));
    event.set_capture(sdl_event.iscapture != 0);
}

CREATE_EVENT(controller_axis)
{

}

CREATE_EVENT(controller_button)
{

}

CREATE_EVENT(controller_device)
{

}

CREATE_EVENT(dollar_gesture)
{

}

CREATE_EVENT(drop)
{

}

CREATE_EVENT(touch_finger)
{

}

CREATE_EVENT(keyboard)
{

}

CREATE_EVENT(joy_axis)
{

}

CREATE_EVENT(joy_ball)
{

}

CREATE_EVENT(joy_hat)
{

}

CREATE_EVENT(joy_button)
{

}

CREATE_EVENT(joy_device)
{

}

CREATE_EVENT(mouse_motion)
{

}

CREATE_EVENT(mouse_button)
{

}

CREATE_EVENT(mouse_wheel)
{

}

CREATE_EVENT(multi_gesture)
{

}

CREATE_EVENT(quit)
{

}

CREATE_EVENT(text_editing)
{

}

CREATE_EVENT(text_input)
{

}

CREATE_EVENT(window)
{

}

// END HELPER FUNCTIONS

sdlpp::system::~system()
{
    if(_event_loop_open)
    {
        close_event_loop();
    }

    if(_initialized)
    {
        SDL_Quit();
    }
}

void sdlpp::system::open_event_loop() noexcept
{
    _event_loop_open = true;
#define EVENT_OBJECT(TYPE) sdlpp:: ## TYPE ## _event TYPE ## _event_object;
    EVENT_OBJECT(audio_device)
    EVENT_OBJECT(controller_axis)
    EVENT_OBJECT(controller_button)
    EVENT_OBJECT(controller_device)
    EVENT_OBJECT(dollar_gesture)
    EVENT_OBJECT(drop)
    EVENT_OBJECT(touch_finger)
    EVENT_OBJECT(keyboard)
    EVENT_OBJECT(joy_axis)
    EVENT_OBJECT(joy_ball)
    EVENT_OBJECT(joy_hat)
    EVENT_OBJECT(joy_button)
    EVENT_OBJECT(joy_device)
    EVENT_OBJECT(mouse_motion)
    EVENT_OBJECT(mouse_button)
    EVENT_OBJECT(mouse_wheel)
    EVENT_OBJECT(multi_gesture)
    EVENT_OBJECT(quit)
    EVENT_OBJECT(text_editing)
    EVENT_OBJECT(text_input)
    EVENT_OBJECT(window)
#define DISPATCH_EVENT(TYPE) \
    create_ ## TYPE ## _event(## TYPE ## _event_object,sdl_event); \
    _ ## TYPE ## _callback(## TYPE ## _event_object)
    _future = std::async(
        std::launch::async,
        [&]
        {
            SDL_Event sdl_event;
            while(_event_loop_open)
            {
                if(SDL_PollEvent(&sdl_event) == 1)
                {
                    switch (sdl_event.type)
                    {
                    case SDL_AUDIODEVICEADDED:
                    case SDL_AUDIODEVICEREMOVED:
                        DISPATCH_EVENT(audio_device);
                        break;
                    case SDL_CONTROLLERAXISMOTION:
                        DISPATCH_EVENT(controller_axis);
                        break;
                    case SDL_CONTROLLERBUTTONDOWN:
                    case SDL_CONTROLLERBUTTONUP:
                        DISPATCH_EVENT(controller_button);
                        break;
                    case SDL_CONTROLLERDEVICEADDED:
                    case SDL_CONTROLLERDEVICEREMOVED:
                    case SDL_CONTROLLERDEVICEREMAPPED:
                        DISPATCH_EVENT(controller_device);
                        break;
                    case SDL_DOLLARGESTURE:
                    case SDL_DOLLARRECORD:
                        DISPATCH_EVENT(dollar_gesture);
                        break;
                    case SDL_DROPFILE:
                    case SDL_DROPTEXT:
                    case SDL_DROPBEGIN:
                    case SDL_DROPCOMPLETE:
                        DISPATCH_EVENT(drop);
                        break;
                    case SDL_FINGERMOTION:
                    case SDL_FINGERDOWN:
                    case SDL_FINGERUP:
                        DISPATCH_EVENT(touch_finger);
                        break;
                    case SDL_KEYDOWN:
                    case SDL_KEYUP:
                        DISPATCH_EVENT(keyboard);
                        break;
                    case SDL_JOYAXISMOTION:
                        DISPATCH_EVENT(joy_axis);
                        break;
                    case SDL_JOYBALLMOTION:
                        DISPATCH_EVENT(joy_ball);
                    default:
                        break;
                    }
                }
            }
        });
}

void sdlpp::system::close_event_loop()
{
    _event_loop_open = false;
    _future.wait();
}

#define SET_CALLBACK(EVENT_TYPE) \
void sdlpp::system::set_ ## EVENT_TYPE ## _callback(const EVENT_TYPE ## _callback_t& callback) \
{                                                                                              \
    _ ## EVENT_TYPE ## _callback = callback;                                                   \
}

SET_CALLBACK(audio_device)
SET_CALLBACK(controller_axis)
SET_CALLBACK(controller_button)
SET_CALLBACK(controller_device)
SET_CALLBACK(dollar_gesture)
SET_CALLBACK(drop)
SET_CALLBACK(touch_finger)
SET_CALLBACK(keyboard)
SET_CALLBACK(joy_axis)
SET_CALLBACK(joy_ball)
SET_CALLBACK(joy_hat)
SET_CALLBACK(joy_button)
SET_CALLBACK(joy_device)
SET_CALLBACK(mouse_motion)
SET_CALLBACK(mouse_button)
SET_CALLBACK(mouse_wheel)
SET_CALLBACK(multi_gesture)
SET_CALLBACK(quit)
SET_CALLBACK(text_editing)
SET_CALLBACK(text_input)
SET_CALLBACK(window)