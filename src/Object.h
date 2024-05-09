//============================================================================
// Name        : Object.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define a object.
//============================================================================

#ifndef __OBJECT_H__
#define __OBJECT_H__

// System includes.
#include <string>

// Local includes.
#include "Vector.h"

//==============================================================================
/* Object */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define a object.
 */
namespace tnt
{
    class Object
    {
    private:
        int id;           // Unique game engine defined identifier.
        std::string type; // Game programmer defined type.
        Vector position;  // Position in game world.

    public:
        // Construct Object.
        // Set default parameters and add to game world (WorldManager).
        Object();

        // Destroy Object.
        // Remove from game world (WorldManager).
        virtual ~Object();

        // Set Object id.
        void setId(int newId);

        // Get Object id.
        int getId() const;

        // Set type identifier of Object.
        void setType(std ::string newType);

        // Get type identifier of Object.
        std::string getType() const;

        // Set position of Object.
        void setPosition(Vector newPos);

        // Get position of Object.
        Vector getPosition() const;

        void Update();

        void print();
    };
}
//------------------------------------------------------------------------------
#endif /* __OBJECT_H__ */
