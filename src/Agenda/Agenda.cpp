#include <algorithm>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "../Contact/Contact.hpp"
#include "../StringUtils/StringUtils.hpp"
#include "Agenda.hpp"

Agenda::Agenda(const std::string& filePath) : filePath(filePath) {}

std::vector<Contact>::iterator Agenda::iteratorOf(const std::string& name) {
  return std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
    return c.getName() == name;
  });
}

std::vector<Contact>::const_iterator Agenda::iteratorOf(const std::string& name) const {
  return std::find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {
    return c.getName() == name;
  });
}

void Agenda::load() {
  std::ifstream csv(filePath);
  std::string line;

  if (!csv.is_open()) {
    throw std::runtime_error("Não foi possível ler o arquivo " + filePath);
  }

  while (std::getline(csv, line)) {
    std::vector<std::string> sepLine;
    StringUtils::split(line, ',', sepLine);

    if (sepLine.size() != 3) {
      throw std::invalid_argument("Arquivo malformatado. O arquivo .csv deve conter 3 colunas");
    }

    Contact c(sepLine.at(0), sepLine.at(1), sepLine.at(2));
    contacts.push_back(c);
  }
}

void Agenda::save() const {
  std::ofstream csv(filePath);

  if (!csv.is_open()) {
    throw std::runtime_error("Não foi possível gravar no arquivo " + filePath);
  }

  for (const Contact& c : contacts) {
    std::string line = c.toCSV();
    csv << line << std::endl;
  }
}

void Agenda::add(const Contact& c) {
  auto it = iteratorOf(c.getName());

  if (it != contacts.end()) {
    *it = c;

  } else {
    contacts.push_back(c);
  }
}

void Agenda::printAgenda() const {
  for (const Contact& c : contacts) {
    std::cout << c.toString() << std::endl;
  }
}

void Agenda::remove(const std::string& name) {
  auto it = iteratorOf(name);

  if (it != contacts.end()) {
    contacts.erase(it);
  }
}

std::optional<Contact> Agenda::findContactByName(const std::string& name) const {
  auto it = iteratorOf(name);

  if (it == contacts.end()) {
    return std::nullopt;
  }

  return *it;
}

bool Agenda::empty() const {
  return contacts.empty();
}
