#include <gtest/gtest.h>

#include "../src/Vector.h"

#include <math.h>

TEST(VectorTest, Constuctor)
{
    tnt::Vector v(1, 2);
    EXPECT_FLOAT_EQ(1, v.getX());
    EXPECT_FLOAT_EQ(2, v.getY());
}

TEST(VectorTest, DefaultConstructor)
{
    tnt::Vector v;
    EXPECT_FLOAT_EQ(0, v.getX());
    EXPECT_FLOAT_EQ(0, v.getY());
}

TEST(VectorTest, SetX)
{
    tnt::Vector v;
    v.setX(33);
    ASSERT_FLOAT_EQ(33, v.getX());
}

TEST(VectorTest, SetY)
{
    tnt::Vector v;
    v.setY(33);
    ASSERT_FLOAT_EQ(33, v.getY());
}

TEST(VectorTest, SetXY)
{
    tnt::Vector v;
    v.setXY(33, 13);
    ASSERT_FLOAT_EQ(33, v.getX());
    ASSERT_FLOAT_EQ(13, v.getY());
}

TEST(VectorTest, GetMagnitude)
{
    tnt::Vector v(1, 1);
    EXPECT_FLOAT_EQ(1, v.getX());
    EXPECT_FLOAT_EQ(1, v.getY());
    ASSERT_FLOAT_EQ(sqrt(2), v.getMagnitude());
}

TEST(VectorTest, Normalize)
{
    tnt::Vector v(1, 1);
    EXPECT_FLOAT_EQ(1, v.getX());
    EXPECT_FLOAT_EQ(1, v.getY());
    ASSERT_FLOAT_EQ(sqrt(2), v.getMagnitude());
    v.normalize();
    EXPECT_FLOAT_EQ(1 / sqrt(2), v.getX());
    EXPECT_FLOAT_EQ(1 / sqrt(2), v.getY());
}

TEST(VectorTest, Scale)
{
    tnt::Vector v(1, 1);
    EXPECT_FLOAT_EQ(1, v.getX());
    EXPECT_FLOAT_EQ(1, v.getY());
    v.scale(2);
    EXPECT_FLOAT_EQ(2, v.getX());
    EXPECT_FLOAT_EQ(2, v.getY());
}

TEST(VectorTest, Sum)
{
    tnt::Vector v1(1, 1);
    tnt::Vector v2(1, 1);
    tnt::Vector v3 = v1 + v2;
    EXPECT_FLOAT_EQ(2, v3.getX());
    EXPECT_FLOAT_EQ(2, v3.getY());
}

TEST(VectorTest, Subtraction)
{
    tnt::Vector v1(3, 0);
    tnt::Vector v2(1, 1);
    tnt::Vector v3 = v1 - v2;
    EXPECT_FLOAT_EQ(2, v3.getX());
    EXPECT_FLOAT_EQ(-1, v3.getY());
}

TEST(VectorTest, OperatorEqual)
{
    tnt::Vector v1(2, 4);
    tnt::Vector v2(2, 4);
    EXPECT_TRUE(v1 == v2);
}

TEST(VectorTest, OperatorNotEqual)
{
    tnt::Vector v1(4, 2);
    tnt::Vector v2(2, 4);
    EXPECT_TRUE(v1 != v2);
}
