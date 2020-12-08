#include <iostream>
#include <string>
#include "Config.h"
#ifdef USE_MYMATH
  #include "MathFunctions.h"
#endif


int main(int argc, char *argv[])
{
  //Version Configuration test
  if (argc < 2) {
    std::cout << "Printing Versions ------" << std::endl;
    std::cout << argv[0] << " Version " << SC_CMAKE_VERSION_MAJOR << "." << SC_CMAKE_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
  }

  // stod dependency test
  if (argc > 0) {
    std::cout << "Printing inputValue -----" << std::endl;
    const double inputValue = std::stod(argv[1]);
    std::cout << inputValue << std::endl;
  }

  // sub-library test
  const double inputValue = std::stod(argv[1]);
#ifdef USE_MYMATH
  const double outputValue = mysqrt(inputValue);
#else
  const double outputValue = sqrt(inputValue);
#endif
  std::cout << "Printing square of inputValue -----" << std::endl;
  std::cout << outputValue << std::endl;

  return 1;
}
