#include <bits/stdc++.h>
using namespace std;


vector<int> cuenta = {0,1,2,3,4,5,6,7};
int main()
{
  for_each(cuenta.begin(), cuenta.end(), [](int &n){cout << " n: " << n;});
  cout << endl;
  for_each(cuenta.begin(), cuenta.end(), [](int &n){n=n*n;});
  for_each(cuenta.begin(), cuenta.end(), [](int &n){cout << " n: " << n;});
  cout << "v" << endl;
  return 0;
}
