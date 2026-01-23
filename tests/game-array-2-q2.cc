#include <gtest/gtest.h>
#include <vector>
#include "../src/game-array-2-q2.cc"

using namespace std;

// 1. 定义一个结构体存放输入和预期的输出
struct TestCase {
  vector<int> nums;
  vector<int> expected;
};

// 2. 创建测试类
class SmallerNumbersParamTest : public ::testing::TestWithParam<TestCase> {};

// 3. 编写测试逻辑
TEST_P(SmallerNumbersParamTest, CheckResult) {
  auto param = GetParam(); // 获取当前的测试数据对
  Solution sol;
  
  vector<int> actual = sol.smallerNumbersThanCurrent(param.nums);
  
  // 修正：使用 param.expected 而不是直接写 expected
  EXPECT_EQ(actual, param.expected); 
}

// 4. 注入你提供的那些 Case
INSTANTIATE_TEST_SUITE_P(
    LeetCode_1365,
    SmallerNumbersParamTest,
    ::testing::Values(
        TestCase{{8, 1, 2, 2, 3}, {4, 0, 1, 1, 3}},
        TestCase{{6, 5, 4, 8},    {2, 1, 0, 3}},
        TestCase{{7, 7, 7, 7},    {0, 0, 0, 0}}
    )
);