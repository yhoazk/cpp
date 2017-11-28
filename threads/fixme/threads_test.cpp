/**
 * https://www.classes.cs.uchicago.edu/archive/2013/spring/12300-1/labs/lab6/
 * */

#include <iostream>
#include <thread>

using namespace std;

void func(int x)
{
    cout << "Th: " << x << endl;
}

int main()
{
    /* create a single tread with id 100 */
    thread th(&func, 100);
    /* create a single tread with id 200 */
    thread th_2(&func, 200);
    th.join();
    th_2.join();
    cout << "Out of thread" << endl;
    return 0;
}
