#ifndef TEXCEPTION_H
#define TEXCEPTION_H

#include <iostream>
#include <typeinfo>

enum TExceptionType
{
    Unknown, OutOfBoundary, NotInvertible, ZeroDivision
};

class TException
{
protected:
    TExceptionType _type;
    std::string _msg;

public:
    TException(const std::string &msg="", TExceptionType type=TExceptionType::Unknown)
        : _type(type), _msg(msg)
    {

    }

    std::string GetMsg() const
    {
        return _msg;
    }

    TExceptionType GetType() const
    {
        return _type;
    }
};

std::ostream& operator<<(std::ostream& os, const TException& e)
{
    return os << e.GetMsg() << std::endl;
}

#endif // TEXCEPTION_H
