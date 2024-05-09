//============================================================================
// Name        : Clock.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the game loop.
//============================================================================

#include "Clock.h"

// System includes.
#include <iostream>

//==============================================================================
/* Manager */
//==============================================================================

namespace tnt
{

    /*------------------------------------------------------------------------------
     * Sets previous time to current time.
     */
    Clock::Clock(void)
    {
        previous_time = std::chrono::steady_clock::now();
    }

    /*------------------------------------------------------------------------------
     * Return time elapsed since delta() vas last called, -1 if error.
     * Resets previous time.
     * Units are miliseconds.
     */
    std::chrono::milliseconds Clock::delta()
    {
        auto end = std::chrono::steady_clock::now();
        auto aux1 =
            std::chrono::time_point_cast<std::chrono::milliseconds>(end);
        auto aux2 =
            std::chrono::time_point_cast<std::chrono::milliseconds>(previous_time);
        std::chrono::milliseconds elapsed_time = aux1 - aux2;
        previous_time = end;
        return elapsed_time;
    }

    /*------------------------------------------------------------------------------
     * Return time elapsed since delta() las last called, -1 if error.
     * Does not reset previous time.
     * Units are miliseconds.
     */
    std::chrono::milliseconds Clock::split() const
    {

        auto end = std::chrono::steady_clock::now();
        auto aux1 =
            std::chrono::time_point_cast<std::chrono::milliseconds>(end);
        auto aux2 =
            std::chrono::time_point_cast<std::chrono::milliseconds>(previous_time);
        std::chrono::milliseconds elapsed_time = aux1 - aux2;
        return std::chrono::milliseconds(elapsed_time);
    }
}
