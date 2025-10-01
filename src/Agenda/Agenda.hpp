#pragma once

#include <optional>
#include <string>
#include <vector>

#include "../Contact/Contact.hpp"

class Agenda {
private:
  std::vector<Contact> contacts;
  std::string filePath;
  std::vector<Contact>::iterator iteratorOf(const std::string& name);
  std::vector<Contact>::const_iterator iteratorOf(const std::string& name) const;

public:
  Agenda(const std::string& filePath);
  void load();
  void save() const;
  void add(const Contact& c);
  void printAgenda() const;
  void remove(const std::string& name);
  std::optional<Contact> findContactByName(const std::string& name) const;
  bool empty() const;
};