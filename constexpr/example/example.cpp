#include <iostream>

template<int N>
struct Table
{
    constexpr Table() : values()
    {
        for (auto i = 0; i < N; ++i)
        {
            values[i][0] = i;
            values[i][1] = i * i * i;
        }
    }
    int values[N][2];
};

int main() {
    constexpr auto a = Table<1000>();
    for (auto x : a.values)
        std::cout << "f(" << x[0] << ") = " << x[1] << '\n';
}