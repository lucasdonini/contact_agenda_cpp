#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "StringUtils.hpp"

std::string StringUtils::trim(const std::string& str) {
  std::regex regex("^\\s+|\\s+$");
  return std::regex_replace(str, regex, "");
}

void StringUtils::split(const std::string& str, char sep, std::vector<std::string>& out) {
  std::stringstream ss(str);
  std::string e;

  while (std::getline(ss, e, sep)) {
    e = trim(e);
    out.push_back(e);
  }
}