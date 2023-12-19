#include "realty.h"

int main() {
  std::string filename = "test_data.txt";
  std::vector<Realty> data = load_data_from_file(filename);
  for (Realty line : data) {
    line.printInfo();
    std::cout << std::endl;
  }
  return 0;
}
