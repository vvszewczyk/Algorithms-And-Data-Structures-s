// clang-format off
#include "pch.h"
// clang-format on
#include "Stack.hpp"
#include "gtest/gtest.h"

TEST(StackTests, Push)
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    Stack::Node *top = stack.getTop();
    std::vector<int> expected = {30, 20, 10};

    for (int &value : expected)
    {
        ASSERT_NE(top, nullptr);
        EXPECT_EQ(top->value, value);
        stack.pop();
        top = stack.getTop();
    }
    EXPECT_EQ(top, nullptr);
}
TEST(StackTests, Pop)
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(10);

    stack.pop();
    stack.pop();
    Stack::Node *top = stack.getTop();
    std::vector<int> expected = {30, 20, 10};

    for (int &value : expected)
    {
        ASSERT_NE(top, nullptr);
        EXPECT_EQ(top->value, value);
        stack.pop();
        top = stack.getTop();
    }
    EXPECT_EQ(top, nullptr);
}
TEST(StackTests, IsEmpty)
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    Stack::Node *top = stack.getTop();
    ASSERT_NE(top, nullptr);
    EXPECT_EQ(stack.isEmpty(), false);
    stack.pop();
    stack.pop();
    EXPECT_EQ(stack.isEmpty(), false);
    stack.pop();
    EXPECT_EQ(stack.isEmpty(), true);
}
TEST(StackTests, Peek)
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    Stack::Node *top = stack.getTop();
    ASSERT_NE(top, nullptr);
    EXPECT_EQ(top->value, 30);
    stack.pop();
    top = stack.getTop();
    EXPECT_EQ(top->value, 20);
    stack.push(20);
    stack.push(130);
    top = stack.getTop();
    EXPECT_EQ(top->value, 130);
}

TEST(StackTests, reverse)
{
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.reverse();
    Stack::Node *top = stack.getTop();
    std::vector<int> expected = {10, 20, 30};

    for (int &value : expected)
    {
        ASSERT_NE(top, nullptr);
        EXPECT_EQ(top->value, value);
        stack.pop();
        top = stack.getTop();
    }
    EXPECT_EQ(top, nullptr);
}

TEST(StackTests, Sort)
{
    Stack stack;
    stack.push(3);
    stack.push(1);
    stack.push(4);
    stack.push(2);
    stack.push(5);

    stack.sort();

    Stack::Node *top = stack.getTop();
    std::vector<int> expected = {1, 2, 3, 4, 5};

    for (int expectedValue : expected)
    {
        ASSERT_NE(top, nullptr);
        EXPECT_EQ(top->value, expectedValue);
        top = top->next;
    }

    EXPECT_EQ(top, nullptr);
}
