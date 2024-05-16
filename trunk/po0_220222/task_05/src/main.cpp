#include <iostream>
#include <vector>
#include "Money.h"
#include "MyVector.h"
#include <queue>
#include "MyQVector.h"

template<class T>
void putMinToEnd(std::vector<T> &vec);
template<class T>
void findByKeyAndDelete(std::vector<T> &vec, T key);
template <class T>
void addAllMinMaxSum(std::vector<T> &vec);

template<class T>
void QputMinToEnd(std::queue<T> &q);
template<class T>
void QfindByKeyAndDelete(std::queue<T> &q, T key);
template <class T>
void QaddAllMinMaxSum(std::queue<T> &q);

int main()
{
	std::cout << "Task1" << std::endl;
	
	std::vector<float> vec;
	vec.push_back(float(1.50));
	vec.push_back(float(2.50));
	vec.push_back(float(1.30));
	vec.push_back(float(5.50));
	
	putMinToEnd(vec);
	findByKeyAndDelete(vec, float(1.50));
	addAllMinMaxSum(vec);
	for(auto elt : vec)
	{
		std::cout << elt << std::endl;
	}
	
	std::cout << "-----------------------------------" << std::endl;


	std::cout << "Task2" << std::endl;
	
	std::vector<Money> moneybagVec;
	moneybagVec.push_back(Money(1.50));
	moneybagVec.push_back(Money(1.20));
	moneybagVec.push_back(Money(1.10));
	moneybagVec.push_back(Money(2.50));
	moneybagVec.push_back(Money(2.00));

	putMinToEnd(moneybagVec);
	findByKeyAndDelete(moneybagVec, Money(1.50));
	addAllMinMaxSum(moneybagVec);
	for (auto elt1 : moneybagVec)
	{
		std::cout << elt1 << std::endl;
	}
	std::cout << "-----------------------------------" << std::endl;


	std::cout << "Task3" << std::endl;

	MyVector<Money> my_moneybagVec;   
	my_moneybagVec.Add(Money(1.50));
	my_moneybagVec.Add(Money(1.20));
	my_moneybagVec.Add(Money(1.30));
	my_moneybagVec.Add(Money(1.10));
	my_moneybagVec.Add(Money(2.50));

	my_moneybagVec.putMinToEnd();
	my_moneybagVec.findByKeyAndDelete(Money(1.20));
	my_moneybagVec.addAllMinMaxSum();
	my_moneybagVec.Print();

	std::cout << "-----------------------------------" << std::endl;


	std::cout << "Task4" << std::endl;

	std::queue<Money> q;
	q.push(Money(1.50));
	q.push(Money(1.20));
	q.push(Money(1.10));
	q.push(Money(2.50));
	q.push(Money(2.00));

	QputMinToEnd(q);
	QfindByKeyAndDelete(q, Money(1.50));
	QaddAllMinMaxSum(q);

	std::queue<Money> tmp_q = q;
	for (int i = 0; i < q.size(); i++)
	{
		std::cout << tmp_q.front() << std::endl;
		tmp_q.pop();
	}

	std::cout << "-----------------------------------" << std::endl;

	std::cout << "Task5" << std::endl;

	MyQVector<Money> qvec;
	qvec.Add(Money(1.50));
	qvec.Add(Money(1.20));
	qvec.Add(Money(1.30));
	qvec.Add(Money(1.10));
	qvec.Add(Money(2.50));

	qvec.putMinToEnd();
	qvec.findByKeyAndDelete(Money(1.50));
	qvec.addAllMinMaxSum();
	qvec.Print();

	std::cout << "-----------------------------------" << std::endl;

}

template <class T>
void putMinToEnd(std::vector<T> &vec)
{
	int index = 0;
	T tmp = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] < tmp)
		{
			index = i;
			tmp = vec[i];
		}
	}

	vec.erase(vec.begin()+index);

	vec.push_back(tmp);
}

template <class T>
void findByKeyAndDelete(std::vector<T> &vec, T key)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == key)
		{
			vec.erase(vec.begin()+i);
			break;
		}
	}

}

template <class T>
void addAllMinMaxSum(std::vector<T> &vec)
{
	T min = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] < min)
		{
			min = vec[i];
		}
	}

	T max = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] > max)
		{
			max = vec[i];
		}
	}

	T sum = min + max;
	auto len = static_cast<int>(vec.size());

	for (int i = 0; i < len; i++)
	{
		vec[i] = vec[i]+sum;
	}
}

template<class T>
void QputMinToEnd(std::queue<T> &q)
{
	int index = 0;
	std::queue<T> tmp_q = q;
	T tmp = tmp_q.front(); tmp_q.pop();
	for (int i = 1; i < q.size(); i++)
	{
		T tmp1 = tmp_q.front(); tmp_q.pop();
		if (tmp1 < tmp)
		{
			index = i;
			tmp = tmp1;
		}
	}
	auto len = static_cast<int>(q.size());
	tmp_q = q;
	for (int i = 0; i < len; i++)
	{
		q.pop();
		if (i != index)
		{
			q.push(tmp_q.front());
		}
		tmp_q.pop();
	}
	q.push(tmp);
}

template<class T>
void QfindByKeyAndDelete(std::queue<T> &q, T key)
{
	int index = 0;
	std::queue<T> tmp_q = q;
	for (int i = 0; i < q.size(); i++)
	{
		if (tmp_q.front() == key)
		{
			index = i;
		}
		tmp_q.pop();
	}
	auto len = static_cast<int>(q.size());
	tmp_q = q;
	for (int i = 0; i < len; i++)
	{
		q.pop();
		if (i != index)
		{
			q.push(tmp_q.front());
			tmp_q.pop();
		}
	}
}

template<class T>
void QaddAllMinMaxSum(std::queue<T> &q)
{
	std::queue<T> tmp_q = q;
	T min = tmp_q.front(); tmp_q.pop();
	for (int i = 1; i < q.size(); i++)
	{
		T tmp1 = tmp_q.front(); tmp_q.pop();
			if (tmp1 < min)
			{
				min = tmp1;
			}
	}

	tmp_q = q;
	T max = tmp_q.front(); tmp_q.pop();
	for (int i = 1; i < q.size(); i++)
	{
		T tmp1 = tmp_q.front(); tmp_q.pop();
			if (tmp1 > max)
			{
				max = tmp1;
			}
	}

	T sum = min + max;
	auto len = static_cast<int>(q.size());
	tmp_q = q;
	for (int i = 0; i < len; i++)
	{
		q.pop();
		q.push(tmp_q.front()+sum);
		tmp_q.pop();
	}

}
