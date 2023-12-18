#ifndef REALTY_H
#define REALTY_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Realty {
private:
  std::string owner;
  std::string registrationDate;
  int estimatedCost;

public:
  // Конструктор, принимающий строку с описанием объекта
  Realty(const std::string &description);
  // Функция для вывода информации о недвижимости
  void printInfo() const;
};

/**
 * @brief Функция построчно парсит файл в коллекцию объектов
 * (1 строка = 1 объект)
 *
 * @param filename
 * @return std::vector<Realty>
 */
std::vector<Realty> load_data_from_file(std::string filename);

#endif
