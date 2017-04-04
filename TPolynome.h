#ifndef TPOLYNOME_H
#define TPOLYNOME_H

#include <iostream>
#include <typeinfo>
#include "TPoint.h"

template<size_t N, typename T>
class TPolynome
{
protected:
    T _coeffs[N+1];

public:
    TPolynome(const T& c=0)
    {
        for(size_t i=0; i<N+1; i++)
            _coeffs[i] = c;
    }

    TPolynome(const T (&coeffs)[N])
    {
        for(size_t i=0; i<N+1; i++)
            _coeffs[i] = coeffs[i];
    }

    TPolynome(const TPolynome<N-1, T>& p)
    {
        for(size_t i=0; i<N; i++)
            _coeffs[i] = p(i);

        _coeffs[N] = 0;
    }

    TPolynome operator*(const T& k) const
    {
        return TPolynome(*this)*=k;
    }

    TPolynome& operator*=(const T& k)
    {
        for(size_t i=0; i<N+1; i++)
            _coeffs[i] *= k;

        return *this;
    }

    TPolynome operator+(const T& k) const
    {
        return TPolynome(*this)+=k;
    }

    TPolynome& operator+=(const T& k)
    {
        for(size_t i=0; i<N+1; i++)
            _coeffs[i] += k;

        return *this;
    }

    TPolynome operator-(const T& k) const
    {
        return TPolynome(*this)-=k;
    }

    TPolynome& operator-=(const T& k)
    {
        for(size_t i=0; i<N+1; i++)
            _coeffs[i] -= k;

        return *this;
    }

    TPolynome operator-() const
    {
        return TPolynome(*this)*=-1;
    }

    TPolynome operator+() const
    {
        return TPolynome(*this);
    }

    const T& operator[](size_t x) const throw(TException)
    {
        if(x>=N+1)
            throw(TException(std::to_string(x) + ">=" + std::to_string(N+1) + "!", TExceptionType::OutOfBoundary));

        return _coeffs[x];
    }

    T& operator[](size_t x) throw(TException)
    {
        if(x>=N+1)
            throw(TException(std::to_string(x) + ">=" + std::to_string(N+1) + "!", TExceptionType::OutOfBoundary));

        return _coeffs[x];
    }

    bool operator==(const TPolynome& t) const
    {
        for(size_t i=0; i<N+1; i++)
            if(_coeffs[i] != t._coeffs[i])
                return false;

        return true;
    }

    bool operator!=(const TPolynome& t) const
    {
        return !(*this == t);
    }

    TPolynome operator+(const TPolynome& p) const
    {
        return TPolynome(*this)+=p;
    }

    TPolynome& operator+=(const TPolynome& p)
    {
        for(size_t i=0; i<N+1; i++)
            _coeffs[i] += p._coeffs[i];

        return *this;
    }

    TPolynome operator-(const TPolynome& p) const
    {
        return TPolynome(*this)-=p;
    }

    TPolynome& operator-=(const TPolynome& p)
    {
        for(size_t i=0; i<N+1; i++)
            _coeffs[i] -= p._coeffs[i];

        return *this;
    }

    template<size_t M>
    TPolynome<M+N, T> operator*(const TPolynome<M, T>& p) const
    {
        TPolynome<M+N, T> rt;

        for(size_t i=0; i<N+1; i++)
            for(size_t j=0; j<M+1; j++)
                rt[i+j] += _coeffs[i]*p[i];

        return rt;
    }

    TPolynome operator+(const TPolynome<N-1, T>& p) const
    {
        return TPolynome(*this)+=p;
    }

    TPolynome& operator+=(const TPolynome<N-1, T>& p)
    {
        for(size_t i=0; i<N; i++)
            _coeffs[i] += p(i);

        return *this;
    }

    TPolynome operator-(const TPolynome<N-1, T>& p) const
    {
        return TPolynome(*this)-=p;
    }

    TPolynome& operator-=(const TPolynome<N-1, T>& p)
    {
        for(size_t i=0; i<N; i++)
            _coeffs[i] -= p(i);

        return *this;
    }

    TPolynome<N+1, T> operator+(const TPolynome<N+1, T>& p) const
    {
        TPolynome<N+1, T> rt(*this);

        for(size_t i=0; i<N+2; i++)
            rt(i) += p(i);
    }

    TPolynome<N+1, T> operator-(const TPolynome<N+1, T>& p) const
    {
        TPolynome<N+1, T> rt(*this);

        for(size_t i=0; i<N+2; i++)
            rt(i) -= p(i);
    }

    operator TPolynome<N+1, T>() const
    {
        return TPolynome<N+1, T> rt(*this);
    }

    T operator()(T x) const
    {
        T r = _coeffs[0];
        T a;

        for(size_t i=1; i<N+1; i++)
        {
            a = x;
            for(size_t j=1; j<i; j++)
                a *= x;
            r += a;
        }

        return r;
    }
};

template<size_t N, typename T>
std::ostream& operator<<(std::ostream& os, const TPolynome<N, T>& t)
{
    os << "TPolynome " << (N+1) << " " << typeid(T).name() << " degree(s)" << std::endl;

    os << "{ ";
    for(size_t i=0; i<N+1; i++)
        os << t(i) << std::endl;
    os << " }" << std::endl;

    return os;
}

#endif // TPOLYNOME_H
