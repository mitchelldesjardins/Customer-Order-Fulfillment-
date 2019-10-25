//Mitchell Desjardins 
// mtdesjardins@myseneca.ca
// Student Number - 059863126

#ifndef Utilities_h
#define Utilities_h

#include <iostream>
#include <string>

namespace sict{
  class Utilities{
    static char delimiter;
    static size_t fieldWidth;
    public:
      Utilities();
      const std::string extractToken(const std::string& str, size_t& next_pos);
      const char getDelimiter() const;
      size_t getFieldWidth() const;
      static void setDelimiter(const char d);
      void setFieldWidth(size_t);
  };
}

#endif