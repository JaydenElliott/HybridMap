#include <HybridMap.cpp>
#include <gtest/gtest.h>

double hashFuncTest(double test)
{
  return test;
}
TEST(MapTests, MapInit)
{
  // auto hashFunction = [](double key) { return key; };
  HybridMap map = HybridMap<double, 1000, std::function<double()>(double), double>(hashFuncTest);
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
