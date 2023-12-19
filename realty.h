#ifndef REALTY_H
#define REALTY_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Date {
private:
  int year;
  int month;
  int day;

public:
  // Конструктор принимающий параметром строку
  // Значение полей по умолчанию -1 (=> дата не установлена)
  Date(const std::string &Date_string = "-1.-1.-1");
  // Функция для вывода даты
  void Print_Date() const;
};

class Realty {
private:
  std::string owner;
  Date registrationDate;
  int estimatedCost;
  void SetOwner(std::string *Owner, std::istringstream *Stream);
  void SetCost(std::string &Cost);
  // Функция для подсчета слов во входной строке описания недвижимости
  int count_words(const std::string &description);

public:
  // Конструктор, принимающий строку с описанием объекта
  Realty(const std::string &description);
  // Функция для вывода информации о недвижимости
  void PrintInfo() const;
};

/**
 * @brief Функция построчно парсит файл в коллекцию объектов
 * (1 строка = 1 объект)
 *
 * @param filename
 * @return std::vector<Realty>
 */
std::vector<Realty> Load_data_from_file(std::string filename);

#endif
