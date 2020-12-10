#include <iostream>
#include <cmath>

double mysqrt(double inputValue)
{
#if defined(HAVE_LOG) && defined(HAVE_EXP)
  double result = exp(log(inputValue) * 0.5);
  std::cout << "Computing sqrt of " << inputValue << " to be " << result << " using log & exp" << std::endl;
#else
  double result = inputValue + 1;
#endif
  return result;
}
