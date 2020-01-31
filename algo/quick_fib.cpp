#include <iostream>
using namespace std;

int qfib(int k){
    return (k <= 0? 1 : qfib(k-1) + qfib(k-2));
}


int qfact(int f){
    return (f <=0? 1 : f*qfact(f-1));
}

int main(){
    int n=0;
    cin >> n;
    cout << qfib(n) << '\n';
    cout << qfact(n) << '\n';
    return 0;
}
