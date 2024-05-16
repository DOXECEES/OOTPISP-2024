﻿#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <optional>

#include "Cash.h"
#include "Multitude.h"
#include "SSet.h"

template <class T>
void PushMaxToBegin(std::vector<T> &vec)
{
	auto max = std::ranges::max_element(vec);
	vec.insert(vec.begin(), *max);
}

template <class T>
void DeleteMin(std::vector<T> &vec)
{
	auto min = std::ranges::min_element(vec);
	vec.erase(min);
}

template <class T>
void AddAverageValueToVector(std::vector<T> &vec)
{
	auto average = std::accumulate(vec.begin(), vec.end(), T());
	average = average / static_cast<float>(vec.size());
	std::ranges::for_each(vec, [average](auto &i)
						  { i = i + average; });
}

template <class T>
void PushMaxToBeginStack(std::stack<T> &stack)
{
	std::optional<T> maxElement;
	std::stack<T> tempStack;

	while (!stack.empty())
	{
		if (!maxElement || stack.top() > *maxElement)
		{
			maxElement = stack.top();
		}
		tempStack.push(stack.top());
		stack.pop();
	}

	if (maxElement)
	{
		stack.push(*maxElement);
	}

	while (!tempStack.empty())
	{
		stack.push(tempStack.top());
		tempStack.pop();
	}
}

template <class T>
void DeleteMinStack(std::stack<T> &stack)
{
	if (stack.empty())
	{
		std::cerr << "Stack is empty." << std::endl;
		return;
	}

	T minElement = stack.top();
	std::stack<T> tempStack;
	while (!stack.empty())
	{
		if (stack.top() < minElement)
		{
			minElement = stack.top();
		}
		tempStack.push(stack.top());
		stack.pop();
	}

	bool removed = false;
	while (!tempStack.empty())
	{
		if (tempStack.top() == minElement && !removed)
		{
			removed = true;
		}
		else
		{
			stack.push(tempStack.top());
		}
		tempStack.pop();
	}
}

template <class T>
void AddAverageValueToStack(std::stack<T> &stack)
{
	if (stack.empty())
	{
		std::cerr << "Stack is empty." << std::endl;
		return;
	}

	std::vector<T> tempVec;
	while (!stack.empty())
	{
		tempVec.push_back(stack.top());
		stack.pop();
	}

	T sum = std::accumulate(tempVec.begin(), tempVec.end(), T());

	T average = sum / static_cast<double>(tempVec.size());

	for (auto &elem : tempVec)
	{
		elem = elem + average;
	}

	for (auto it = tempVec.rbegin(); it != tempVec.rend(); ++it)
	{
		stack.push(*it);
	}
}

int main()
{
	// TASK 1 //
	// -----------------------------------------------//
	std::vector<float> v = {1.0f, 2.0f, 4.0f, 3.3f};

	PushMaxToBegin(v);
	DeleteMin(v);
	AddAverageValueToVector(v);

	for (auto i : v)
	{
		std::cout << i << " ";
	}

	// -----------------------------------------------//

	// TASK 2 //
	// -----------------------------------------------//
	std::vector<Cash> vm = {Cash(1.66), Cash(4.51), Cash(0.4), Cash(6.53)};

	PushMaxToBegin(vm);
	DeleteMin(vm);
	AddAverageValueToVector(vm);

	for (auto i : vm)
	{
		std::cout << i << " ";
	}

	// -----------------------------------------------//

	// TASK 3 //
	// -----------------------------------------------//

	Multitude<double> s;
	s.Insert(1.9f);
	s.Insert(1.333f);
	s.Insert(2.53f);
	s.Insert(0.4f);
	s.Insert(5.42f);

	s.PushMaxToBegin();
	s.DeleteMin();
	s.AddAverageValueToVector();

	s.Show();

	// -----------------------------------------------//

	// TASK 4 //
	// -----------------------------------------------//

	std::stack<Cash> st;

	st.push(Cash(1.66));
	st.push(Cash(4.51));
	st.push(Cash(0.4));
	st.push(Cash(6.53));

	PushMaxToBeginStack(st);
	DeleteMinStack(st);
	AddAverageValueToStack(st);

	while (!st.empty())
	{
		std::cout << st.top() << " ";
		st.pop();
	}

	// -----------------------------------------------//

	// TASK 5 //
	// -----------------------------------------------//

	SSet<float> sa;
	sa.Add(1.9f);
	sa.Add(1.333f);
	sa.Add(2.53f);
	sa.Add(11.0f);
	sa.Add(11.0f);

	sa.PushMaxToBegin();
	sa.DeleteMin();
	sa.AddAverageValueToStack();

	sa.print();
}