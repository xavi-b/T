#include "TMatrix.h"

template<size_t N, typename T>
TMatrix<N, T>::TMatrix()
{
    for(size_t i=0; i<N; i++)
        for(size_t j=0; j<N; j++)
            _m[i][j] = 0;
}

template<size_t N, typename T>
TMatrix<N, T>::TMatrix(T m[N][N])
{
    for(size_t i=0; i<N; i++)
        for(size_t j=0; j<N; j++)
            _m[i][j] = m[i][j];
}

template<size_t N, typename T>
T TMatrix<N, T>::Det() const
{

}

template<size_t N, typename T>
const TMatrix<N, T> TMatrix<N, T>::operator+(const TMatrix<N, T>& t) const
{
    return TMatrix(*this) += t;
}

template<size_t N, typename T>
TMatrix<N, T>& TMatrix<N, T>::operator+=(const TMatrix<N, T>& t)
{
    for(size_t i=0; i<N; i++)
        for(size_t j=0; j<N; j++)
            _m[i][j] += t._m[i][j];
}

template<size_t N, typename T>
const TMatrix<N, T> TMatrix<N, T>::operator-(const TMatrix<N, T>& t) const
{
    return TMatrix(*this) -= t;
}

template<size_t N, typename T>
TMatrix<N, T>& TMatrix<N, T>::operator-=(const TMatrix<N, T>& t)
{
    for(size_t i=0; i<N; i++)
        for(size_t j=0; j<N; j++)
            _m[i][j] -= t._m[i][j];
}

template<size_t N, typename T>
const TMatrix<N, T> TMatrix<N, T>::operator*(const TMatrix<N, T>& t) const
{
    return TMatrix(*this) *= t;
}

template<size_t N, typename T>
TMatrix<N, T>& TMatrix<N, T>::operator*=(const TMatrix<N, T>& t)
{

}

template<size_t N, typename T>
const TMatrix<N, T> TMatrix<N, T>::operator~() const
{
    TMatrix rt;

    for(size_t i=0; i<N; i++)
        for(size_t j=0; j<N; j++)
            rt._m[i][j] = _m[j][i];

    return rt;
}

template<size_t N, typename T>
const TMatrix<N, T> TMatrix<N, T>::operator!() const
{

}

template<size_t N, typename T>
const TVector<N, T> TMatrix<N, T>::operator*(const TVector<N, T>& t) const
{

}

template<size_t N, typename T>
const T& TMatrix<N, T>::operator()(size_t x, size_t y) const
{

}

template<size_t N, typename T>
T& TMatrix<N, T>::operator()(size_t x, size_t y)
{

}

template<size_t N, typename T>
std::ostream& operator<<(std::ostream& os, const TMatrix<N, T>& t)
{

}
