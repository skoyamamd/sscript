#include <iostream>
#include <sstream>
#include <vector>
#include <string>

// cpp program to convert plink2 .raw format files
// [compile] cpp -o convert convert.c
// [usege] cat your_raw_file.raw | ./convert > your_output_file
// roughly 3 times faster than awk implementation

int main() {
  std::string line;
  std::vector<std::string> headers;
  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {
      tokens.push_back(token);
    }

    if (tokens.size() < 7) continue;

    if (headers.empty()) {
      for (size_t i = 6; i < tokens.size(); ++i) {
        headers.push_back(tokens[i]);
      }
    } else {
      for (size_t i = 6; i < tokens.size(); ++i) {
        if (tokens[i] != "2" && tokens[i] != "NA") {
          std::cout << tokens[0] << " " << headers[i-6] << " " << tokens[i] << std::endl;
        }
      }
    }
  }
  return 0;
}
