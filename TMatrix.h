#ifndef TMATRIX_H
#define TMATRIX_H

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include "TException.h"

template<size_t N, size_t P, typename T=int>
class TMatrix
{
protected:
    T _m[N][P];

public:   
    TMatrix()
    {
        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<P; j++)
                _m[i][j] = 0;
    }

    TMatrix(T m[N][P])
    {
        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<P; j++)
                _m[i][j] = m[i][j];
    }

    T* M() const
    {
        return _m;
    }

    size_t Height() const
    {
        return N;
    }

    size_t Width() const
    {
        return P;
    }

    T Det() const throw(TException)
    {
        if(N!=P)
            throw(TException("Matrix " + std::to_string(N) + "x" + std::to_string(P) + " is not a square matrix!", TExceptionType::NotInvertible));

        if(N<2)
            return N;

        if(N==2)
            return _m[0][0]*_m[1][1]-_m[0][1]*_m[1][0];

        T det = 0;

        if(N==3)
        {
            for(size_t i=0; i<N; i++)
            {
                T a = 1, b = 1;

                for(size_t j=0; j<N; j++)
                {
                    a *= _m[j][(i+j)%N];
                    b *= _m[(N-1)-j][(i+j)%N];
                }

                det += a - b;
            }
        }
        else
        {
            // TODO
        }

        return det;
    }

    const TMatrix operator+(const TMatrix& t) const
    {
        return TMatrix(*this) += t;
    }

    TMatrix& operator+=(const TMatrix& t)
    {
        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<P; j++)
                _m[i][j] += t._m[i][j];
    }

    const TMatrix operator-(const TMatrix& t) const
    {
        return TMatrix(*this) -= t;
    }

    TMatrix& operator-=(const TMatrix& t)
    {
        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<P; j++)
                _m[i][j] -= t._m[i][j];
    }

    template<size_t R>
    const TMatrix<N, R, T> operator*(const TMatrix<P, R, T> & t) const
    {
        TMatrix<N, R, T> rt;
        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<R; j++)
                for(size_t k=0; k<P; k++)
                    rt(i, j) += _m[i][k]*t(k,j);
        return rt;
    }

    TMatrix& operator*=(const TMatrix<P, P, T>& t)
    {
        return ((*this) = (*this)*t);
    }

    const TMatrix<P, N, T> operator~() const
    {
        TMatrix<P, N, T> rt;

        for(size_t i=0; i<N; i++)
            for(size_t j=0; j<P; j++)
                rt(j,i) = _m[i][j];

        return rt;
    }

    const TMatrix operator!() const throw(TException)
    {
        size_t det = Det();

        TMatrix rt;

        // TODO

        return rt;
    }

    const T& operator()(size_t x, size_t y) const throw(TException)
    {
        if(x>=N)
            throw(TException(std::to_string(x) + ">=" + std::to_string(N) + "!", TExceptionType::OutOfBoundary));
        if(y>=P)
            throw(TException(std::to_string(y) + ">=" + std::to_string(P) + "!", TExceptionType::OutOfBoundary));

        return _m[x][y];
    }

    T& operator()(size_t x, size_t y) throw(TException)
    {
        if(x>=N)
            throw(TException(std::to_string(x) + ">=" + std::to_string(N) + "!", TExceptionType::OutOfBoundary));
        if(y>=P)
            throw(TException(std::to_string(y) + ">=" + std::to_string(P) + "!", TExceptionType::OutOfBoundary));

        return _m[x][y];
    }
};

template<size_t N, size_t P, typename T>
std::ostream& operator<<(std::ostream& os, const TMatrix<N, P, T>& t)
{
    os << "TMatrix " << N << "x" << P << " " << typeid(T).name() << std::endl;

    for(size_t i=0; i<N; i++)
    {
        os << "| ";

        for(size_t j=0; j<P; j++)
            os << "\t" << t(i,j);

        os << " |" << std::endl;
    }

    return os;
}

#endif // TMATRIX_H
