#pragma once
#include "stdafx.h"
#include "Exercise.h"
#include <vector>

// (1) Linked List Reverse Printing Challenge
//
//Using whatever programming techniques you know, write the cleanest possible function you can think of to print a singly linked list in reverse.The format for the node should be a struct containing an integer value, val, and a next pointer to the following node.

// (2) Linked List In-Place Reverse Challenge
//
//This challenge, similar to the last linked list challenge, involves reversing a singly linked list--but this time, you must not out the list but actually reverse the entire list in place.By in - place, I mean that no memory can be allocated.The resulting code should be function that takes the head of a list and returns a the new head of the reversed list.
//http://www.cprogramming.com/challenge.html

struct ListNode
{
public:
	ListNode(int i_value) :
		m_next(NULL),
		m_value(i_value)
	{
	}

	int m_value;
	ListNode *m_next;
};

class SingleLinkedList
{
public:
	SingleLinkedList() : m_first(NULL), m_last(NULL) {}

	void addNode(ListNode *i_node);
	bool removeNode(ListNode *i_node);
	ListNode* getFirst() const { return m_first; }

	// O(n)
	int getSize() const;
	// O(n)
	ListNode* getPredecessor(const ListNode &i_node) const;
	std::vector<int> getValues() const;
	// O(n^2)
	std::vector<int> getReversedValues() const;
	// O(n)
	void getReversedValuesRecursion(std::vector<int> &o_reversedValues, ListNode *i_curr) const;
	void reverseListInPlace();

private:
	ListNode *m_first;
	ListNode *m_last;
};

class LinkedListReversalChallenge : Exercise
{
public:
	void mySolution();
};
