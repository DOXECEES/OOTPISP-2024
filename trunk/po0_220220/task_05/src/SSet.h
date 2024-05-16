#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <stack>

template <typename T>
class SSet
{

public:
    SSet() = default;
    ~SSet() = default;

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

    void PushMaxToBegin();
    void DeleteMin();
    void AddAverageValueToStack();

    friend std::ostream &operator<< <T>(std::ostream &out, const SSet<T> &a);
    friend std::istream &operator>> <T>(std::istream &in, SSet<T> &a);

private:
    std::stack<T> tempStack;
    std::stack<T> stack;
};

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
    std::stack<T> _tempStack;

    while (!stack.empty())
    {
        if (!maxElement || stack.top() > *maxElement)
        {
            maxElement = stack.top();
        }
        _tempStack.push(stack.top());
        stack.pop();
    }

    if (maxElement)
    {
        stack.push(*maxElement);
    }

    while (!_tempStack.empty())
    {
        stack.push(_tempStack.top());
        _tempStack.pop();
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
    std::stack<T> _tempStack;
    while (!stack.empty())
    {
        if (stack.top() < minElement)
        {
            minElement = stack.top();
        }
        _tempStack.push(stack.top());
        stack.pop();
    }

    bool removed = false;
    while (!_tempStack.empty())
    {
        if (_tempStack.top() == minElement && !removed)
        {
            removed = true;
        }
        else
        {
            stack.push(_tempStack.top());
        }
        _tempStack.pop();
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

    T average = sum / static_cast<T>(tempVec.size());

    for (auto &elem : tempVec)
    {
        elem = elem + average;
    }

    for (auto it = tempVec.rbegin(); it != tempVec.rend(); ++it)
    {
        stack.push(*it);
    }
}
