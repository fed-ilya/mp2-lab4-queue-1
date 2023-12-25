#include "gtest.h"
#include <iostream>
#include "..\queue-with-list\TLQueue.h"

TEST(TLQueue, can_create_queue)
{
	ASSERT_NO_THROW(TLQueue<int> q);
}

TEST(TLQueue, new_created_queue_is_empty)
{
	TLQueue<int> q;
	ASSERT_TRUE(q.IsEmpty());
}

TEST(TLQueue, not_empty_queue_is_not_empty)
{
	TLQueue<int> q;
	q.Push(1); q.Push(2);

	ASSERT_FALSE(q.IsEmpty());
}

TEST(TLQueue, can_create_copied_queue)
{
	TLQueue<int> q;
	ASSERT_NO_THROW(TLQueue<int> copy = q);
}

TEST(TLQueue, copied_queue_is_equal_to_source_one)
{
	int size = 5;

	TLQueue<int> q;
	for (int i = 0; i < size; i++)
		q.Push(i + 1);

	TLQueue<int> copy = q;

	EXPECT_EQ(copy, q);
}

TEST(TLQueue, copied_queue_has_its_own_memory)
{
	int size = 5;

	TLQueue<int> q;
	for (int i = 0; i < size; i++)
		q.Push(i + 1);

	TLQueue<int> copy = q;
	copy.Clear();
	for (int i = 0; i < size; i++)
		copy.Push(i + 2);

	for (int i = 0; i < size; i++)
		EXPECT_NE(q.Pop(), copy.Pop());
}

TEST(TLQueue, can_assign_queues)
{
	TLQueue<int> q1;
	for (int i = 0; i < 5; i++)
		q1.Push(i + 1);

	TLQueue<int> q2;

	ASSERT_NO_THROW(q2 = q1);
	EXPECT_EQ(q2, q1);
}

TEST(TLQueue, can_assign_queue_to_itself)
{
	TLQueue<int> q;
	for (int i = 0; i < 10; i++)
		q.Push(i + 1);

	q = q;

	EXPECT_EQ(q, q);
}

TEST(TLQueue, equal_queues_comparison_returns_true)
{
	TLQueue<int> q1;
	for (int i = 0; i < 10; i++)
		q1.Push(i + 1);

	TLQueue<int> q2;
	for (int i = 0; i < 10; i++)
		q2.Push(i + 1);

	EXPECT_EQ(q1, q2);
}

TEST(TLQueue, unequal_queues_comparison_returns_false)
{
	TLQueue<int> q1;
	for (int i = 0; i < 10; i++)
		q1.Push(i + 1);

	TLQueue<int> q2;
	for (int i = 0; i < 12; i++)
		q2.Push(i + 2);

	EXPECT_NE(q1, q2);
}

TEST(TLQueue, can_push_and_pop_single)
{
	TLQueue<double> q;
	double number = 1.23;
	double popped;

	ASSERT_NO_THROW(q.Push(number));
	ASSERT_NO_THROW(popped = q.Pop());
	EXPECT_EQ(popped, number);
}

TEST(TLQueue, cant_pop_from_an_empty_queue)
{
	TLQueue<int> q;
	ASSERT_ANY_THROW(q.Pop());
}

TEST(TLQueue, can_clear_queue)
{
	TLQueue<int> q;
	for (int i = 0; i < 10; i++)
		q.Push(1);

	ASSERT_NO_THROW(q.Clear());
}

TEST(TLQueue, cleared_queue_is_empty)
{
	TLQueue<int> q;
	for (int i = 0; i < 10; i++)
		q.Push(1);

	q.Clear();
	ASSERT_TRUE(q.IsEmpty());
}