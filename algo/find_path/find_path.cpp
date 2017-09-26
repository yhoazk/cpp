#include <iostream>
#include <vector>
#include <queue>
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
/*
#define RIGHTMOST_LANE_IDX (0)
#define CENTER_LANE_IDX (1)
#define LEFTMOST_LANE_IDX (2)
*/


enum lane_id {
  rigthmost_lane = 0,
  center_lane,
  leftmost_lane
  };
using namespace std;


class node
{
public:
  // bool visited; not needed as it a tree
  // node* last; this will be implemented in the parent
  vector<node*> child_expand;
  vector<node*> parent_expand;
  int x;
  int y;
  char val;
  node(): child_expand{nullptr,nullptr,nullptr}, parent_expand{nullptr,nullptr,nullptr}, x(0),y(0), val('#')
  {
    /* Empty */
  }

  node* get_parent(enum lane_id lane)
  {
    return this->parent_expand[lane];
  }

  node* get_child(enum lane_id lane)
  {
    return this->child_expand[lane];
  }

  void set_parent(enum lane_id lane, node* n)
  {
    this->parent_expand[lane] = n;
  }

  void set_child(enum lane_id lane, node* n)
  {
    this->child_expand[lane] = n;
  }

  bool found()
  {
    return false;
  }
  /* The goal is to find a route to the end of the grid */
  void expand_parents(void)
  {

    /* check boundaries */
    if (x == rigthmost_lane)
    {
      set_parent(rigthmost_lane, nullptr);
      set_child(rigthmost_lane, nullptr);
    }
    else if (leftmost_lane == x)
    {

      set_parent(leftmost_lane, nullptr);
      set_child(leftmost_lane, nullptr);
    }


    /* Fill parent information*/
    if('O' != this->val)
    {
      /*if we are not root*/
      /* check  */
      if('.' != this->val)
      {
          std::cout << "/* message */" << '\n';
      }

    }
    else
    {
      /*we are root, nothing, all the parent is already nullptr */

    }

    /* Fill the child information */
  }

  void expand_children(void)
  {

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
  std::cout << "Print map address: " << &v << '\n';

  for (size_t i = 0; i < v.size(); i++)
  {
    for (size_t j = 0; j < v[0].size(); j++)
    {
      std::cout << v[i][j].val;
    }
    std::cout  << '\n';
  }
  std::cout  << '\n';

}

void fill_grid(std::vector<std::vector<node>>& v)
{
  std::cout << "Fill map address: " << &v << '\n';
  for (size_t i = 0; i < v.size(); i++)
  {
    for (size_t j = 0; j < v[0].size(); j++)
    {
      v[i][j].val = '#';
    }
  }
}

void set_val(std::vector<std::vector<node>>& v, size_t x, size_t y, char c)
{
  if(x < GRID_W && y < GRID_H)
  {
    v[y][x].val = c;
  }
}

bool finish = false;





/* A function will be created to parse the tree and return the path even is there's no
  option but to remain in the same state */

std::vector<int> find_path(node* root)
{

}


int main(int argc, char const *argv[]) {
  /* Init grid */
  std::cout << "Origianl Map address: " << &node_map << '\n';
  node_map.resize(GRID_H);
  for(auto& r : node_map) /* This needs to be a reference, otherwise will generate a copy */
  {
    r.resize(GRID_W);
    //fill(r.begin(), r.end(), '#')
  }
  fill_grid(node_map);
  /* Set the obstacles */
  set_val(node_map,0,10,'.');
  set_val(node_map,1,10,'.');


  /*------------*/
  node* me = new node;
  //me->set_me(1,2);


  std::cout << "map:" << node_map.size() << "x" << node_map[0].size() << '\n';
  /*setting Original position*/
  // while(!finish)
  {
    //me->expand();
  }
  print_grid(node_map);
  return 0;
}
