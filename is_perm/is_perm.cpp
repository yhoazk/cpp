// C++ program to demonstrate working of
// is_permutation()
#include <bits/stdc++.h>
using namespace std;
 
// Driver program to test above
int main()
{
    vector<int> v1{1, 2, 3, 4};
    vector<int> v2{2, 3, 1, 4};
 
    // v1 and v2 are permutation of each other
    if (is_permutation(v1.begin(), v1.end(), v2.begin()))
        cout << "True\n";
    else
        cout << "False\n";
 
    // v1 and v3 are NOT permutation of each other
    vector<int> v3{5, 3, 1, 4};
    if (is_permutation(v1.begin(), v1.end(), v3.begin()))
        cout << "True\n";
    else
        cout << "False\n";
 
    return 0;
}
