#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
#include <typeinfo>
#include "TException.h"

template<size_t N, typename T=int>
class TVector
{
protected:
    T _v[N];

public:
    TVector()
    {
        for(size_t i=0; i<N; i++)
            _v[i] = 0;
    }

    TVector(T v[N])
    {
        for(size_t i=0; i<N; i++)
            _v[i] = v[i];
    }

    const TVector operator+(const TVector& t) const
    {
        return TVector(*this) += t;
    }

    TVector& operator+=(const TVector& t)
    {
        for(size_t i=0; i<N; i++)
            _v[i] += t._v[i];
    }

    const TVector operator-(const TVector& t) const
    {
        return TVector(*this) -= t;
    }

    TVector& operator-=(const TVector& t)
    {
        for(size_t i=0; i<N; i++)
            _v[i] -= t._v[i];
    }

    const T& operator()(size_t x) const throw(TException)
    {
        if(x>=N)
            throw(TException);

        return _v[x];
    }

    T& operator()(size_t x) throw(TException)
    {
        if(x>=N)
            throw(TException);

        return _v[x];
    }

    const T& operator[](size_t x) const throw(TException)
    {
        return this(x);
    }

    T& operator[](size_t x) throw(TException)
    {
        return this(x);
    }
};

template<size_t N, typename T>
std::ostream& operator<<(std::ostream& os, const TVector<N, T>& t);


template<size_t N, typename T=int>
class TVectorH : TVector<N, T>
{
public:
    TVectorH();
    TVectorH(T v[N]);
};

template<size_t N, typename T>
std::ostream& operator<<(std::ostream& os, const TVectorH<N, T>& t);


template<size_t N, typename T=int>
class TVectorC : TVector<N, T>
{
public:
    TVectorC();
    TVectorC(T v[N]);
};

template<size_t N, typename T>
std::ostream& operator<<(std::ostream& os, const TVectorC<N, T>& t);


template<size_t N, typename T>
const TVectorC<N, T> operator~(const TVectorH<N, T>& t);

template<size_t N, typename T>
const TVectorH<N, T> operator~(const TVectorC<N, T>& t);

#endif // TVECTOR_H
