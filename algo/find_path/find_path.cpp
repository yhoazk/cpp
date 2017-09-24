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

using namespace std;

std::vector<std::vector<char>> map;
/* This is done by expanding the nodes, this means to watch at every position
   if what movements are possible, and penalizing the movements and discarting
   the impossible movemets
*/

void print_grid(std::vector<std::vector<char>>& v)
{
  std::cout << "Print map address: " << &v << '\n';

  for (size_t i = 0; i < v.size(); i++)
  {
    for (size_t j = 0; j < v[0].size(); j++)
    {
      std::cout << v[i][j];
    }
    std::cout  << '\n';
  }
  std::cout  << '\n';

}

void fill_grid(std::vector<std::vector<char>>& v)
{
  std::cout << "Fill map address: " << &v << '\n';
  for (size_t i = 0; i < v.size(); i++)
  {
    for (size_t j = 0; j < v[0].size(); j++)
    {
      v[i][j] = '#';
    }
  }
}

void set_val(std::vector<std::vector<char>>& v, size_t x, size_t y, char c)
{
  if(x < GRID_W && y < GRID_H)
  {
    v[y][x] = c;
  }
}


class node
{
public:
  bool visited;
  node* last;
  vector<node*> child_expand;
  vector<node*> parent_expand;
  int x;
  int y;
  std::vector<std::vector<char>>* gmap;
  node(): visited(false), last(nullptr), child_expand{nullptr,nullptr,nullptr}, parent_expand{nullptr,nullptr,nullptr}, x(0),y(0), gmap(&map)
  {
    /* Empty */
  }
  void set_me(int n_x, int n_y)
  {
    if((x < map[0].size()) && (y < map.size()))
    {
      x=n_x; y=n_y;
      map[y][x] = 'O';
    }
  }
  /* Sets a change in the car motion could be | / \ */
  void set_change(int n_x, int n_y, char c)
  {
    if((x < map[0].size()) && (y < map.size()))
    {
      x=n_x; y=n_y;
      map[y][x] = c;
    }
  }

  bool found()
  {
    return false;
  }

  void expand(void)
  {
    
  }
};




int main(int argc, char const *argv[]) {
  /* Init grid */
  std::cout << "Origianl Map address: " << &map << '\n';
  map.resize(GRID_H);
  for(auto& r : map) /* This needs to be a reference, otherwise will generate a copy */
  {
    r.resize(GRID_W);
    //fill(r.begin(), r.end(), '#')
  }
  fill_grid(map);
  /* Set the obstacles */
  set_val(map,0,10,'.');
  set_val(map,1,10,'.');


  /*------------*/
  node* me = new node;
  me->set_me(1,2);


  std::cout << "map:" << map.size() << "x" << map[0].size() << '\n';
  /*setting Original position*/
  while(me->found() == false)
  {

  }
  print_grid(map);
  return 0;
}
