#include "realty.h"

// Конструктор, принимающий строку с описанием объекта
Realty::Realty(const std::string &description) {
  std::istringstream stream(description);
  while (!stream.eof()) {
    std::string tmp_str;
    stream >> tmp_str;
    if (tmp_str[0] == '"') {
      owner = tmp_str.erase(0, 1);
      stream >> tmp_str;
      owner += ' ' + tmp_str.erase(tmp_str.size() - 1, 1);
    } else if (tmp_str.find('.') != std::string::npos) {
      registrationDate = tmp_str;
    } else if (!tmp_str.empty()) {
      estimatedCost = std::stoi(tmp_str);
    }
  }
}

// Функция для вывода информации о недвижимости
void Realty::printInfo() const {
  std::cout << "Owner:              " << owner << std::endl;
  std::cout << "Registration Date:  " << registrationDate << std::endl;
  std::cout << "Estimated Cost:     " << estimatedCost << " ₽" << std::endl;
}

// Создать коллекцию объектов из файла
std::vector<Realty> load_data_from_file(std::string filename) {
  std::string line;
  std::ifstream in(filename);
  std::vector<Realty> data;
  if (in.is_open()) {
    while (std::getline(in, line)) {
      data.push_back(Realty(line));
    }
  } else {
    std::cout << "File doesn't open" << std::endl;
  }
  in.close();
  return data;
}
