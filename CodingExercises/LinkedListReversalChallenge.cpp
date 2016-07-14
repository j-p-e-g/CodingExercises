#include "stdafx.h"
#include "LinkedListReversalChallenge.h"
#include <iostream>

void SingleLinkedList::addNode(ListNode *i_node)
{
	if (!m_first)
	{
		m_first = i_node;
	}
	else
	{
		ListNode *curr = m_first;
		while (curr->m_next)
		{
			curr = curr->m_next;
		}

		curr->m_next = i_node;
	}
	// always added at the end
	m_last = i_node;
}

bool SingleLinkedList::removeNode(ListNode *i_node)
{
	if (i_node)
	{
		if (m_first == i_node)
		{
			m_first = i_node->m_next;
			if (m_last == i_node)
			{
				m_last = NULL;
			}
			return true;
		}
		else
		{
			ListNode *curr = m_first;
			while (curr)
			{
				if (curr->m_next == i_node)
				{
					curr->m_next = i_node->m_next;
					if (m_last == i_node)
					{
						m_last = curr;
					}
					return true;
				}
				curr = curr->m_next;
			}
		}
	}
	return false;
}

int SingleLinkedList::getSize() const
{
	int count = 0;

	ListNode *curr = m_first;
	while (curr)
	{
		count++;
		curr = curr->m_next;
	}

	return count;
}

std::vector<int> SingleLinkedList::getValues() const
{
	std::vector<int> values;

	ListNode *curr = m_first;
	while (curr)
	{
		values.push_back(curr->m_value);
		curr = curr->m_next;
	}
	return values;
}

ListNode* SingleLinkedList::getPredecessor(const ListNode &i_node) const
{
	ListNode *curr = m_first;
	while (curr)
	{
		if (curr->m_next == &i_node)
		{
			return curr;
		}
		curr = curr->m_next;
	}

	return NULL;
}

std::vector<int> SingleLinkedList::getReversedValues() const
{
	std::vector<int> values;
	ListNode* curr = m_last;
	while (curr)
	{
		values.push_back(curr->m_value);
		curr = getPredecessor(*curr);
	}
	return values;
}

void SingleLinkedList::getReversedValuesRecursion(std::vector<int> &o_reversedValues, ListNode *i_curr) const
{
	if (i_curr)
	{
		getReversedValuesRecursion(o_reversedValues, i_curr->m_next);
		o_reversedValues.push_back(i_curr->m_value);
	}
}

void SingleLinkedList::reverseListInPlace()
{
	if (m_first) // list is non-empty
	{
		ListNode* startOfTheReversedList = m_first;
		ListNode* nextElement = startOfTheReversedList->m_next;

		// the current _first_ element becomes the new _last_ element
		m_last = m_first;
		m_last->m_next = NULL;

		ListNode* tempElementForNext;
		while (true)
		{
			if (nextElement)
			{
				// order is important her
				tempElementForNext = nextElement->m_next;
				nextElement->m_next = startOfTheReversedList;
				startOfTheReversedList = nextElement;
				nextElement = tempElementForNext;
			}
			else
			{
				// old _last_ element: set as the new _first_ element
				m_first = startOfTheReversedList;
				break;
			}
		}
	}
}

void LinkedListReversalChallenge::mySolution()
{
	SingleLinkedList* list = new SingleLinkedList();
	list->addNode(new ListNode(1));
	list->addNode(new ListNode(2));
	list->addNode(new ListNode(3));
	list->addNode(new ListNode(4));
	list->addNode(new ListNode(5));

	const std::vector<int> values = list->getValues();
	for (int k = (int) values.size() - 1; k >= 0; k--)
	{
		std::cout << values[k] << "  ";
	}
	std::cout << std::endl;

	const std::vector<int> reverseValues = list->getReversedValues();
	for (std::vector<int>::const_iterator it = reverseValues.begin(), end = reverseValues.end(); it != end; it++)
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl;

	std::vector<int> reverseValues2;
	list->getReversedValuesRecursion(reverseValues2, list->getFirst());
	for (std::vector<int>::const_iterator it = reverseValues.begin(), end = reverseValues.end(); it != end; it++)
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl;

	list->reverseListInPlace();
	std::vector<int> invertedListValues = list->getValues();
	for (std::vector<int>::const_iterator it = invertedListValues.begin(), end = invertedListValues.end(); it != end; it++)
	{
		std::cout << *it << "  ";
	}
	std::cout << std::endl;

	system("pause");
}
