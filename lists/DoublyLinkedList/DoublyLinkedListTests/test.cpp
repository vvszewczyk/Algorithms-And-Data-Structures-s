// clang-format off
#include "pch.h"
// clang-format on
#include "DoublyLinkedList.hpp"
#include "gtest/gtest.h"
TEST(DoublyLinkedListTests, PushFrontWhenHeadEmpty)
{
    DoublyLinkedList list;
    list.pushFront(10);
    DoublyLinkedList::Node *head = list.getHead();

    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->value, 10);
    EXPECT_EQ(head->prev, nullptr);
    EXPECT_EQ(head->next, nullptr);
}
TEST(DoublyLinkedListTests, PushFrontAddMultiple)
{
    DoublyLinkedList list;
    list.pushFront(10);
    list.pushFront(20);
    list.pushFront(30);
    DoublyLinkedList::Node *head = list.getHead();

    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->value, 30);
    EXPECT_EQ(head->prev, nullptr);

    EXPECT_EQ(head->next->value, 20);
    EXPECT_EQ(head->next->prev->value, 30);

    EXPECT_EQ(head->next->next->value, 10);
    EXPECT_EQ(head->next->next->prev->value, 20);
    EXPECT_EQ(head->next->next->next, nullptr);
}
TEST(DoublyLinkedListTests, PopFrontCorrectly)
{
    DoublyLinkedList list;
    list.pushFront(10);
    list.pushFront(20);
    list.pushFront(30);
    list.popFront();
    DoublyLinkedList::Node *curr = list.getHead();

    std::vector<int> expected = {20, 10};
    for (int &value : expected)
    {
        ASSERT_NE(curr, nullptr) << "Unexpected nullptr while checking value " << value;
        EXPECT_EQ(curr->value, value) << "Mismatch at value: expected " << value;
        curr = curr->next;
    }

    EXPECT_EQ(curr, nullptr) << "List should end with nullptr";
}
TEST(DoublyLinkedListTests, PushBackWhenHeadEmpty)
{
    DoublyLinkedList list;
    list.pushBack(15);
    DoublyLinkedList::Node *head = list.getHead();

    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->value, 15);
    EXPECT_EQ(head->next, nullptr);
    EXPECT_EQ(head->prev, nullptr);
}
TEST(DoublyLinkedListTests, PushBackAddMultiple)
{
    DoublyLinkedList list;
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    DoublyLinkedList::Node *head = list.getHead();

    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->value, 10);
    EXPECT_EQ(head->prev, nullptr);

    EXPECT_EQ(head->next->value, 20);
    EXPECT_EQ(head->next->prev->value, 10);

    EXPECT_EQ(head->next->next->value, 30);
    EXPECT_EQ(head->next->next->prev->value, 20);
    EXPECT_EQ(head->next->next->next, nullptr);
}
TEST(DoublyLinkedListTests, PopBackCorrectly)
{
    DoublyLinkedList list;
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    list.popBack();
    DoublyLinkedList::Node *curr = list.getHead();
    std::vector<int> expected = {10, 20};

    for (int &value : expected)
    {
        ASSERT_NE(curr, nullptr) << "Unexpected nullptr while checking value " << value;
        EXPECT_EQ(curr->value, value) << "Mismatch at value: expected " << value;
        curr = curr->next;
    }

    EXPECT_EQ(curr, nullptr) << "List should end with nullptr";
}
TEST(DoublyLinkedListTests, PushAtPositionWhenHeadEmpty)
{
    DoublyLinkedList list;
    DoublyLinkedList::Node *head = list.getHead();
    ASSERT_EQ(head, nullptr);
    list.pushAtPosition(1337, 1337);
    head = list.getHead();
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->value, 1337);
    EXPECT_EQ(head->next, nullptr);
    EXPECT_EQ(head->prev, nullptr);
}
TEST(DoublyLinkedListTests, PushAtVariousPosition)
{
    DoublyLinkedList list;
    std::vector<std::pair<int, std::size_t>> data = {
        {10, 0}, {20, 1}, {30, 1}, {40, 100}, {50, 0},
    };

    for (std::pair<int, std::size_t> &pair : data)
    {
        list.pushAtPosition(pair.first, pair.second);
    }

    DoublyLinkedList::Node *curr = list.getHead();
    std::vector<int> expected = {50, 10, 30, 20, 40};

    for (int &value : expected)
    {
        ASSERT_NE(curr, nullptr);
        EXPECT_EQ(curr->value, value);
        curr = curr->next;
    }

    EXPECT_EQ(curr, nullptr);
}
TEST(DoublyLinkedListTests, PopAtPositionCorrectly)
{
    DoublyLinkedList list;
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    list.removeAtPosition(1);
    DoublyLinkedList::Node *curr = list.getHead();
    std::vector<int> expected = {10, 30};

    for (int &value : expected)
    {
        ASSERT_NE(curr, nullptr) << "Unexpected nullptr while checking value " << value;
        EXPECT_EQ(curr->value, value) << "Mismatch at value: expected " << value;
        curr = curr->next;
    }

    EXPECT_EQ(curr, nullptr) << "List should end with nullptr";
}
TEST(DoublyLinkedListTests, ReverseEmpty)
{
    DoublyLinkedList list;
    DoublyLinkedList::Node *head = list.getHead();
    EXPECT_EQ(head, nullptr);
    list.reverse();
    EXPECT_EQ(head, nullptr);
}
TEST(DoublyLinkedListTests, ReverseOneElement)
{
    DoublyLinkedList list;
    list.pushBack(10);
    DoublyLinkedList::Node *head = list.getHead();
    ASSERT_NE(head, nullptr);
    EXPECT_EQ(head->value, 10);
    EXPECT_EQ(head->next, nullptr);
    EXPECT_EQ(head->prev, nullptr);
    list.reverse();
    EXPECT_EQ(head->value, 10);
    EXPECT_EQ(head->next, nullptr);
    EXPECT_EQ(head->prev, nullptr);
}
TEST(DoublyLinkedListTests, ReverseMultipleElements)
{
    DoublyLinkedList list;
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    list.reverse();
    DoublyLinkedList::Node *curr = list.getHead();
    std::vector<int> expected = {30, 20, 10};

    for (int &value : expected)
    {
        ASSERT_NE(curr, nullptr) << "Unexpected nullptr while checking value " << value;
        EXPECT_EQ(curr->value, value) << "Mismatch at value: expected " << value;
        curr = curr->next;
    }

    EXPECT_EQ(curr, nullptr) << "List should end with nullptr";
}
TEST(DoublyLinkedListTests, DoubleReverseMultipleElements)
{
    DoublyLinkedList list;
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    list.reverse();
    list.reverse();
    DoublyLinkedList::Node *curr = list.getHead();
    std::vector<int> expected = {10, 20, 30};

    for (int &value : expected)
    {
        ASSERT_NE(curr, nullptr) << "Unexpected nullptr while checking value " << value;
        EXPECT_EQ(curr->value, value) << "Mismatch at value: expected " << value;
        curr = curr->next;
    }

    EXPECT_EQ(curr, nullptr) << "List should end with nullptr";
}
TEST(DoublyLinkedListTests, Find)
{
    DoublyLinkedList list;
    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);

    DoublyLinkedList::Node *res1 = list.find(20);
    DoublyLinkedList::Node *res2 = list.find(30);
    DoublyLinkedList::Node *res3 = list.find(10);

    const std::vector<DoublyLinkedList::Node *> found = {res1, res2, res3};
    const std::vector<int> value = {20, 30, 10};

    for (std::size_t i = 0; i < found.size(); ++i)
    {
        ASSERT_NE(found[i], nullptr) << "Unexpected nullptr while checking value " << value[i];
        EXPECT_EQ(found[i]->value, value[i]) << "Mismatch at value: expected " << value[i];
    }

    DoublyLinkedList::Node *unknown = list.find(1337);
    ASSERT_EQ(unknown, nullptr) << "Unknown should point at nullptr";
}
