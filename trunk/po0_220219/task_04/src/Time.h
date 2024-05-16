#pragma once

#include <iostream>
#include <string>
#include <sstream>

class Time
{
public:
    Time() = default;
    explicit Time(const std::string& time);
    ~Time() = default;

    Time& operator=(const Time& t) = default;
    
    bool operator==(const Time& t) const = default;


    inline int GetMin() const { return minutes; };
    inline int GetSec() const { return seconds; };

    inline void SetMin(const int min) { minutes = min; };
    inline void SetSec(const int sec) { seconds = sec; };

    friend std::ostream& operator<<(std::ostream& out, const Time& a)
    {
        out << a.GetMin() << ":" << a.GetSec() << " ";
        return out;
    }

private:
    int minutes = 0;
    int seconds = 0;
};
