#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <gtest/gtest.h>

/**
This program find the path of the '0' in order to keep moving forward
it will use a simplie scheme as there's no goal per se.

The given map is:

###  ###  ###   ###  ###  ###
.##  .##  .##   .##  .##  .##
###  ###  ###   ###  ###  ###
###  ###  ###   ###  ###  ###
###  ###  ###   ###  ###  ###
#O#  #O#  #O#   #O#  #O#  #O#
###->#|#->#|# ->#|#->#|#->#|#
###  ###  #|#   #|#  #|#  #|#
###  ###  ###   #|#  #|#  #|#
.#.  .#.  .#.   .|.  .|.  .|.
###  ###  ###   ###  #|#  #|#
###  ###  ###   ###  #|#  #|#
###  ###  ###   ###  ###  #|#
###  ###  ###   ###  ###  #|#
###  ###  ###   ###  ###  #|#

---
###  ###  ###  ###  ###  ###
.##  .##  .##  .##  .##  .##
###  ###  ###  ###  ###  ###
###  ###  ###  ###  ###  ###
###  ###  ###  ###  ###  ###
#O#  #O#  #O#  #O#  #O#  #O#
#/#->#/#->#/#->#/#->#/#->#/#
#.#  |.#  |.#  |.#  |.#  |.#
###  ###  #\#  #\#  #\#  #\#
.#.  .#.  .#.  .|.  .|.  .|.
###  ###  ###  ###  #|#  #|#
###  ###  ###  ###  ###  #|#
###  ###  ###  ###  ###  #|#
###  ###  ###  ###  ###  #|#
###  ###  ###  ###  ###  #|#
---
###  ###  ###   ###  ###  ###
.##  .##  .##   .##  .##  .##
###  ###  ###   ###  ###  ###
###  ###  ###   ###  ###  ###
###  ###  ###   ###  ###  ###
O##  O##  O##   O##  O##  O##
|##->|##->|## ->|##->|##->|##
###  |##  |##   |##  |##  |##
###  ###  #\#   #\#  #\#  #\#
.#.  .#.  .#.   .|.  .|.  .|.
###  ###  ###   ###  #|#  #|#
###  ###  ###   ###  ###  #|#
###  ###  ###   ###  ###  ###
###  ###  ###   ###  ###  ###
###  ###  ###   ###  ###  ###
---
###  ###  ###   ###  ###  ###
.##  .##  .##   .##  .##  .##
###  ###  ###   ###  ###  ###
###  ###  ###   ###  ###  ###
###  ###  ###   ###  ###  ###
O##  O##  O##   O##  O##  O##
\##->\##->\## ->\##->\##->\##
###  #\#  #\#   #\#  #\#  #\#
###  ###  ##|   ##|  ##|  ##|
..#  ..#  ..#   ..|  ..|  ..|
###  ###  ###   ###  ##|  ##|
###  ###  ###   ###  ###  ##|
###  ###  ###   ###  ###  ###
###  ###  ###   ###  ###  ###
###  ###  ###   ###  ###  ###



The '.' are grids which cannot be occupied.

Bread-first search:

* The elements need to be explored in the same order they are being added to the queue.
* Once a node is checked (expanded) must not be checked again, otherwise the algorithm migth end up in an infinite loop.

- Two queues are needed, first the not expanded nodes, and the second the already expanded nodes.
we can use a special node type to check if a node was already expanded.

### Using the limitations of the vehicle we can simplify as the movement can only be in one direction,
try a straight paths unless an obstacle is found.

**/

#define GRID_W (3)
#define GRID_H (15)

enum lane_id{
  rigthmost_lane = 0,
  center_lane,
  leftmost_lane
};
using namespace std;

bool found = false;
bool finished = false;
class node{
public:
  // bool visited; not needed as it a tree
  // node* last; this will be implemented in the parent
  vector<node*> child_expand;
  vector<node*> parent_expand;
  int x;
  int y;
  char val;
  bool expanded;
  node(): child_expand{nullptr,nullptr,nullptr}, parent_expand{nullptr,nullptr,nullptr}, x(0),y(0), val('#'), expanded(false)
  {
    /* Empty */
  }

  node* get_parent(enum lane_id lane)
  {
    return parent_expand[lane];
  }

  node* get_child(enum lane_id lane)
  {
    return child_expand[lane];
  }

  void set_parent(enum lane_id lane, node* n)
  {
    parent_expand[lane] = n;
  }

  void set_child(enum lane_id lane, node* n)
  {
    child_expand[lane] = n;
  }
};

/* Crete the array of nodes */
std::vector<std::vector<node>> node_map;
/* This is done by expanding the nodes, this means to watch at every position
   if what movements are possible, and penalizing the movements and discarting
   the impossible movemets
*/

void print_grid(std::vector<std::vector<node>>& v)
{
  std::cout << "   0 1 2" << '\n';

  for (size_t i = 0; i < v.size(); i++)
  {
    std::cout.width(2);
    std::cout <<  i << '|' << ' ';
    for (size_t j = 0; j < v[0].size(); j++)
    {
      std::cout << v[i][j].val << ' ';
    }
    std::cout  << '\n';
  }
  std::cout  << '\n';

}

void fill_grid(std::vector<std::vector<node>>& v){
  std::cout << "Fill map address: " << &v << '\n';
  for(auto& r : v){
    for(auto& e : r){
      e.val = '#';
    }
  }
}

