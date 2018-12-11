#include <iostream>
#include <functional>

int classic_fnc_add_6(int x)
{
    return (6 + x);
}

int main()
{
    /* Store a classic function */
    std::function<int(int)> classic_fnc = classic_fnc_add_6;

    /* lambda */
    std::function<void()> lambda_fnc = [](){std::cout << "lambda\n"; };

    /* Store the result of a bind  */
    std::function<int()> bind_fnc = std::bind(classic_fnc_add_6, 4);
    ////
    std::cout << "Classic function: " << classic_fnc(24);
    std::cout << "\nThis is the ";   lambda_fnc();
    std::cout << "Binded fnc: " << bind_fnc() << std::endl;
}
