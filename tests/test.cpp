#include <HybridMap.hpp>
#include <gtest/gtest.h>
#include <iostream>

int hashFuncTest(double test)
{
  return test;
}

TEST(MapTests, MapInit)
{
  HybridMap map = HybridMap<std::string, 1001, double, std::function<double(double)>>(hashFuncTest);
  std::string test = "testing";
  map.insert(9, test);
  // map.insert(9, "testing");
  // map.printMap();
  ASSERT_EQ(*map[9], "testing");
  // std::cout << map[1000].data;
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
