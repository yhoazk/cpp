#include <iostream>
#include <variant>
#include <string>

enum class Err : std::uint32_t {
    ENEN = 0,
    ENAN = 1,
};

struct dummy{};
struct visitor{
    void operator()(int) {std::cout << "Integer" << std::endl;}
    void operator()(float) {std::cout << "float" << std::endl;}
    void operator()(std::string) {std::cout << "string" << std::endl;}
    void operator()(dummy) {std::cout << "dummy" << std::endl;}
    void operator()(std::variant<int,float>) {std::cout << "nested variant" << std::endl;}
};


int main() {
    std::variant<int, float> int_float{10.0f};
    std::variant<dummy, float> void_float{10.0f};
    try{
        std::cout << int_float.index() << ", value: " << std::get<int>(int_float) << std::endl;
    } catch (std::bad_variant_access&){
        std::cout << "Variant int type has not been initialized" << std::endl;
    }

    try{
        std::cout << int_float.index() << ", value: " << std::get<float>(int_float) << std::endl;
    } catch (std::bad_variant_access&){
        std::cout << "Variant int type has not been initialized" << std::endl;
    }
    // the fist type is the one which is intialized by default
    std::variant<float, int, std::string> var{};
    std::visit(visitor{}, var);

    // By passing a compatible type, that member gets initialized
    std::variant<float, int, std::string> var1{"sss"};
    std::visit(visitor{}, var1);
    // Variant can also hold non-native types
    std::variant<dummy, float, int, std::string> var2{};
    std::visit(visitor{}, var2);

    // Can it also hold nested variants?
    std::variant<std::variant<int,float>, int, std::string> var3;
    std::visit(visitor{}, var3);



    return 0;
}
