//============================================================================
// Name        : Object.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description :
//============================================================================

#include "Object.h"
#include "LogManager.h"

#include <string>
#include <sstream>

//==============================================================================
/* Object */
//==============================================================================

namespace tnt
{
    /*------------------------------------------------------------------------------
     * Default constructor.
     */
    Object::Object()
    {
        static int cont{0};
        id = cont;
        type = "Object";
        ++cont;
    }

    /*------------------------------------------------------------------------------
     * Destructor.
     */
    Object::~Object()
    {
        // TODO
    }

    /*------------------------------------------------------------------------------
     * Get Object id.
     */
    int Object::getId(void) const
    {
        return id;
    }

    /*------------------------------------------------------------------------------
     * Set Object id.
     */
    void Object::setId(int newId)
    {
        id = newId;
    }

    /*------------------------------------------------------------------------------
     * Set type identifier of Object.
     */
    void Object::setType(std ::string newType)
    {
        type = newType;
    }

    /*------------------------------------------------------------------------------
     *  Get type identifier of Object.
     */
    std::string Object::getType() const
    {
        return type;
    }

    /*------------------------------------------------------------------------------
     * Set position of Object.
     */
    void Object::setPosition(Vector newPos)
    {
        position = newPos;
    }

    /*------------------------------------------------------------------------------
     *  Get position of Object.
     */
    Vector Object::getPosition() const
    {
        return position;
    }

    void Object::print()
    {
        std::ostringstream message;
        message << "Printing an object info: " << std::endl
                << "- Game identifier: " << id << std::endl
                << "- Defined type: " << type << std::endl
                << "- Vector position: " << position.print();

        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, message.str());
    }
}
