#pragma once

#include <string>

class Contact {
private:
  std::string name;
  std::string phone;
  std::string email;

public:
  Contact(const std::string& name, const std::string& phone, const std::string& email);
  Contact();
  std::string getName() const;
  std::string getPhone() const;
  std::string getEmail() const;
  std::string toCSV() const;
  std::string toString() const;
};