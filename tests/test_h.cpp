#include <gtest/gtest.h>
#include "../include/functions.h"
#include "../include/structures.h"

TEST(TestAverage, HandleAverage) {
  const int N = 1;
  Student s[N]= {{"Кулаковський", 1, INFORMATIONAL_SYSTEMS_AND_TECHNOLOGIES, 5, 5, 5}};
  float average = CountAverageMark(s, 0);
  EXPECT_EQ(average, 5);
}