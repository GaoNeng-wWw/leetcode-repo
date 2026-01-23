#include <gtest/gtest.h>
#include "../src/stack.q2.cc" // 假设上面的代码在这个头文件里

// 测试用例 1: 基础加法和乘法
TEST(RPNTest, BasicExample) {
    Solution sol;
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    EXPECT_EQ(sol.evalRPN(tokens), 9);
}

// 测试用例 2: 包含除法和整数截断
TEST(RPNTest, DivisionExample) {
    Solution sol;
    std::vector<std::string> tokens = {"4", "13", "5", "/", "+"};
    // 13 / 5 = 2 (C++ 默认向零取整)
    // 4 + 2 = 6
    EXPECT_EQ(sol.evalRPN(tokens), 6);
}

// 测试用例 3: 复杂表达式与负数
TEST(RPNTest, ComplexExample) {
    Solution sol;
    std::vector<std::string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    EXPECT_EQ(sol.evalRPN(tokens), 22);
}

// 补充测试：单个数字
TEST(RPNTest, SingleNumber) {
    Solution sol;
    std::vector<std::string> tokens = {"42"};
    EXPECT_EQ(sol.evalRPN(tokens), 42);
}

// 补充测试：包含负数运算
TEST(RPNTest, NegativeNumbers) {
    Solution sol;
    std::vector<std::string> tokens = {"3", "-4", "+"};
    EXPECT_EQ(sol.evalRPN(tokens), -1);
}