/* This is a demo to see how is the life cycle of a variable generated 
 * inside a function. This is a c++ demo */

#include <iostream>

unsigned char* create_array( char c)
{
    char *r;
    char k[4];
    int i;
    for(i=0; i<4; ++i)
    {
        k[i] = c;
    }
    r = k;
    
    return r;
}


int main()
{


}
