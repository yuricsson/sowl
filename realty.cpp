#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// определение класса Realty
class Realty {
private:
  // Поля класса Realty
  std::string owner;
  std::string registrationDate;
  int estimatedCost = -1;

public:

  // Конструктор, принимающий строку с описанием объекта
  Realty(const std::string &description) {
    std::istringstream stream(description);
    while(!stream.eof()) {
      std::string tmp_str;
      stream >> tmp_str;
      if (tmp_str[0] == '"') {
        owner = tmp_str.erase(0, 1);;
        stream >> tmp_str;
        owner += ' ' + tmp_str.erase(tmp_str.size()-1, 1);
      } else if (tmp_str.find('.') != std::string::npos) {
        registrationDate = tmp_str;
      } else if (!tmp_str.empty()){
        estimatedCost = std::stoi(tmp_str);
      }
    }
  }
  // Метод для вывода информации о недвижимости
  void printInfo() const {
    std::cout << "Owner:              " << owner << std::endl;
    std::cout << "Registration Date:  " << registrationDate << std::endl;
    std::cout << "Estimated Cost:     " << estimatedCost << " ₽" << std::endl;
  }
};

int main() {
  // Тесты
  std::string filename = "test_data.txt";
  std::string inputDescription;
  std::ifstream in(filename);
  if (in.is_open()) {

    while (std::getline(in, inputDescription)) {
      // Создание экземпляра класса
      Realty property(inputDescription);
      // Вывод информации о недвижимостиcout
      property.printInfo();
      std::cout << std::endl;
    }
  } 
  else 
  {
    std::cout << "File does not open" << std::endl;
  }
  
  in.close();
  return 0;
}
