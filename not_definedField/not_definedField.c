#include <stdio.h>
#include <stdlib.h>
/* Demo for undefined field in the initalization of a const 
 * array of structs 
 * There's a missing initialization for  the element W
 * The members of the struct that are not explicitly initialized
 * have the value of 0 for ints, 0.0 for floats and NULL for pointers
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

void fnc(unsigned char* ret){
    array_element_t* s;
    s = malloc(sizeof(array_element_t));
    s->x = 24;
    *ret = s->w;
    free(s);
    return;
}


int main(void)
{
    int i;
    unsigned char res = 0;
    for(i=0; i<sizeof(TA)/sizeof(TA[1]); i++)
    {
        printf("X:%i ", TA[i].x);
        printf(" Y:%i ", TA[i].y);
        printf(" Z:%i ", TA[i].z);
        printf(" W:%i\n", TA[i].w);
    }
    fnc(&res);
    printf("From function: %i\n", res);
    return 0;
}
