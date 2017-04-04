#ifndef TPOINT_H
#define TPOINT_H

#include <iostream>
#include <typeinfo>
#include <math.h>

template<size_t N, typename T>
class TPoint
{
protected:
    T _coords[N];

public:
    TPoint(const T& c=0)
    {
        for(size_t i=0; i<N; i++)
            _coords[i] = c;
    }

    TPoint(const T (&coords)[N])
    {
        for(size_t i=0; i<N; i++)
            _coords[i] = coords[i];
    }

    TPoint operator*(const T& k) const
    {
        return TPoint(*this)*=k;
    }

    TPoint& operator*=(const T& k)
    {
        for(size_t i=0; i<N; i++)
            _coords[i] *= k;

        return *this;
    }

    TPoint operator+(const TPoint& p) const
    {
        return TPoint(*this)+=p;
    }

    TPoint& operator+=(const TPoint& p)
    {
        for(size_t i=0; i<N; i++)
            _coords[i] += p._coords[i];

        return *this;
    }

    TPoint operator-(const TPoint& p) const
    {
        return TPoint(*this)-=p;
    }

    TPoint& operator-=(const TPoint& p)
    {
        for(size_t i=0; i<N; i++)
            _coords[i] -= p._coords[i];

        return *this;
    }

    TPoint operator-() const
    {
        return TPoint(*this)*=-1;
    }

    TPoint operator+() const
    {
        return TPoint(*this);
    }

    const T& operator()(size_t x) const throw(TException)
    {
        if(x>=N)
            throw(TException(std::to_string(x) + ">=" + std::to_string(N) + "!", TExceptionType::OutOfBoundary));

        return _coords[x];
    }

    T& operator()(size_t x) throw(TException)
    {
        if(x>=N)
            throw(TException(std::to_string(x) + ">=" + std::to_string(N) + "!", TExceptionType::OutOfBoundary));

        return _coords[x];
    }

    bool operator==(const TPoint& t) const
    {
        for(size_t i=0; i<N; i++)
            if(_coords[i] != t._coords[i])
                return false;

        return true;
    }

    bool operator!=(const TPoint& t) const
    {
        return !(*this == t);
    }

    T SquareDistance() const
    {
        T d = 0;

        for(size_t i=0; i<N; i++)
            d += _coords[i]*_coords[i];

        return d;
    }

    T Distance() const
    {
        T d = 0;

        for(size_t i=0; i<N; i++)
            d += _coords[i]*_coords[i];

        return T(sqrt(double(d)));
    }
};

template<size_t N, typename T>
std::ostream& operator<<(std::ostream& os, const TPoint<N, T>& t)
{
    os << "{ ";
    for(size_t i=0; i<N; i++)
    {
        os << t(i);
	if(i != N-1)
	    os << ", ";
    }
    os << " }" << std::endl;

    return os;
}

#endif // TPOINT_H
