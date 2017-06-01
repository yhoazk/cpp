#include <stdio.h>

/* Demo for undefined field in the initalization of a const 
 * array of structs 
 * There's a missing initialization for  the element W
 * */


typedef struct _array_element
{
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char w;
} array_element_t;

const array_element_t TA [] = 
{
    {1,2,3,},
    {4,5,6,},
    {7,8,9,},
    {'a','b','c',},
    {'e','f','g',},
};



int main(void)
{
    int i;
    for(i=0; i<sizeof(TA)/sizeof(TA[1]); i++)
    {
        printf("X:%i ", TA[i].x);
        printf(" Y:%i ", TA[i].y);
        printf(" Z:%i ", TA[i].z);
        printf(" W:%i\n", TA[i].w);
    }
    return 0;
}
