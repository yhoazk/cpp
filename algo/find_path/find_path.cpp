#include <iostream>
#include <vector>

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



**/
#define GRID_W (3)
#define GRID_H (15)

std::vector<std::vector<char>> map;
/* This is done by expanding the nodes, this means to watch at every position
   if what movements are possible, and penalizing the movements and discarting
   the impossible movemets
*/





int main(int argc, char const *argv[]) {

  return 0;
}
