#include "Time.h"

Time::Time(const std::string& time)
{
    std::stringstream stri(time);
    char razd;
    stri >> minutes >> razd >> seconds;
}
