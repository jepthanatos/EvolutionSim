//============================================================================
// Name        : Manager.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Base class for engine managers.
//============================================================================

#include "Manager.h"

//==============================================================================
/* Manager */
//==============================================================================

namespace tnt
{
    Manager::Manager()
    {
        type = "None";
        started = false;
    }

    Manager::~Manager() {}

    /*------------------------------------------------------------------------------
     * Set type identifier of Manager.
     */
    void Manager::setType(std ::string value)
    {
        type = value;
    }

    /*------------------------------------------------------------------------------
     * Get type identifier of Manager.
     */
    std::string Manager::getType() const
    {
        return type;
    }

    /*------------------------------------------------------------------------------
     * Return true when startUp() was executed ok, else false.
     */
    bool Manager::isStarted() const
    {
        return started;
    }
}
