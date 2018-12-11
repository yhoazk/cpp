/*************************************************************************/
/************  make_shared example****************************************/
/*************************************************************************/
/*
 * In header <memory>
 * Usage:
 *  shared_ptr<T> make_shared<T>(Args)
 * Constructs an object of type T and wraps it in a shated_ptr using Args
 * as the parameter list for the constructor of T.
 *
 * Returns a shared_ptr of an instance of type T
 *
 */
#include <iostream>
#include <memory>
using namespace std;

void foo(int* k)
{
    (*k)++;
}

void bar(const shared_ptr<int>& i)
{
    (*i)++;
}

int main()
{
    int n = 0;
    cout << n << "\n";
    foo(&n);
    cout << n << "\n";
    foo(&n);
    cout << n << "\n";
    foo(&n);
    cout << n << "\n";
    foo(&n);
    cout << n << "\n";
    foo(&n);
    /* Example for make shared */
    auto sp = make_shared<int>(12); // create a const shared pointer to a const integer with value 12
    bar(sp);
    cout << *sp << "\n";
    bar(make_shared<int>(n));
    cout << n << "\n";
    return 0;
}
