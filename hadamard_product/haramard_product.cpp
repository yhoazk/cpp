#include <iostream>
#include <vector>
/* The macro NDEBUG disables the asserts. 
 * If the macro is defined at the moment of the inclusion of 
 * the assert.h the assert function call does not affects the 
 * program.
 * */
#define NDEBUG
#include <assert.h>
using namespace std;

vector<vector<int>> Mx = {{1,2,3},{3,2,1},{3,4,5}};
vector<vector<int>> My = {{1,2,3},{3,2,1},{3,4,5}};
vector<vector<int>> Mz = {{0,0,0},{0,0,0},{0,0,0}};
template <class T>
bool haramard_product(const vector<vector<T>>& ma, const vector<vector<T>>& mb,\
        vector<vector<T>>& mo)
{
    bool success = false;
    std::int32_t rows = (ma.size() == mb.size())? ma.size() : 0;
    if(rows > 0)
    {
        std::int32_t columns = (ma[0].size() == mb[0].size())? ma[0].size() : 0;
        std::cout << "Matrix size: " << rows << " x " << columns << "\n";
        for(std::int32_t i=0; i < columns; ++i)
        {
            for(std::int32_t j=0; j < rows; ++j)
            {
                mo[i][j] = ma[i][j] * mb[i][j];
            }
        }
        success = true;
    }
    else
    {
        std::cout << "Empty matrix" << "\n";
    }

    return success;
}

template<class T>
void print_matrix(vector<vector<T>>& m)
{
/*    size_t r,c;
    r = m.size(); c = m[0].size();*/
    for(auto x: m)
    {
        for(auto y:x)
        {
            std::cout << y << " ";
        }
        cout << "\n";
    }
}


int main()
{
    assert(false);
    cout << "Matrix X:\n\n";
    print_matrix(Mx);
    cout << "Matrix Y:\n\n";
    print_matrix(My);

    if(haramard_product(Mx,My,Mz))
    {
        std::cout << "Success\n";
        cout << "Matrix result:\n\n";
        print_matrix(Mz);
    }
    else
    {
        std::cout << "Error\n";
    }
    return 0;
}
