#include "TMatrix.h"

int main()
{
    TMatrix<2, 3, int> m1;
    m1(0, 0) = 1;
    m1(0, 1) = 2;
    m1(0, 2) = 3;

    try
    {
        m1(0, 3) = 0;
    }
    catch(TException e)
    {
        std::cout << e;
    }

    m1(1, 0) = 4;
    m1(1, 1) = 5;
    m1(1, 2) = 6;
    std::cout << m1 << std::endl;
    std::cout << "Transposition" << std::endl << ~m1 << std::endl;

    TMatrix<3, 2, int> m2;
    m2(0, 0) = 1;
    m2(0, 1) = 2;
    m2(1, 0) = 3;
    m2(1, 1) = 1;
    m2(2, 0) = 2;
    m2(2, 1) = 3;
    std::cout << m2 << std::endl;

    std::cout << m1*m2 << std::endl;
    std::cout << m2*m1 << std::endl;

    TMatrix<3, 3, int> m3;
    m3(0, 0) = -2;
    m3(0, 1) = 2;
    m3(0, 2) = -3;
    m3(1, 0) = -1;
    m3(1, 1) = 1;
    m3(1, 2) = 3;
    m3(2, 0) = 2;
    m3(2, 1) = 0;
    m3(2, 2) = -1;
    std::cout << m3 << std::endl;
    std::cout << ~m3 << std::endl;
    std::cout << "Det " << m3.Det() << std::endl;

    TMatrix<2, 2, int> m4;
    m4(0, 0) = -2;
    m4(0, 1) = 2;
    m4(1, 0) = -3;
    m4(1, 1) = -1;
    std::cout << m4 << std::endl;
    std::cout << "Det " << m4.Det() << std::endl;

    return 1;
}
