#include <gtest/gtest.h>

#include "../src/ObjectListIterator.h"

TEST(ObjectListIteratorTest, EmptyList)
{
    tnt::ObjectList ol;
    tnt::ObjectListIterator li(&ol);
    EXPECT_TRUE(li.isDone());
}

TEST(ObjectListIteratorTest, AddOneObject)
{
    tnt::ObjectList ol;
    tnt::ObjectListIterator li(&ol);
    tnt::Object o;
    ol.insert(&o);
    EXPECT_FALSE(li.isDone());
    li.next();
    EXPECT_TRUE(li.isDone());
}

TEST(ObjectListIteratorTest, AddSeveralObjects)
{
    tnt::ObjectList ol;
    tnt::ObjectListIterator li(&ol);
    tnt::Object o;
    for (int i = 0; i < 10; i++)
    {
        ol.insert(&o);
    }
    EXPECT_FALSE(li.isDone());
    for (int i = 0; i < 10; i++)
    {
        li.next();
    }
    EXPECT_TRUE(li.isDone());
}

TEST(ObjectListIteratorTest, AddOneObjectThenRemove)
{
    tnt::ObjectList ol;
    tnt::ObjectListIterator li(&ol);
    tnt::Object o;
    ol.insert(&o);
    ol.remove(&o);
    EXPECT_TRUE(li.isDone());
}
