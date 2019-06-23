#include <bits/stdc++.h>

enum class DID : size_t {
  ETH_SIGNAL_QTY  = 0xff,
  VIN             = 0x02,
  NUMBER_ETH_PORT = 0x04,
};

struct Data{
  DID did;
  std::vector<uint8_t> data;
};

Data eth_quality(Data& did_data){
  std::vector<uint8_t> eth{0x30, 0x31, 0x33, 0x44};
  std::vector<uint8_t> resp;
  // copy the DID into the response
  uint8_t lower_byte = static_cast<uint8_t>(0xffu & static_cast<uint8_t>(did_data.did));
  uint8_t upper_byte = static_cast<uint8_t>((0xff00u & static_cast<uint8_t>( did_data.did)) >> 8u);
  // std::cout << "Upper byte" << std::hex << upper_byte;
  // std::cout << "lower byte" << std::hex << lower_byte;

  //for(uint8_t resp_byte : eth){
  // this will not work in the case eth is a dictionary, in that case use the for loop
  std::copy(std::begin(eth), std::end(eth), std::back_inserter(resp));
  //}

  resp.insert(std::begin(resp), lower_byte);
  resp.insert(std::begin(resp), upper_byte);
  return {DID::ETH_SIGNAL_QTY, {resp}};
}

void show_did(Data& d){
  using namespace std;
  cout << "Did: " << hex << static_cast<size_t>(d.did);
  cout << "\nData: ";
  for(auto& resp_byte : d.data){
    cout << resp_byte << " : ";
  }
  cout << '\n';

}
Data dispatch(Data& msg){
  switch (msg.did)
  {
  case DID::ETH_SIGNAL_QTY:
    /* code */
    return eth_quality(msg);
  case DID::NUMBER_ETH_PORT:
  case DID::VIN:
  default:
    return {DID::VIN, {0,0,0,0}};
    break;
  }
}

int main(void){
  Data test = {DID::ETH_SIGNAL_QTY, {0,0,0,0}};
  auto r = dispatch(test);
  show_did(r);
  return 0;
}