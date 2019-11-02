#include <iostream>
#include <cassert>


/**
 * Demo for use after move
 * 
 * Here the object is used after it was moved.
 * There is no warning from gcc or clang and the program runs and ends 
 * as expected.
 * 
 * Clang offers annotations which can be used to detect this errors
 * The class is marked as consumable, objects from this class then exist in one
 * of three states:
 * - unconsumed
 * - consumed
 * - unknown
 * 
 * 
 * The program needs to be compiled with clang++ with the flag -Wconsumed
*/

using namespace std;

#ifdef __clang__
class [[clang::consumable(unconsumed)]] smart_obj{
public:
    [[clang::return_typestate(unconsumed)]]
    smart_obj(){}
    smart_obj(smart_obj&& other){other.invalidate();}
    [[clang::callable_when(unconsumed)]]
    void do_sth(){assert(m_valid);}
public:
    [[clang::set_typestate(consumed)]]
    void invalidate(){m_valid = false;}
    bool m_valid { true };

};
#endif

class Object {
public:
    Object() {cout << "ctor()\n";}
    Object(Object&& other){ cout << "ctor(&&)\n";  other.invalidate();}
    // w/o this assert the program contiues to run
    void do_sth(){assert(m_valid); cout << "Hallochen\n";}


private:
    void invalidate(){m_valid=false;}
    bool m_valid{true};
};


int main(){
#ifdef __clang__
    
    smart_obj smart;
    auto cpy_smart = std::move(smart);
    smart.do_sth();
#endif

    Object object;
    auto other = std::move(object);
    object.do_sth(); // this object was already moved, what is the output of this?
    return 0;
}