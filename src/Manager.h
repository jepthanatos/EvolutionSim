//============================================================================
// Name        : Manager.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Base class for engine managers.
//============================================================================

#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <string>

//==============================================================================
/* Manager */
//==============================================================================

/*------------------------------------------------------------------------------
 * Base class for engine managers.
 */
namespace tnt
{
    class Manager
    {
    private:
        std ::string type;  // Manager type identifier.
        bool started;       // True when started sucessfully.

    protected:
        // Set type identifier of Manager.
        void setType(std ::string value);

    public:
        Manager();
        virtual ~Manager();

        // Get type identifier of Manager.
        std::string getType() const;

        // Startup Manager.
        // Return 0 if ok, else negative number.
        virtual int startUp(){};

        // Shutdown Manager.
        virtual void shutDown(){};

        // Return true when startUp() was executed ok, else false.
        bool isStarted() const;
    };
}
//------------------------------------------------------------------------------
#endif /* __MANAGER_H__ */
