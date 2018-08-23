#include <string>
#include <iostream>
#include <typeinfo>

using namespace std;

class MyException{};
class Dummy{

  public:
    Dummy(string s) : MyName(s) { PrintMsg("Created Dummy:"); }
    Dummy(const Dummy& other):MyName(other.MyName){ PrintMsg("Copy created dummy:");}
    ~Dummy(){ PrintMsg("Destroyed dummy");}

    void PrintMsg(string s) {cout << s << MyName << endl;}
    string MyName;
    int level;
};

void C(Dummy d, int i){
  cout << "entering fncC" << endl;
  d.MyName = "C";
  throw MyException();

  cout << "Exiting FncC" << endl;
}


void B(Dummy d, int i){
  cout << "Entering FncB" << endl;
  d.MyName = "B";
  C(d, i+1);
  cout << "Exiting FncB" << endl;
}

void A(Dummy d, int i){
  cout << "Entering FncA" << endl;
  d.MyName = "A";
  // Dummy *pd = new Dummy("New dummy"); // not exception safe!!
  B(d, i+1);
  //delete pd;
  cout << "Exiting FncA" << endl;
}

int main(){
  cout << "Entering Main" << endl;
  try{
    Dummy d(" M");
    A(d,1);
  } catch(MyException& e){
    cout << "Caught an exception of type: " << typeid(e).name() << endl;
  }

  cout << "Exiting main" << endl;
  char c;
  cin >> c;
}
