#include "gtest/gtest.h"

#include "VectorTest.cpp"
#include "ObjectTest.cpp"
#include "ObjectListTest.cpp"
#include "ObjectListIteratorTest.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
