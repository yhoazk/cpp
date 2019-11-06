#include <stdio.h>



#pragma pack(push)
#pragma pack(1)
struct test{
    char aa;
    int  bb;
    short cc;
    long dd;
    union {
        //_Decimal128 ee1;
        long ee2[2];
    }ee;
};
#pragma pack(pop)
// without the push pop pragmas this struct will have sizeof
// 9 = lon (8) + char(1)
// currently has a sizeof 16 xx gets padded to the same size as yy
struct my_other{
    char xx;
    long yy;
};

struct att_struct{

} __attribute__((__pack__));

int main(){
    struct test a;
    a.aa = (char) 0x44;
    a.bb = 0x55555555;
    a.cc = 0x6666;
    a.dd = 0x7777777777777777;
    a.ee.ee2[0]=0x8888888888888888;
    a.ee.ee2[1]=0x8888888888888888;
    

    printf("size of struct = %d\n",sizeof(struct my_other));
    int ptr=0xffffffff; 
    printf("size of struct = %d\n",sizeof(struct test));
    printf("a =%p\n",&a);
    printf("aa=%p   offset = %d\n",&(a.aa),(int)(&(a.aa))-(int)(&a));
    printf("bb=%p   offset = %d\n",&(a.bb),(int)(&(a.bb))-(int)(&a));
    printf("cc=%p   offset = %d\n",&(a.cc),(int)(&(a.cc))-(int)(&a));
    printf("dd=%p   offset = %d\n",&(a.dd),(int)(&(a.dd))-(int)(&a));
    printf("ee=%p   offset = %d\n",&(a.ee),(int)(&(a.ee))-(int)(&a));
    printf("pt=%p\n",&ptr);

    return 0;
}