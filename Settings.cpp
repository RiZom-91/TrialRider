#include "Settings.h"

void Settings::set_window_w(short int value)
{
    if (window_w != value) {
        window_w = value;
        has_changed = true;
    }
}

void Settings::set_window_h(short int value)
{
    if (window_h != value) {
        window_h = value;
        has_changed = true;
    }
}

bool Settings::get_has_changed()
{
    return has_changed;
}

short int Settings::get_window_w()
{
    return window_w;
}

short int Settings::get_window_h()
{
    return window_h;
}

Settings::Settings()
{
    //ctor
}

Settings::~Settings()
{
    //dtor
}
