#include "wtf.h"

namespace func {

// bool module::is_ok() {
    // return value == 99;
// }
void module::apply_change(std::uint8_t update) {
    value = update;
}

bool module::is_ok(int) {
    return true;
}

} // namespace func