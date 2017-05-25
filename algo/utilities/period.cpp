
#if 0
#include <iostream>

using namespace std;


int solution(int n)
{
 int d[30];
 int l = 0;
 /*  convert to bin*/
 while (n > 0) {
   d[l] = n%2;
   n/=2;
   l++;
 }
 /* D holds the binary represetation of n */
 for(int p=1; p< 1+l; ++p )
 {
   bool ok = true;
   for (int i = 0; i < l-p; ++i)
   {
     if (d[i] != d[i+p])
     {
       ok = false;
       break;
     }
   }
   if(ok)
   {
    return p;
   }
 }
 return -1;
}


int main(void)
{
  cout << solution(955) << endl;
}
/*******************************************************************************/
#else
/*******************************************************************************/
/*
https://codility.com/c/feedback/M4JDUF-3UF

P <= Q/2
*/
#include <iostream>

using namespace std;


int solution(int n)
{
 int d[30];
 int l = 0;
 /*  convert to bin*/
 while (n > 0) {
   d[l] = n%2;
   n/=2;
   l++;
 }
 /* D holds the binary represetation of n */
 cout << "L:" << l << endl;
 for(int p=1; (p< 1+l) ; ++p )
 {
   bool ok = true; int max;
   cout << "p:" << p << endl;
   for (int i = 0; i < l-p; ++i)
   {
     cout << "i: " << i;
     if (d[i] != d[i+p])
     {
       ok = false;
       break;
     }
     else
     {
       cout << ".";
     }
   }
   cout << endl;
   if(ok )
   {
    return p;
   }
 }
 return -1;
}


int main(void)
{
  cout << solution(39333) << endl;
}
#endif
