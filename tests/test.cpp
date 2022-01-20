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
}

TEST(MapTests, MapInsert)
{
  HybridMap map = HybridMap<std::string, 1001, double, std::function<double(double)>>(hashFuncTest);
  std::string test = "testing_insert_1";
  map.insert(9, test);
  ASSERT_EQ(*map[9], "testing_insert_1");

  map.insert(20, "testing_insert_2");
  ASSERT_EQ(*map[20], "testing_insert_2");
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
