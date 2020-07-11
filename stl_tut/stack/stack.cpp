#include <iostream>
#include <vector>
#include <stack>

/* My stack */

int main(int c, char** v, char** e) {
    using namespace std;
    stack<int,vector<int>> s{};
    s.push(5);
    s.push(5);
    s.push(5);
    s.push(5);
    cout << "Size: " << to_string(s.size()) << '\n';
    return 0;
}
