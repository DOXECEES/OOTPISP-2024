#include "Vector.h"
#include <iostream>
#include "Time.h"

int main()
{
    Vector<float> A;
    Vector<Time> B;
    Vector<float> C;

    A.Add(1.2f);
    A.Add(3.4f);
    A.Add(5.6f);

    B.Add(Time("10:41"));
    B.Add(Time("50:51"));
    B.Add(Time("12:50"));

    C.Add(5.0f);
    C.Add(3.0f);
    C.Add(7.0f);

    
    std::cout << "Container A: " << A << std::endl;
    std::cout << "Container B: " << B << std::endl;
    std::cout << "Container C: " << C << std::endl;

    auto minElem = A[0];
    for (int i = 1; i < A.Size(); ++i)
    {
        if (A[i] < minElem)
            minElem = A[i];
    }
    A.Add(minElem);

   
    auto sum = 0.0f;
    for (int i = 0; i < B.Size(); ++i)
    {
        sum += B[i].GetMin() ;
    }
    auto avg = sum / B.Size();

    for (int i = 0; i < B.Size(); ++i)
    {
        if (B[i].GetMin() > avg)
            B[i] = Time("00:00");
    }

   
    auto maxElem = C[0];
    for (int i = 1; i < C.Size(); ++i)
    {
        if (C[i] > maxElem)
            maxElem = C[i];
    }

    for (int i = 0; i < C.Size(); ++i)
    {
        C *= maxElem;

    }

    
    std::cout << "Task 3 result: " << A << std::endl;
    std::cout << "Task 4 result: " << B << std::endl;
    std::cout << "Task 5 result: " << C << std::endl;

    return 0;
}
