#include <iostream>
#include <typeinfo>
using namespace std;

class Base {
    virtual void f() {};
};

class Derived1: public Base {
};

class Derived2: public Base {
};

template <typename T> class Number {
    T value;
public:
    Number(T n) { value = n; }
    T get_value() { return value; };
};

int main(int argc, const char *argv[])
{
    // built-in types
    {
        char c, *p;
        int i;
        long l;
        float f;
        double d;

        cout << endl;
        cout << "== built-in types" << endl;

        cout << "c's typeid().name: ";
        cout << typeid(c).name() << endl;

        cout << "p's typeid().name: ";
        cout << typeid(p).name() << endl;

        cout << "i's typeid().name: ";
        cout << typeid(i).name() << endl;

        cout << "l's typeid().name: ";
        cout << typeid(l).name() << endl;

        cout << "f's typeid().name: ";
        cout << typeid(f).name() << endl;

        cout << "d's typeid().name: ";
        cout << typeid(d).name() << endl;
    }

    // polymorphic types
    {
        Base b, *p;
        Derived1 d1;
        Derived2 d2;

        cout << endl;
        cout << "== polymorphic types" << endl;

        p = &b;
        cout << "*p's typeid().name: ";
        cout << typeid(*p).name() << endl;

        p = &d1;
        cout << "*p's typeid().name: ";
        cout << typeid(*p).name() << endl;

        p = &d2;
        cout << "*p's typeid().name: ";
        cout << typeid(*p).name() << endl;

        cout << endl;

        if (typeid(Base) == typeid(Derived1)) {
            cout << "Derived1 is same as Base" << endl;
        } else {
            cout << "Derived1 is not same as Base" << endl;
        }

        if (typeid(Derived2) == typeid(Derived1)) {
            cout << "Derived1 is same as Derived2" << endl;
        } else {
            cout << "Derived1 is not same as Derived2" << endl;
        }
    }

    // templete classes
    {
        Number<int> i(10);
        Number<double> d(3.14);

        cout << endl;
        cout << "== template_classes" << endl;

        cout << "i's typeid().name: ";
        cout << typeid(i).name() << endl;

        cout << "d's typeid().name: ";
        cout << typeid(d).name() << endl;

        cout << endl;

        if (typeid(Number<double>) == typeid(Number<int>)) {
            cout << "Number<int> is same as Number<double>" << endl;
        } else {
            cout << "Number<int> is not same as Number<double>" << endl;
        }
    }

    return 0;
}
