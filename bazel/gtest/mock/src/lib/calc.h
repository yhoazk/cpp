#ifndef BASIC_MATH_APP
#define BASIC_MATH_APP

class basic_math {
public:
    basic_math(){}
    virtual ~basic_math(){}
    virtual int addition(int x, int y);
    virtual int multiply(int x, int y);
    virtual int divide(int x, int y);

};

#endif /* BASIC_MATH_APP */
