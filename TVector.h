#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>

template<size_t N, typename T=int>
class TVector
{
protected:
    T _v[N];

public:
    TVector();
};

#endif // TVECTOR_H
