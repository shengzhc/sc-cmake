#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
// Version Configuration
//  if (argc < 2) {
//    std::cout << argv[0] << " Version " << SC_CMAKE_VERSION_MAJOR << "." << SC_CMAKE_VERSION_MINOR << std::endl;
//    std::cout << "Usage: " << argv[0] << " number" << std::endl;
//    return 1;
//  }

  if (argc > 0) {
    const double inputValue = std::stod(argv[1]);
    std::cout << inputValue << std::endl;
    return 1;
  }

  return -1;
}
