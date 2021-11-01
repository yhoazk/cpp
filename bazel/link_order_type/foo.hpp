#ifndef __LIBFOO1__
#define __LIBFOO1__

namespace first {
template<typename T>
struct Result {
    T value;
    bool get();
    void clear();
    int get_val();
};
}
#endif  // __LIBFOO1__