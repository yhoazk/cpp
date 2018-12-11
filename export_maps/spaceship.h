#include <string>
#include <vector>

namespace scifi
{
  typedef int FluxLevels;
class Spaceship
{
public:
  Spaceship( std::string const& name );
  ~Spaceship();
  void stabliseIonFluxers();
  void initiateHyperwarp();
private:
  Spaceship( Spaceship const& );
  Spaceship& operator=( Spaceship const& );
private:
  typedef unsigned int            FluxLevel;
  typedef std::vector<FluxLevel>  FluxLevels;
private:
  void doSomethingInternal();
  FluxLevel checkFluxLevel( size_t ionFluxerIdx );
private:
  std::string m_name;
  FluxLevels  m_fluxLevels;
};
}

