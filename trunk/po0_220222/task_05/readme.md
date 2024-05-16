# Лабораторная работа №5 #

## Последовательные контейнеры библиотеки STL ##

## Вариант 7 ##
 

## Цель работы ##
Изучение контейнеров стандартной библиотеки STL в C++. 

### Функции для решения задач 1 и 2 ###
#### Функции требуемые для решения обоих задач были объеденены в шаблон для предотвращения дубликации кода ####
```
c++
  template <class T>
void putMinToEnd(std::vector<T> &vec)
{
  int index = 0;
  T tmp = vec[0];
  for (int i = 1; i < vec.size(); i++)
  {
    if (_vec[i] < tmp)
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
  int index = 0;
  for (int i = 0; i < vec.size(); i++)
  {
    if (vec[i] == key)
    {
      index = i;
      vec.erase(vec.begin()+index);
      break;
    }
  }
  len--;
}

template <class T>
void addAllMinMaxSum(std::vector<T> &vec)
{
  int index = 0;
  T min = vec[0];
  for (int i = 1; i < vec.size(); i++)
  {
    if (vec[i] < min)
    {
      index = i;
      min = vec[i];
    }
  }

  int index1 = 0;
  T max = vec[0];
  for (int i = 1; i < vec.size(); i++)
  {
    if (vec[i] > max)
    {
      index1 = i;
      max = vec[i];
    }
  }

  T sum = min + max;

  for (int i = 0; i < vec.size(); i++)
  {
    vec[i] = vec[i]+sum;
  }
}
```
### Функции для решения задачи 3 ###
```
c++
template<class T>
inline void MyVector<T>::putMinToEnd()
{
  int index = 0;
  T tmp = _vec[0];
  for (int i = 1; i < _vec.size(); i++)
  {
    if (vec[i] < tmp)
    {
      index = i;
      tmp = _vec[i];
    }
  }

  _vec.erase(_vec.begin() + index);

  _vec.push_back(tmp);
}

template<class T>
inline void MyVector<T>::findByKeyAndDelete(T key)
{
  int index = 0;
  for (int i = 0; i < _vec.size(); i++)
  {
    if (_vec[i] == key)
    {
      index = i;
      _vec.erase(_vec.begin() + index);
      break;
    }
  }
}

template<class T>
inline void MyVector<T>::addAllMinMaxSum()
{
  int index = 0;
  T min = _vec[0];
  for (int i = 1; i < _vec.size(); i++)
  {
    if (_vec[i] < min)
    {
      index = i;
      min = _vec[i];
    }
  }

  int index1 = 0;
  T max = _vec[0];
  for (int i = 1; i < _vec.size(); i++)
  {
    if (_vec[i] > max)
    {
      index1 = i;
      max = _vec[i];
    }
  }

  T sum = min + max;

  for (int i = 0; i < _vec.size(); i++)
  {
    _vec[i] = _vec[i] + sum;
  }
}
```
### Функции для решения задачи 4 ###
```
c++
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
  int len = q.size();
  tmp_q = q;
  for (int i = 0; i < len; i++)
  {
    q.pop();
    if(i!= index)
    q.push(tmp_q.front());
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
  int len = q.size();
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
  int len = q.size();
  tmp_q = q;
  for (int i = 0; i < len; i++)
  {
    q.pop();
    q.push(tmp_q.front()+sum);
    tmp_q.pop();
  }

}
```
### Функции для решения задачи 5 ###

```
c++
template<class T>
inline void MyQVector<T>::putMinToEnd()
{
  int index = 0;
  std::queue<T> tmp_q = _q;
  T tmp = tmp_q.front(); tmp_q.pop();
  for (int i = 1; i < _q.size(); i++)
  {
    T tmp1 = tmp_q.front(); tmp_q.pop();
      if (tmp1 < tmp)
      {
        index = i;
        tmp = tmp1;
      }
  }
  int len = _q.size();
  tmp_q = _q;
  for (int i = 0; i < len; i++)
  {
    _q.pop();
    if (i != index)
      _q.push(tmp_q.front());
    tmp_q.pop();
  }
  _q.push(tmp);
}

template<class T>
inline void MyQVector<T>::findByKeyAndDelete(T key)
{
  int index = 0;
  std::queue<T> tmp_q = _q;
  for (int i = 0; i < _q.size(); i++)
  {
    if (tmp_q.front() == key)
    {
      index = i;
    }
    tmp_q.pop();
  }
  int len = _q.size();
  tmp_q = _q;
  for (int i = 0; i < len; i++)
  {
    _q.pop();
    if (i != index)
    {
      _q.push(tmp_q.front());
      tmp_q.pop();
    }
  }
}

template<class T>
inline void MyQVector<T>::addAllMinMaxSum()
{
  std::queue<T> tmp_q = _q;
  T min = tmp_q.front(); tmp_q.pop();
  for (int i = 1; i < _q.size(); i++)
  {
    T tmp1 = tmp_q.front(); tmp_q.pop();
    if (tmp1 < min)
    {
      min = tmp1;
    }
  }

  tmp_q = _q;
  T max = tmp_q.front(); tmp_q.pop();
  for (int i = 1; i < _q.size(); i++)
  {
    T tmp1 = tmp_q.front(); tmp_q.pop();
    if (tmp1 > max)
    {
      max = tmp1;
    }
  }

  T sum = min + max;
  int len = _q.size();
  tmp_q = _q;
  for (int i = 0; i < len; i++)
  {
    _q.pop();
    _q.push(tmp_q.front() + sum);
    tmp_q.pop();
  }

}
```

