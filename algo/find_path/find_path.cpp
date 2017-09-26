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


typedef enum lane_id {
  rigthmost_lane = 0,
  center_lane,
  leftmost_lane
  };
using namespace std;

bool found = false;
bool finished = false;
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
  static std::vector<int> path;
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
  /* return the possible paths for this node */
  void expand(void)
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
std::vector<int>  node::path = {};

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
    v[y][x].x = x;
    v[y][x].y = y;

  }
}




/* A function will be created to parse the tree and return the path even is there's no
  option but to remain in the same state */

std::vector<int> find_path(node* root)
{
  std::cout << "root: O == " << root->val << '\n';
  found = false;
  finished = false;
  queue<node*> node_queue;
  node* current_node;
  node* next_node;
  node_queue.push(root);
  int inc_x;
  std::vector<int> possible_movs;

  while (node_queue.empty() != true || found == true)
  {
    next_node = nullptr;
    possible_movs = {rigthmost_lane, center_lane, leftmost_lane};
    current_node = node_queue.front();
    node_queue.pop();
    cout << "______________________________________ Queue size: " << node_queue.size() << endl;
    std::cout << "current_node x: " << current_node->x << "  y: " << current_node->y << " val: " << current_node->val << '\n';
    /* check possible paths in which the node can move */
    /**/
    if(rigthmost_lane == current_node->x)
    {
      possible_movs.erase( possible_movs.begin() + int(rigthmost_lane) );
    }
    else if(leftmost_lane == current_node->x)
    {
      possible_movs.erase( possible_movs.begin() + int(leftmost_lane) );
    }


    /* Fill the child info */
    for(auto lane: possible_movs)
    {
      std::cout << "lane available: " << lane << '\n';
      switch (lane)
      {
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

      next_node = &node_map[ (current_node->y)+1 ][ (current_node->x)+inc_x ]; /// ‘__gnu_cxx::__alloc_traits<std::allocator<node> >::value_type {aka node}’ to ‘node*’ in assignment
      next_node->x = (current_node->x)+inc_x;
      next_node->y = (current_node->y)+1;

      if('#' == next_node->val)
      {
        std::cout << "next_node x: " << next_node->x << "  y: " << next_node->y << '\n';
        current_node->set_child(lane_id(lane), next_node);
        node_queue.push(next_node);
      }
      else if('G' == next_node->val)
      {
        found = true;
      }
    }

  }

  if(found)
  {

    return root->path;
  }
  else
  {
    return {};
  }

}


int main(int argc, char const *argv[]) {
  /* Init grid */
  std::cout << "Origianl Map address: " << &node_map << '\n';
  node_map.resize(GRID_H);
  for(auto& r : node_map) /* This needs to be a reference, otherwise will generate a copy */
  {
    r.resize(GRID_W);
  }
  // fill_grid(node_map);
  /* Set the obstacles */
  set_val(node_map,0,10,'.');
  set_val(node_map,1,10,'.');
                // x y
  set_val(node_map,1,2,'O'); // setting the root node
  set_val(node_map,1,11,'G'); // setting the root node

std::vector<int> sol;
print_grid(node_map);   //y  x
sol = find_path(&node_map[2][1]);


  /*------------*/
  std::cout << "map:" << node_map.size() << "x" << node_map[0].size() << '\n';
  /*setting Original position*/
  print_grid(node_map);
  return 0;
}
