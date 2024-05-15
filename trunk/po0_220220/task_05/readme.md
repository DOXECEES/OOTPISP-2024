
# Лабораторная работа №5 #

## Последовательные контейнеры библиотеки STL ##

## Вариант 6 ##
 

## Цель работы ##
Создание консольного приложения, состоящего из нескольких файлов в системе  программирования Visual Studio. Использование последовательных контейнеров библиотеки STL в ОО  программе. 

### Задания для первой и второй, третьей задачи ###
```c++
template <class T>
void PushMaxToBegin(std::vector<T> &vec)
{
	auto max = std::max_element(vec.begin(), vec.end());
	vec.insert(vec.begin(), *max);
}

template <class T>
void DeleteMin(std::vector<T> &vec)
{
	auto min = std::min_element(vec.begin(), vec.end());
	vec.erase(min);
}

template <class T>
void AddAverageValueToVector(std::vector<T> &vec)
{
	auto average = std::accumulate(vec.begin(), vec.end(), T());
	average = average / vec.size();
	std::for_each(vec.begin(), vec.end(), [average](auto &i)
				  { i = i + average; });
}
```

### Задания для четвертой задачи ###

```c++
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

	T average = sum / tempVec.size();

	for (auto &elem : tempVec)
	{
		elem = elem + average;
	}

	for (auto it = tempVec.rbegin(); it != tempVec.rend(); ++it)
	{
		stack.push(*it);
	}
}
```

### Класс множество с адаптером стек ###

```c++
		void Add(const T &element)
		{
			if (!Contains(element))
			{
				stack.push(element);
			}
		}

		void Remove(const T &element)
		{
			std::vector<T> elements;
			tempStack = stack;
			while (!tempStack.empty())
			{
				elements.push_back(tempStack.top());
				tempStack.pop();
			}

			for (int i = 0; i < elements.size(); ++i)
			{
				if (elements[i] == element)
				{
					elements.erase(elements.begin() + i);
					break;
				}
			}

			while (!elements.empty())
			{
				tempStack.push(elements.back());
				elements.pop_back();
			}
			stack = tempStack;
		}

		bool Contains(const T &element)
		{
			std::vector<T> elements;
			tempStack = stack;
			while (!tempStack.empty())
			{
				elements.push_back(tempStack.top());
				tempStack.pop();
			}

			for (int i = 0; i < elements.size(); ++i)
			{
				if (elements[i] == element)
				{
					return true;
				}
			}
			return false;
		}

		int Size() const
		{
			return stack.size();
		}

		void print()
		{
			std::vector<T> elements;
			tempStack = stack;
			while (!tempStack.empty())
			{
				elements.push_back(tempStack.top());
				tempStack.pop();
			}

			std::cout << "{ ";
			for (int i = 0; i < elements.size(); ++i)
			{
				std::cout << elements[i] << " ";
			}
			std::cout << "}" << std::endl;
		}

		int operator()() const
		{
			return Size();
		};

		T operator[](const int index) const
		{
			std::vector<T> elements;
			tempStack = stack;
			while (!tempStack.empty())
			{
				elements.push_back(tempStack.top());
				tempStack.pop();
			}

			return elements[index];
		}

	template <class T>
	std::ostream &operator<<(std::ostream &out, const SSet<T> &a)
	{
		a.print();
		return out;
	}

	template <class T>
	std::istream &operator>>(std::istream &in, SSet<T> &a)
	{
		for (int i = 0; i < a(); i++)
		{
			T temp;
			in >> temp;
			a.Add(temp);
		}
		return in;
	}

	template <class T>
	void SSet<T>::PushMaxToBegin()
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
	void SSet<T>::DeleteMin()
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
	void SSet<T>::AddAverageValueToStack()
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

		T average = sum / tempVec.size();

		for (auto &elem : tempVec)
		{
			elem = elem + average;
		}

		for (auto it = tempVec.rbegin(); it != tempVec.rend(); ++it)
		{
			stack.push(*it);
		}
	}

```
