/* Code about a PR where this was found 
The override in the definition of concrete methods of an abstract class make sense
to be sure that they are actually overriding and not implementing a new overload
*/

#include <cstdint>

namespace func {

class module_interface {
    virtual bool is_ok() = 0;
    virtual void apply_change(std::uint8_t) = 0;
};

// https://stackoverflow.com/questions/46446652/is-there-any-point-in-using-override-when-overriding-a-pure-virtual-function
class module : public module_interface {
    private:
    std::uint8_t value{};
    public:
    bool is_ok() override;
    // bool is_ok();
    void apply_change(std::uint8_t) override;
    // void apply_change(std::uint8_t);
};
} // namespace func