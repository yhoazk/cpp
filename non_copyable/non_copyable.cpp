/* Non copyable object */
/* There are 2 methods or just one if the compiler ir <C++11 */
class Foo_M1 {
  private:
    Foo_M1();
    Foo_M1(const Foo_M1&); // non construction-copyable
    Foo_M1& operator=(const Foo_M1&);
    int u;
  public:
      Foo_M1(int k):u(k){
      }
};



class Foo_M2 {
  private:
    Foo_M2();
    Foo_M2( const Foo_M2&) = delete;
    Foo_M2& operator=( const Foo_M2&) = delete; //Non-copyable
    int u;
  public:
    Foo_M2(int k): u(k){
    }
};


int main()
{
  Foo_M1 nc(4);
  Foo_M2 nc_2(4);
  Foo_M2 nc_2a = nc_2; // copy constructor
  return 0;
}
