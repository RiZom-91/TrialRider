#ifndef SETTINGS_H
#define SETTINGS_H

#include <constants.h>


class Settings
{
    public:

        /// Setters
        void set_window_w(short int value);
        void set_window_h(short int value);

        /// Getters
        bool get_has_changed();
        short int get_window_w();
        short int get_window_h();

        /// Methods

        /// Constructor & destructor
        Settings();
        virtual ~Settings();
    protected:
    private:

        /// Properties
        bool has_changed = false;
        short int window_w = DEFAULT_WINDOW_W;
        short int window_h = DEFAULT_WINDOW_H;
};

#endif // SETTINGS_H
