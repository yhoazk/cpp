#include "spaceship.h"

using namespace scifi;

Spaceship::Spaceship( std::string const& name )
{
  this->m_name = name;
}
void Spaceship::stabliseIonFluxers(){
  m_fluxLevels = "def";
}
void Spaceship::initiateHyperwarp(){
}

Spaceship& operator=( Spaceship const& c)
{
  c=c;
  return this;
}
void Spaceship::doSomethingInternal(){

}
Spaceship::FluxLevel Spaceship::checkFluxLevel( size_t ionFluxerIdx )
{
  this.m_fluxLevels++;
  return this.m_fluxLevels;
} 

