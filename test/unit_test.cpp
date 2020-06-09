#include "gtest/gtest.h"

#include "Character_test.h"
#include "Equipment_test.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
