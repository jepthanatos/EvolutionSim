//============================================================================
// Name        : Event.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define an event.
//============================================================================

#ifndef __EVENT_H__
#define __EVENT_H__

// System includes.
#include <string>

const std::string UNDEFINED_EVENT = "tnt::undefined";

//==============================================================================
/* Event */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define an event.
 */
class Event
{

private:
    std ::string m_event_type; // Holds event type .

public:
    // Create base event.
    Event();

    // Destructor.
    virtual ~Event();

    // Set event type.
    void setType(std ::string new_type);

    // Get event type.
    std ::string getType() const;
};
//------------------------------------------------------------------------------
#endif /* __EVENT_H__ */
