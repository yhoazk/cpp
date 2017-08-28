#include <iostream>



double calculateAcceleration(double current, double target)
{
  static double integral_term = 0;
  static double differen_term = 0;
  static double last_err = 0;

  static double P=0.04,I=0.003,D=0.19;

  double increment;
  double err = target - current;

  differen_term = err - last_err;
  last_err = err;
  integral_term += err;

  increment = (P * err) + (I * integral_term) + (D * differen_term);

  return  increment;
}


int main(void)
{
  double  speed = 0;
  double inc = 0;
  for(int i=0; i < 70; ++i)
  {
    inc = calculateAcceleration(speed, 0.4);
    std::cout << "inc: " << inc << "  speed: " << speed << std::endl;
    speed +=inc;
  }
  return 0;
}
