#ifndef TMATRIX_H
#define TMATRIX_H

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "TVector.h"
#include "TException.h"

template<size_t N, typename T=int>
class TMatrix
{
protected:
    T _m[N][N];

public:   
    TMatrix()
    {
        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<N; j++)
                _m[i][j] = 0;
    }

    TMatrix(T m[N][N])
    {
        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<N; j++)
                _m[i][j] = m[i][j];
    }

    T Det() const
    {
        // TODO
    }

    const TMatrix operator+(const TMatrix& t) const
    {
        return TMatrix(*this) += t;
    }

    TMatrix& operator+=(const TMatrix& t)
    {
        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<N; j++)
                _m[i][j] += t._m[i][j];
    }

    const TMatrix operator-(const TMatrix& t) const
    {
        return TMatrix(*this) -= t;
    }

    TMatrix& operator-=(const TMatrix<N, T>& t)
    {
        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<N; j++)
                _m[i][j] -= t._m[i][j];
    }

    const TMatrix operator*(const TMatrix& t) const
    {
        return TMatrix(*this) *= t;
    }

    TMatrix& operator*=(const TMatrix& t)
    {
        TMatrix rt;
        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<N; j++)
                for(size_t k=0; k<N; k++)
                    rt._m[i][j] += _m[i][k]*t._m[k][j];
        return (*this) = rt;
    }

    const TMatrix operator~() const
    {
        TMatrix rt;

        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<N; j++)
                rt._m[i][j] = _m[j][i];

        return rt;
    }

    const TMatrix operator!() const
    {
        if(Det() == 0)
            return TMatrix(*this);

        TMatrix rt;

        // TODO

        return rt;
    }

    const TVectorC<N, T> operator*(const TVectorC<N, T>& t) const
    {
        TVector<N, T> rt;
        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<N; j++)
                rt._v[i] += t[i]*_m[i][j];
        return rt;
    }

    const T& operator()(size_t x, size_t y) const
    {
        if(x>=N || y>= N)
            throw(TException);

        return _m[x][y];
    }

    T& operator()(size_t x, size_t y)
    {
        if(x>=N || y>= N)
            throw(TException);

        return _m[x][y];
    }
};

template<size_t N, typename T>
std::ostream& operator<<(std::ostream& os, const TMatrix<N, T>& t)
{
    os << "TMatrix<" << N << ", " << typeid(T).name() << ">" << std::endl;

    for(size_t i=0; i<N; i++)
    {
        os << "| ";

        for(size_t j=0; j<N; j++)
            os << "\t" << t(i,j);

        os << " |" << std::endl;
    }

    return os;
}

template<size_t N, typename T>
const TVectorH<N, T> operator*(const TVectorH<N, T>& tv, const TMatrix<N, T>& tm)
{
    TVectorH<N, T> rt;
    for(size_t i=0; i<N; i++)
        for(size_t j=0; j<N; j++)
            rt._v[j] += tv[j]*tm(i,j);
    return rt;
}

#endif // TMATRIX_H
