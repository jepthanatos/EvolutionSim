//============================================================================
// Name        : ObjectListIterator.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to iterate over a object list.
//============================================================================

#ifndef __OBJECT_LIST_ITERATOR_H__
#define __OBJECT_LIST_ITERATOR_H__

// Local includes.
#include "Object.h"
#include "ObjectList.h"

//==============================================================================
/* ObjectListIterator */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to iterate over a object list.
 */
namespace tnt
{
    class ObjectList;

    class ObjectListIterator
    {
    private:
        ObjectListIterator();
        const ObjectList *pList;
        int index;

    public:
        ObjectListIterator(const ObjectList *p_l);

        void first();

        void next();

        bool isDone();

        Object *currentObject() const;
    };
}
//------------------------------------------------------------------------------
#endif /* __OBJECT_LIST_ITERATOR_H__ */
