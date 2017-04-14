#include <iostream>


using namespace std;

template<typename T>
double mean(T elements[], size_t count)
{
    T sum = T(); // calling the default constructor sum = 0
    for(size_t i = 0; i < count; ++i)
    {
        sum += elements[i];
    }
    return (double)(sum/(double)count);
}

template<typename T>
void doubleByRef(T& x)
{
    x +=x;
}




int main(void)
{
    int di = 5;
    double dd  = 5.0;
    int test_int[] = {3,4,5,6,5,2,3};
    float test_float[] = {13,44,35,6.7,5.33,2.77,3};
    std::cout << mean(test_int, 5) << endl;    
    std::cout << mean(test_float, 5) << endl;    
    doubleByRef(di);
    doubleByRef(dd);
    std::cout << di << endl;    
    std::cout << dd << endl;    
    return 0;
}