void set_val(std::vector<std::vector<node>>& v, size_t x, size_t y, char c){
  if(x < GRID_W && y < GRID_H){
    v[y][x].val = c;
    v[y][x].x = x;
    v[y][x].y = y;

  }
}
node* check_parent(node* n, vector<char>& sol){
  char decoder[] = {'/','|','\\'};
  static const vector<size_t> prio = {1,2,0}; // first keep lane, second left, tird right
  //vector<node*> result = {nullptr, nullptr, nullptr};
  node* result;// = {nullptr, nullptr, nullptr};
  int refs = 0; //number of encountered references

  for(auto k: prio){
    if(nullptr != n->parent_expand[k]){
        cout << decoder[k];
        sol.push_back(decoder[k]);
        result = n->parent_expand[k];
        result->val = decoder[k];
        ++refs;
        break;
    }
  }

  if(refs > 1){
    cout << "TWO or more references found" << endl << endl;
  }  else  {
    /* nop */
  }
  print_grid(node_map);
  return result;
}


/* A function will be created to parse the tree and return the path even is there's no
  option but to remain in the same state */

std::vector<char> find_path(node* root)
{
  found = false;
  finished = false;
  queue<node*> node_queue;
  node* current_node;
  node* next_node;
  node* goal_node; // if found
  node_queue.push(root);
  int inc_x;
  static vector<char> path;
  std::vector<int> possible_movs;

  while (node_queue.empty() != true && found == false){
    next_node = nullptr;
    possible_movs = {center_lane, leftmost_lane,  rigthmost_lane};
    current_node = node_queue.front();
    node_queue.pop();
    if(current_node->expanded == true){
      continue;
    }
    cout << "______________________________________ Queue size: " << node_queue.size() << endl;
    std::cout << "current_node x: " << current_node->x << "  y: " << current_node->y << " val: " << current_node->val << '\n';
    for(int i = 0; i < current_node->x; ++i)
        cout <<  "   ";
    /* check possible paths in which the node can move */

// the node being appended so it can be registered??

    /**/
    if(rigthmost_lane == current_node->x){
      possible_movs.erase( possible_movs.begin() + 2);
    } else if(leftmost_lane == current_node->x){
        possible_movs.erase( possible_movs.begin() + 1);
    }

    /*By reversing the elements the move to the left comes first in prio*/
    //reverse(possible_movs.begin(), possible_movs.end());
    char decode_show[] = {'/','|','\\'};
    for(auto lane: possible_movs){
      switch (lane){
        case rigthmost_lane:
          inc_x = -1;
        break;
        case leftmost_lane:
          inc_x = 1;
        break;
        case center_lane:
        default:
          inc_x = 0;
      }

      next_node = &node_map[ (current_node->y)+1 ][ (current_node->x)+inc_x ];
      next_node->x = (current_node->x)+inc_x;
      next_node->y = (current_node->y)+1;

      if(next_node->y > 13)
      {
        cout << "ENDD"<< endl;
      }
      /* Fill the child info */
      if('#' == next_node->val)
      {
       // std::cout << "next_node x: " << next_node->x << "  y: " << next_node->y << '\n';
        // cout << decode_show[lane];
        current_node->set_child(lane_id(lane), next_node);
        node_queue.push(next_node);
        next_node->set_parent(lane_id(lane), current_node);
      } else if('G' == next_node->val){
        cout << decode_show[lane];
        current_node->set_child(lane_id(lane), next_node);
        next_node->set_parent(lane_id(lane), current_node);
        cout << "\nFOUND";
        goal_node = next_node;
        cout << " Coordx: " << goal_node->x << " Coordy: " << goal_node->y   << endl;
        found = true;
        /* Now that we now exists a path to the goal, find the best one           */
        /* Check which of the possible parent have a refernce to me (the child node) */
        /* If that reference exists, then is part of the path, not otherwise         */
        while(goal_node != root){
            goal_node = check_parent(goal_node, path);
        }
      }
    }
    current_node->expanded = true;
    std::cout << endl;
  }

  if(!found){
    /* There's no possible path to the to the goal*/
    cout << "NO PATH!!!!!!!!!!1" << endl;
    return {};
  } else {
    return path;
  }

}


void print_resuls(vector<char>& s){
  reverse(s.begin(), s.end());
  for(size_t i=0; i < s.size(); ++i)
  {
    switch(s[i]){
      case '|':
        cout << "Keep on the same lane" << endl;
        break;
      case '\\':
        cout << "Change to left lane" << endl;
        break;
      case '/':
        cout << "Change to right lane" << endl;
        break;
    }
  }
}

TEST(find_path, test_one){
  EXPECT_EQ(true, true);
}

#if 0
int main(int argc, char const *argv[]) {
  /* Init grid */
  std::cout << "Original Map address: " << &node_map << '\n';
  node_map.resize(GRID_H);
  for(auto& r : node_map) /* This needs to be a reference, otherwise will generate a copy */
  {
    r.resize(GRID_W);
  }
  set_val(node_map,0,6,'.');
  set_val(node_map,1,8,'.');
  set_val(node_map,2,6,'.');
                // x y
  set_val(node_map,1,2,'O'); // setting the root node
  set_val(node_map,0,13,'G'); // setting the root node

  std::vector<char> sol;
  print_grid(node_map);   //y  x
  sol = find_path(&node_map[2][1]);

  /*------------*/
  std::cout << "map:" << node_map.size() << "x" << node_map[0].size() << '\n';
  print_resuls(sol);
  /*setting Original position*/
  return 0;
}
#endif