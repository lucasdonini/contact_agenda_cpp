#include <format>
#include <string>

#include "Contact.hpp"

Contact::Contact(const std::string& name, const std::string& phone, const std::string& email)
    : name(name), phone(phone), email(email) {}

Contact::Contact() {}

std::string Contact::getName() const {
  return name;
}

std::string Contact::getEmail() const {
  return email;
}

std::string Contact::getPhone() const {
  return phone;
}

std::string Contact::toCSV() const {
  std::string csv = format("{}, {}, {}", name, phone, email);
  return csv;
}

std::string Contact::toString() const {
  std::string str = format("{} | phone: {}; email: {}", name, phone, email);
  return str;
}