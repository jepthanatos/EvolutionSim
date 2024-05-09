#include <gtest/gtest.h>

#include "../src/Object.h"
#include "../src/Vector.h"

TEST(ObjectTest, Constuctor)
{
    tnt::Object o;
    EXPECT_EQ(0, o.getId());
    EXPECT_STREQ("Object", o.getType().c_str());
}

TEST(ObjectTest, SetId)
{
    tnt::Object o;
    o.setId(999);
    EXPECT_EQ(999, o.getId());
}

TEST(ObjectTest, SetType)
{
    tnt::Object o;
    o.setType("Sword");
    EXPECT_EQ("Sword", o.getType());
}

TEST(ObjectTest, SetPosition)
{
    tnt::Object o;
    tnt::Vector v(1,2);
    o.setPosition(v);
    tnt::Vector v1 = o.getPosition();
    EXPECT_EQ(1, v.getX());
    EXPECT_EQ(2, v.getY());
}

TEST(ObjectTest, CompleteTest)
{
    tnt::Object o1;
    tnt::Object o2;
    // REMEMBER: the cont is static you have to count the number of object
    // created in ALL test to get the id given to the object to be created.
    EXPECT_EQ(4, o1.getId());
    EXPECT_EQ(5, o2.getId());
    o1.setId(5);
    EXPECT_TRUE(o1.getId() == o2.getId());
    tnt::Vector v(1,2);
    o1.setPosition(v);
    EXPECT_FALSE(o1.getPosition() == o2.getPosition());
}
