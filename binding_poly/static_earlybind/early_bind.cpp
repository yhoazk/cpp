/*
  Bindign refers to the process that is to be used for converting functions and
  variables into machine language addresses
  When the ambiguites are fixed at compile time it's called static or early Bindign
*/
#include <iostream>

using namespace std;

class first
{
  int b;
public:
  first(){b=10;}
  void display()
  {
    cout << "b=" << b << endl;
  }
};

class second: public first
{
  int d;
public:
  second(){d=20;}
  void display()
  {
    cout << "d=" << d << endl;
  }
};

int main(int argc, char const *argv[]) {
  second s;
  s.first::display();
  s.display();
  /* Example showing the need  of late Bindign */
  first f,*p;
  p=&f;
  p->display(); /* prints b=10 */
  p=&s;
  p->display(); /* Also prints b=10 */


  return 0;
}
