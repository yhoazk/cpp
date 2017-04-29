/*
 * Example on how to access elements in a vector of structs
 * */
#include <iostream>
#include <vector>
#include <random>

#define PARTICLE_NUMBER (200)

typedef struct 
{
  double x;
  double y;
  double th;
} particle_t;


std::vector<particle_t> Particles;
std::default_random_engine eng;
std::normal_distribution<double> norm(0.0, 1.0); // noise 

int main(int argc, char* arg[])
{
  particle_t p;
  for(int i = 0; i < PARTICLE_NUMBER; ++i)
  {
    p.x = norm(eng);
    p.y = norm(eng);
    p.th = norm(eng);
    Particles.push_back(p);
  }

  /* Access to each particle */
  for(std::vector<particle_t>::iterator p_it = Particles.begin(); p_it != Particles.end(); ++p_it)
  {
    std::cout << p_it->x << std::endl;
  }
}

