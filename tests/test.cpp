#include <HybridMap/HybridMap.cpp>
#include <gtest/gtest.h>

TEST(MapTests, MapInit)
{

  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
