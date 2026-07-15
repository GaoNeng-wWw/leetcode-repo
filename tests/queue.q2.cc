#include <gtest/gtest.h>
#include <vector>
#include "../src/queue.q2.cc"

TEST(Q2, CASE1) {
  Solution sol;
  std::vector<int> q = {2,3,2};
  EXPECT_EQ(sol.timeRequiredToBuy(q, 2), 6);
}