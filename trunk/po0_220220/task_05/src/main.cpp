#include <iostream>
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
	std::vector<float> vectorOfFloats = {1.0f, 2.0f, 4.0f, 3.3f};

	PushMaxToBegin(vectorOfFloats);
	DeleteMin(vectorOfFloats);
	AddAverageValueToVector(vectorOfFloats);

	for (const auto &i : vectorOfFloats)
	{
		std::cout << i << " ";
	}

	// -----------------------------------------------//

	// TASK 2 //
	// -----------------------------------------------//
	std::vector<Cash> vectorOfCash = {Cash(1.66), Cash(4.51), Cash(0.4), Cash(6.53)};

	PushMaxToBegin(vectorOfCash);
	DeleteMin(vectorOfCash);
	AddAverageValueToVector(vectorOfCash);

	for (const auto &i : vectorOfCash)
	{
		std::cout << i << " ";
	}

	// -----------------------------------------------//

	// TASK 3 //
	// -----------------------------------------------//

	Multitude<double> setOfDouble;
	setOfDouble.Insert(1.9f);
	setOfDouble.Insert(1.333f);
	setOfDouble.Insert(2.53f);
	setOfDouble.Insert(0.4f);
	setOfDouble.Insert(5.42f);

	setOfDouble.PushMaxToBegin();
	setOfDouble.DeleteMin();
	setOfDouble.AddAverageValueToVector();

	setOfDouble.Show();

	// -----------------------------------------------//

	// TASK 4 //
	// -----------------------------------------------//

	std::stack<Cash> somePieceOfStack;

	somePieceOfStack.push(Cash(1.66));
	somePieceOfStack.push(Cash(4.51));
	somePieceOfStack.push(Cash(0.4));
	somePieceOfStack.push(Cash(6.53));

	PushMaxToBeginStack(somePieceOfStack);
	DeleteMinStack(somePieceOfStack);
	AddAverageValueToStack(somePieceOfStack);

	while (!somePieceOfStack.empty())
	{
		std::cout << somePieceOfStack.top() << " ";
		somePieceOfStack.pop();
	}

	// -----------------------------------------------//

	// TASK 5 //
	// -----------------------------------------------//

	SSet<float> ssetOfFloats;
	ssetOfFloats.Add(1.9f);
	ssetOfFloats.Add(1.333f);
	ssetOfFloats.Add(2.53f);
	ssetOfFloats.Add(11.0f);
	ssetOfFloats.Add(11.0f);

	ssetOfFloats.PushMaxToBegin();
	ssetOfFloats.DeleteMin();
	ssetOfFloats.AddAverageValueToStack();

	ssetOfFloats.print();
}