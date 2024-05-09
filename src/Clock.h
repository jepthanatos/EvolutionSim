//============================================================================
// Name        : Clock.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define a clock.
//============================================================================

#ifndef __CLOCK_H__
#define __CLOCK_H__

#include <string>
#include <chrono>

//==============================================================================
/* Clock */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define a clock.
 */
namespace tnt
{
    class Clock
    {
    private:
        // Previous time delta() called (in microsec).
        std::chrono::time_point<std::chrono::steady_clock> previous_time;

    public:
        // Sets previous time to current time.
        Clock();

        // Return time elapsed since delta() vas last called, -1 if error.
        // Resets previous time.
        // Units are miliseconds.
        std::chrono::milliseconds delta();

        // Return time elapsed since delta() las last called, -1 if error.
        // Does not reset previous time.
        // Units are miliseconds.
        std::chrono::milliseconds split() const;
    };
}
//------------------------------------------------------------------------------
#endif /* __CLOCK_H__ */
