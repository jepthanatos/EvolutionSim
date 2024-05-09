//============================================================================
// Name        : ObjectListIterator.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to iterate over a object list.
//============================================================================

#include "ObjectListIterator.h"

//==============================================================================
/* ObjectListIterator */
//==============================================================================

namespace tnt
{
    ObjectListIterator::ObjectListIterator(const ObjectList *p_l)
    {
        pList = p_l;
        first();
    }

    void ObjectListIterator::first()
    {
        index = 0;
    }

    void ObjectListIterator::next()
    {
        if (index < pList->count)
            index++;
    }

    bool ObjectListIterator::isDone()
    {
        return (index == pList->count);
    }

    Object *ObjectListIterator::currentObject() const
    {
        return pList->objects[index];
    }
}
