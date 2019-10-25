//Mitchell Desjardins 
// mtdesjardins@myseneca.ca
// Student Number - 059863126

#ifndef CustomerOrder_h
#define CustomerOrder_h

#include <iostream>
#include <string>
#include <algorithm>
#include "Utilities.h"
#include "ItemSet.h"

namespace sict{
  class CustomerOrder{
    std::string customerName;
    std::string productName;
    int numOfItems;
    static size_t fieldWidth;
    struct ItemInfo{
      std::string itemName;
      int itemSerialNumber;
      bool itemFilled;
    };
    ItemInfo* items;
    public:
      CustomerOrder();
      CustomerOrder(const std::string&);
      ~CustomerOrder();
      CustomerOrder(const CustomerOrder&) = delete;
      CustomerOrder& operator=(const CustomerOrder&) = delete;
      CustomerOrder(CustomerOrder&&);
      CustomerOrder& operator=(CustomerOrder&&);
      void fillItem(ItemSet&, std::ostream& os);
      bool isFilled() const;
      bool isItemFilled(const std::string&) const;
      std::string getNameProduct() const;
      void display(std::ostream&, bool showDetail = false) const;
  };
}

#endif
