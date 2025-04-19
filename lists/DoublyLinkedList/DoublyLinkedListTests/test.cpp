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
