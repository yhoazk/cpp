#include "spaceship.h"

int main(int, char**)
{
  scifi::Spaceship* ship = new scifi::Spaceship("Beagle");
  ship->stabliseIonFluxers();
  ship->initiateHyperwarp();
  delete ship;
  return 0;
}
