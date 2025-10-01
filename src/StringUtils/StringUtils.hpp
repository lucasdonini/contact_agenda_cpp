#include <string>
#include <vector>

class StringUtils {
public:
  static void split(const std::string& str, char sep, std::vector<std::string>& out);
  static std::string trim(const std::string& str);
};