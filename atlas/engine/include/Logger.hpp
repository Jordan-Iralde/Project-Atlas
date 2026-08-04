#include <iostream>

class Logger
{
public:

    static void Info(const std::string&);
    static void Warning(const std::string&);
    static void Error(const std::string&);
};