//Mitchell Desjardins 
// mtdesjardins@myseneca.ca
// Student Number - 059863126

#include "ItemSet.h"

namespace sict{
  ItemSet::ItemSet(const std::string& str){
    std::size_t pos = 0;
    itemName = utility.extractToken(str, pos);
    itemSerialNumber = std::stoul(utility.extractToken(str, pos));
    itemQuantity = std::stoul(utility.extractToken(str, pos));
    itemDescription = utility.extractToken(str, pos);
    utility.setFieldWidth(itemName.length());
  }

  ItemSet& ItemSet::operator--(){
    itemQuantity--;
    itemSerialNumber++;
    return *this;
  }

  ItemSet::ItemSet(ItemSet&& src){
    if(this != &src){
      itemQuantity = src.itemQuantity;
      itemName = src.itemName;
      itemDescription = src.itemDescription;
      itemSerialNumber = src.itemSerialNumber;

      src.itemSerialNumber = 0;
      src.itemName = "";
      src.itemDescription = "";
      src.itemQuantity = 0;
    }
  }

  void ItemSet::display(std::ostream& os, bool full) const{
    size_t fieldWidth = utility.getFieldWidth();

		if(full)
			os << std::left << std::setw(fieldWidth) << itemName << " [" << std::setw(5) << itemSerialNumber << "] Quantity " << std::setw(3) << itemQuantity << std::right<< " Description: " << itemDescription << std::endl;
    else
     	os << std::left << std::setw(fieldWidth) << itemName << ' ' << std::setw(5) << itemSerialNumber << std::endl; 
  }
}