//============================================================================
// Name        : ObjectList.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description :
//============================================================================

#include "ObjectList.h"
#include "LogManager.h"

#include <string>
#include <sstream>

#include <stdio.h>
#include <string.h>

//==============================================================================
/* ObjectList */
//==============================================================================

namespace tnt
{
    /*------------------------------------------------------------------------------
     * Default constructor.
     */
    ObjectList::ObjectList(void)
    {
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "ObjectList Constructor");
        count = 0;
        max_count = MAX_COUNT_INIT;
        objects = (Object **)malloc(sizeof(Object *) * max_count);
    }

    /*------------------------------------------------------------------------------
     * Destructor.
     */
    ObjectList::~ObjectList(void)
    {
        if (objects != NULL)
        {
            free(objects);
        }
    }

    /*------------------------------------------------------------------------------
     * Copy constructor.
     */
    ObjectList::ObjectList(const ObjectList &other)
    {
        objects = (Object **)malloc(sizeof(Object *) * other.max_count);
        if (objects != NULL)
        {
            if (memcpy(objects, other.objects, sizeof(Object *) * other.max_count) != NULL)
            {
                max_count = other.max_count;
                count = other.count;
            }
        }
    }

    /*------------------------------------------------------------------------------
     * Operator =
     */
    ObjectList &ObjectList::operator=(const ObjectList &rhs)
    {
        if (*this != rhs)
        {
            if (objects != NULL)
            {
                free(objects);
            }
            objects = (Object **)malloc(sizeof(Object *) * rhs.max_count);
            if (objects != NULL)
            {
                if (memcpy(objects, rhs.objects, sizeof(Object *) * rhs.max_count) != NULL)
                {
                    max_count = rhs.max_count;
                    count = rhs.count;
                }
            }
        }
    }

    /*------------------------------------------------------------------------------
     * Operator !=
     */
    bool ObjectList::operator!=(const ObjectList &other){
        return !((*this->objects) == *other.objects);
    }

    /*------------------------------------------------------------------------------
     * Insert object pointer in list.
     * Return 0 if ok, else -1.
     * TODO: check if the object already exists in the list and modify the tests.
     */
    int ObjectList::insert(Object *object)
    {
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "ObjectList insert new element.");
        //object->print();
        if (count == max_count)
        {
            LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Making list bigger.");
            Object **tempObjects;
            tempObjects = (Object **)realloc(objects, 2 * sizeof(Object *) * max_count);
            if (tempObjects != NULL)
            {
                objects = tempObjects;
                max_count *= 2;
            }
            else
                return -1;
        }
        objects[count] = object;
        count++;
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Number of elements in list: " + std::to_string(count));
        return 0;
    }

    /*------------------------------------------------------------------------------
     * Remove object pointer from list.
     * Return 0 if found, else -1.
     * TODO: expect the max_count to be the half and realloc memory?
     */
    int ObjectList::remove(Object *object)
    {
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Remove element.");
        for (int i = 0; i < count; i++)
        {
            if (objects[i] == object)
            {
                // Pop last item from the end and swap over item to delete.
                objects[i] = objects[count - 1];
                count--;
                return true; // Found.
            }
        }
        return false; // Not found.
    }

    /*------------------------------------------------------------------------------
     * Clear list (setting count to 0).
     */
    void ObjectList::clear()
    {
        count = 0;
    }

    /*------------------------------------------------------------------------------
     * Return count of number of objects in list.
     */
    int ObjectList::getCount() const
    {
        return count;
    }

    /*------------------------------------------------------------------------------
     * Return true if list is empty, else false.
     */
    bool ObjectList::isEmpty() const
    {
        return count == 0;
    }

    /*------------------------------------------------------------------------------
     * Return true if list is full, else false.
     */
    bool ObjectList::isFull() const
    {
        return count == max_count;
    }

    /*------------------------------------------------------------------------------
     * Add two lists, second appended to first.
     */
    ObjectList ObjectList::operator+(ObjectList list)
    {
        // Start with first list.
        ObjectList finalList = *this;

        // Iterate through second list, adding each element.
        ObjectListIterator listIter(&list);
        for (listIter.first(); not listIter.isDone(); listIter.next())
        {
            Object *pObject = listIter.currentObject();
            finalList.insert(pObject);
        }

        // Return combined list.
        return finalList;
    }
}
