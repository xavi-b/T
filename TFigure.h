#ifndef TFIGURE_H
#define TFIGURE_H

#include <iostream>
#include <typeinfo>
#include "TPoint.h"

template<size_t N, typename T>
class TFigure
{
protected:
    TPoint<T> _pts[N];

public:
    TFigure(const TPoint (&pts)[N])
    {
        for(size_t i=0; i<N; i++)
            _pts[i] = pts[i];
    }

    TFigure operator*(const T& k) const
    {
        return TFigure(*this)*=k;
    }

    TFigure& operator*=(const T& k)
    {
        for(size_t i=0; i<N; i++)
            _pts[i] *= k;

        return *this;
    }

    const TPoint& operator()(size_t x) const throw(TException)
    {
        if(x>=N)
            throw(TException(std::to_string(x) + ">=" + std::to_string(N) + "!", TExceptionType::OutOfBoundary));

        return _coords[x];
    }

    TPoint& operator()(size_t x) throw(TException)
    {
        if(x>=N)
            throw(TException(std::to_string(x) + ">=" + std::to_string(N) + "!", TExceptionType::OutOfBoundary));

        return _coords[x];
    }

    bool operator==(const TFigure& t) const
    {
        for(size_t i=0; i<N; i++)
            if(_pts[i] != t._pts[i])
                return false;

        return true;
    }

    bool operator!=(const TFigure& t) const
    {
        return !(*this == t);
    }

    T Perimeter() const
    {
        T d = 0;

        for(size_t i=0; i<N; i++)
            d += _pts[i].Distance();

        return d;
    }
};

template<size_t N, typename T>
std::ostream& operator<<(std::ostream& os, const TFigure<N, T>& t)
{
    os << "TFigure " << N << " " << typeid(T).name() << " points" << std::endl;

    os << "{ ";
    for(size_t i=0; i<N; i++)
        os << t(i) << std::endl;
    os << " }" << std::endl;

    return os;
}

#endif // TFIGURE_H
