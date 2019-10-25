//Mitchell Desjardins 
// mtdesjardins@myseneca.ca
// Student Number - 059863126

#include "Utilities.h"

namespace sict{
  char Utilities::delimiter = '|';
  size_t Utilities::fieldWidth = 0;

  Utilities::Utilities() {}

  const std::string Utilities::extractToken(const std::string& str, size_t& next_pos){

        std::string token;
        size_t pos = next_pos;
        next_pos = str.find(delimiter, pos);
        if (next_pos != std::string::npos) {
            token = str.substr(pos, next_pos - pos);
            next_pos++;
        }
        else {
            token = str.substr(pos);
        }
        return token;
  }

  const char Utilities::getDelimiter() const{
    return delimiter;
  }

  size_t Utilities::getFieldWidth() const{
    return fieldWidth;
  }

  void Utilities::setDelimiter(const char d){
    delimiter = d;
  }

  void Utilities::setFieldWidth(size_t fw){
    fieldWidth = fw;
  }
}