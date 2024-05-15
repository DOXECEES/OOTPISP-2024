#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <optional>

#include "Money.h"
#include "Set.h"
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
	average = average / static_cast<double>(vec.size());
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
	std::vector<Money> vm = {Money(1.66), Money(4.51), Money(0.4), Money(6.53)};

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

	Set<double> s;
	s.Add(1.9f);
	s.Add(1.333f);
	s.Add(2.53f);
	s.Add(0.4f);
	s.Add(5.42f);

	s.PushMaxToBegin();
	s.DeleteMin();
	s.AddAverageValueToVector();

	s.print();

	// -----------------------------------------------//

	// TASK 4 //
	// -----------------------------------------------//

	std::stack<Money> st;

	st.push(Money(1.66));
	st.push(Money(4.51));
	st.push(Money(0.4));
	st.push(Money(6.53));

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