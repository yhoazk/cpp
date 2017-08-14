

#include "spline.h"
#include <iostream>
#include <vector>
/*
 * plot x^3 - 6x^2 + 4x + 12
 *
 * */

int main(void)
{


    std::vector<double> X(6), Y(6);
    X[0] = 1.0f;
    X[1] = 2.0f;
    X[2] = 3.0f;
    X[3] = 4.0f;
    X[4] = 5.0f;
    X[5] = 6.0f;

    Y[0] = 11.0f;
    Y[1] = 4.0f;
    Y[2] = -3.0f;
    Y[3] = -4.0f;
    Y[4] = 7.0f;
    Y[5] = 36.0f;

    tk::spline s;
    s.set_points(X,Y);    // currently it is required that X is already sorted
    
    double x=1.5;

    for(int i = 0; i < 20; ++i)
    {
        std::cout << i << ", " << s(i) << std::endl;
    }

    return 0;
}
