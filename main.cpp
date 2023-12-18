#include "realty.h"

int main() {
  std::string filename = "test_data.txt";
  std::vector<Realty> data = load_data_from_file(filename);
  for (unsigned int i = 0; i < (unsigned int)data.size(); i++) {
    data[i].printInfo();
    std::cout << std::endl;
  }
  return 0;
}
