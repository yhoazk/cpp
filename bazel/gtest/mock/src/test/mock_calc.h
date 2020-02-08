#include "gmock/gmock.h"
#include "calc.cpp" // should the C file be added?

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Invoke;

class mock_basic_math : public basic_math {
    public:
    mock_basic_math(){
        //by default all calls are delegated to the real obj
        ON_CALL(*this, addition(_,_))
            .WillByDefault(Invoke(&real_, &basic_math::addition));
        ON_CALL(*this, multiply(_,_))
            .WillByDefault(Invoke(&real_, &basic_math::multiply));
        ON_CALL(*this, divide(_,_))
            .WillByDefault(Invoke(&real_, &basic_math::divide));
    }
    MOCK_METHOD2(addition, int(int,int));
    MOCK_METHOD2(multiply, int(int,int));
    MOCK_METHOD2(divide, int(int,int));
    private:
    basic_math real_;
};