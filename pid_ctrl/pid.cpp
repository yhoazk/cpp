#include <iostream>



double calculateAcceleration(double current, double target)
{
  static double integral_term = 0;
  static double differen_term = 0;
  static double last_err = 0;

  static double P=0.015,I=0.000003,D=0.00019; // TODO: Make a class of controller and add a auto-tunning method.

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
  for(int i=0; i < 490; ++i)
  {
    inc = calculateAcceleration(speed, 40.0f);
    std::cout << i << ", " << speed << std::endl;
    speed +=inc;
  }
  return 0;
}
