#include <bits/stdc++.h>
int main(){
  std::map<int,int> ordered_map;

  ordered_map[20] = 0;
  ordered_map[2] = 1;
  ordered_map[14] = 2;
  ordered_map[98] = 3;
  ordered_map[0] = 4;

  for(auto& p : ordered_map){
    std::cout << "Key: " << p.first << " Val: " << p.second << '\n';
  }

  // In the expected output the result will be ordered by ascending key value
  //Key: 0 Val: 4
  //Key: 2 Val: 1
  //Key: 14 Val: 2
  //Key: 20 Val: 0
  //Key: 98 Val: 3
  // 
  //
  std::cout << "----------- Give a different order to the ordered map ---------\n";
  // To change the ordering of the elements or give an specific comparator use
  std::map<int, int, std::greater<int> > reverse_ordered_map;
  reverse_ordered_map[20] = 0;
  reverse_ordered_map[2] = 1;
  reverse_ordered_map[14] = 2;
  reverse_ordered_map[98] = 3;
  reverse_ordered_map[0] = 4;

  for(auto& p : reverse_ordered_map){
    std::cout << "Key: " << p.first << " Val: " << p.second << '\n';
  }

  std::cout << "--------- Try now with unordered maps -------------------------\n";
  // To change the ordering of the elements or give an specific comparator use
  std::unordered_map<int, int> unord_map;
  unord_map[20] = 0;
  unord_map[2] = 1;
  unord_map[14] = 2;
  unord_map[98] = 3;
  unord_map[0] = 4;

  for(auto& p : unord_map){
    std::cout << "Key: " << p.first << " Val: " << p.second << '\n';
  }
  std::cout << "--------- No order guaraties are given ------------------------\n";
}
