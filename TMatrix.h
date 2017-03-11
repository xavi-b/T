#ifndef TMATRIX_H
#define TMATRIX_H

#include <iostream>
#include "TVector.h"

template<size_t N, typename T=int>
class TMatrix
{
protected:
    T _m[N][N];
public:
    TMatrix();
    TMatrix(T m[N][N]);

    T Det() const;

    const TMatrix operator+(const TMatrix& t) const;
    TMatrix& operator+=(const TMatrix& t);

    const TMatrix operator-(const TMatrix& t) const;
    TMatrix& operator-=(const TMatrix& t);

    const TMatrix operator*(const TMatrix& t) const;
    TMatrix& operator*=(const TMatrix& t);

    const TMatrix operator~() const;

    const TMatrix operator!() const;

    const TVector<N, T> operator*(const TVector<N, T>& t) const;

    const T& operator()(size_t x, size_t y) const;
    T& operator()(size_t x, size_t y);
};

template<size_t N, typename T>
std::ostream& operator<<(std::ostream& os, const TMatrix<N, T>& t);

#endif // TMATRIX_H
