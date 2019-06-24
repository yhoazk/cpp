#include <bits/stdc++.h>

namespace uds {

  enum class SID : uint8_t{
    kDataRequest = 0x22,
    kServiceRequest = 0x31,
  };
  using Data = std::vector<uint8_t>;
  struct UdsMessage{
    SID sid;
    Data data;
  };
}