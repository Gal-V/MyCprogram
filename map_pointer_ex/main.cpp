#include <map>
#include <string>
#include <iostream>

int main() {
  std::map<int, std::string> * mapping = new std::map<int, std::string>();
  (*mapping)[1] = "test";
  std::cout << (*mapping)[1] <<std::endl;
}