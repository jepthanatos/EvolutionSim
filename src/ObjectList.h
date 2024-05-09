//============================================================================
// Name        : ObjectList.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define a object list.
//============================================================================

#ifndef __OBJECT_LIST_H__
#define __OBJECT_LIST_H__

const int MAX_COUNT_INIT = 1;

// Local includes.
#include "Object.h"
#include "ObjectListIterator.h"

//==============================================================================
/* ObjectList */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define a object list.
 */
namespace tnt
{
    class ObjectListIterator;

    class ObjectList
    {
    private:
        int count; // Count of object in list.
        int max_count;
        Object **objects; // Array of pointers to objects.

    public:
        friend class ObjectListIterator;

        // Default constructor.
        ObjectList();

        // Destructor.
        ~ObjectList();

        // Copy constructor and operator =.
        ObjectList(const ObjectList &other);
        ObjectList &operator=(const ObjectList &rhs);
        bool operator!=(const ObjectList &other);

        // Insert object pointer in list.
        // Return 0 if ok, else -1.
        int insert(Object *p_o);

        // Remove object pointer from list.
        // Return 0 if found, else -1.
        int remove(Object *p_o);

        // Clear list (setting count to 0).
        void clear();

        // Return count of number of objects in list.
        int getCount() const;

        // Return true if list is empty, else false.
        bool isEmpty() const;

        // Return true if list is full, else false.
        bool isFull() const;

        // Add two lists, second appended to first.
        ObjectList operator+(ObjectList list);
    };
}
//------------------------------------------------------------------------------
#endif /* __OBJECT_LIST_H__ */
