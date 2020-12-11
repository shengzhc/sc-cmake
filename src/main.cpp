#include <iostream>
#include <string>

#include "MathFunctions.h"
#include "Config.h"

int main(int argc, char *argv[])
{
  //Version Configuration test
  if (argc < 2) {
    std::cout << "Printing Versions ------" << std::endl;
    std::cout << argv[0] << " Version " << SC_CMAKE_VERSION_MAJOR << "." << SC_CMAKE_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
  }

  // stod dependency test
  if (argc > 1) {
    std::cout << "Printing inputValue -----" << std::endl;
    const double inputValue = std::stod(argv[1]);
    std::cout << inputValue << std::endl;
  }

  // sub-library test
  if (argc > 1) {
    const double inputValue = std::stod(argv[1]);
    const double outputValue = mathfunctions::sqrt(inputValue);
    std::cout << "Printing square -----" << std::endl;
    std::cout << inputValue << " is " << outputValue << std::endl;
  }

  return 0;
}
