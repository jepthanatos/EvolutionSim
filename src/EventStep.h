//============================================================================
// Name        : EventStep.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define a step event.
//============================================================================

#ifndef __EVENTSTEP_H__
#define __EVENTSTEP_H__

#include "Event.h"

const std::string STEP_EVENT = "df::step";

//==============================================================================
/* EventStep */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define a step event.
 */
class EventStep : public Event
{

private:
    int m_step_count; //Iteration number of game loop.

public:
    // Default constructor.
    EventStep();

    // Constructor with initial step count.
    EventStep(int init_step_count);

    // Set step count.
    void setStepCount(int new_step_count);

    // Get step count.
    int getStepCount() const;
};
//------------------------------------------------------------------------------
#endif /* __EVENTSTEP_H__ */
