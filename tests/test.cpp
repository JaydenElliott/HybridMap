#include <HybridMap.hpp>
#include <gtest/gtest.h>

int hashFuncTest(double test)
{
  return test;
}
TEST(MapTests, MapInit)
{
  HybridMap map = HybridMap<std::string, 1000, double, std::function<double(double)>>(hashFuncTest);
  map.insert(1000, "testing");
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
