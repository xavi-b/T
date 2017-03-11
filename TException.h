#ifndef TEXCEPTION_H
#define TEXCEPTION_H

#include <iostream>

enum TExceptionType
{
    OutOfBoundary
};

class TException
{
protected:
    TExceptionType _type;

public:
    TException(TExceptionType type=TExceptionType::OutOfBoundary);
};

std::ostream& operator<<(std::ostream& os, const TException& e);

#endif // TEXCEPTION_H
