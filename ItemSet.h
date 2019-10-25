//Mitchell Desjardins 
// mtdesjardins@myseneca.ca
// Student Number - 059863126

#ifndef ItemSet_h
#define ItemSet_h

#include <string>
#include <iomanip>
#include "Utilities.h"

namespace sict{
  class ItemSet{
    unsigned int itemSerialNumber, itemQuantity;
    std::string itemName, itemDescription;
    Utilities utility;
    public:
      ItemSet(const std::string&);
      const std::string& getName() const { return itemName;}
      const unsigned int getSerialNumber() const {return itemSerialNumber;}
      const unsigned int getQuantity() const { return itemQuantity;}
      ItemSet& operator--();
      void display(std::ostream& os, bool full = true) const;
      ItemSet(const ItemSet&) = delete;
      ItemSet& operator=(const ItemSet&) = delete;
      ItemSet(ItemSet&&);
      ItemSet& operator=(const ItemSet&&) = delete;
  };
}

#endif