#include "realty.h"

// Конструктор класса Date, принимающий дату в виде строки
Date::Date(const std::string &Date_string) {
  // Создаем строковый поток stream
  std::istringstream stream(Date_string);
  enum { YEAR, MONTH, DAY };
  char c;
  int num, read_counter = 0; // Считанное число, и его порядок
  while (stream >> num) {
    if (num > 0) {
      switch (read_counter) {
      case YEAR:
        year = num;
        break;
      case MONTH:
        month = num;
        break;
      case DAY:
        day = num;
        break;
      }
      stream >> c; // считываем разделитель
      read_counter++;
    }
  }
  // Проверка на корректность данных
  if (year > 2024) {
    year = -1;
  }
  if (month > 12) {
    month = -1;
  }
  if (day > 30) {
    day = -1;
  }
}

// Метод для вывода всех полей класса Date
void Date::Print_Date() const {
  std::cout.width(2);
  std::cout << year << '.' << std::setw(2) << std::setfill('0') << month << '.'
            << std::setw(2) << std::setfill('0') << day << std::endl;
}

// Конструктор класса Reaalty, принимающий строку с описанием объекта
Realty::Realty(const std::string &description) {
  if (count_words(description) > 4) {
    throw std::exception();
  } else {
    // Создаем строковый поток stream
    std::istringstream stream(description);
    std::string tmp_str;
    // ОБрабатываем данные с потока в цикле
    while (stream >> tmp_str) {
      // Если встретился символ двойных ковычек, устанавливаем собственника
      if (tmp_str[0] == '"') {
        SetOwner(&tmp_str, &stream);
        // Ищем в tmp_str '.' (в случае отсутствия возвращается npos), если
        // есть, то устанавливаем дату
      } else if (tmp_str.find('.') != std::string::npos) {
        registrationDate = Date(tmp_str);
        // Иначе устанавливаем стоимость (при условии что строка не пуста)
      } else if (!tmp_str.empty()) {
        SetCost(tmp_str);
      }
    }
  }
}

// Функция для подсчета слов во входной строке описания недвижимости
int Realty::count_words(const std::string &description) {
  int counter = 0;
  std::istringstream stream(description);
  std::string tmp_str;
  while (stream >> tmp_str) {
    counter++;
  }
  return counter;
}

// Функция для установки стоимости
void Realty::SetCost(std::string &Cost) {
  try {
    estimatedCost = std::stoi(Cost);
  } catch (const std::invalid_argument &e) {
    std::cerr
        << "!!! Error reading Estimated cost data, the data was assigned: ";
    estimatedCost = -1;
    std::cerr << estimatedCost << std::endl;
  }
}

// Функция предназначена для установки собственника из конструктора с
// параметрами
void Realty::SetOwner(std::string *Owner, std::istringstream *Stream) {
  // Удаляем символ двойных ковычек из начала стркои '"'
  Owner->erase(0, 1);
  int counter = 1;
  do {
    owner += *Owner + ' ';
    *Stream >> *Owner;
    counter++;
  } while (Owner->back() != '"');
  // Проверяем количество слов
  if (counter > 2) {
    std::cout << "Too many arguments in field Name: " << counter << std::endl;
    owner.erase(owner.begin(), owner.end());
    owner = "Error input";
  } else {
    owner += *Owner;
    // Удаляем символ ковычек из конца строки
    owner.erase(owner.size() - 1, 1);
  }
}

// Функция для вывода информации о недвижимости
void Realty::PrintInfo() const {
  std::cout << "Owner:              " << owner << std::endl;
  std::cout << "Registration Date:  ";
  registrationDate.Print_Date();
  std::cout << "Estimated Cost:     " << estimatedCost << " ₽" << std::endl;
}

// Создать коллекцию объектов из файла
std::vector<Realty> Load_data_from_file(std::string filename) {
  std::string line;
  std::ifstream in(filename);
  std::vector<Realty> data;
  if (in.is_open()) {
    while (std::getline(in, line)) {
      try {
        data.push_back(Realty(line));
      } catch (const std::exception &e) {
        std::cerr << "Too many arguments in line" << std::endl;
      }
    }
  } else {
    std::cout << "File doesn't open" << std::endl;
  }
  in.close();
  return data;
}
