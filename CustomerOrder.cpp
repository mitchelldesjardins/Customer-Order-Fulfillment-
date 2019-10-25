//Mitchell Desjardins 
// mtdesjardins@myseneca.ca
// Student Number - 059863126

#include "CustomerOrder.h"

namespace sict{
  size_t CustomerOrder::fieldWidth = 0;

CustomerOrder::CustomerOrder() : customerName(""), productName(""), items(nullptr), numOfItems(0){}

CustomerOrder::CustomerOrder(const std::string& str){
  Utilities utility;
  size_t pos = 0;
  fieldWidth = utility.getFieldWidth();
  customerName = utility.extractToken(str, pos);
  productName = utility.extractToken(str, pos);
  numOfItems = std::count(str.begin(), str.end(), utility.getDelimiter()) - 1;
  items = new ItemInfo[numOfItems];
    if(numOfItems == 0)
      throw "not enough items";
    else
      for(int i = 0; i < numOfItems; i++)
        items[i].itemName = utility.extractToken(str, pos);
  }

CustomerOrder::~CustomerOrder(){
    delete [] items;
    items = nullptr;
  }

void CustomerOrder::fillItem(sict::ItemSet& item, std::ostream& os){
  for(size_t i = 0; i < numOfItems; i++){
    if(item.getName() == items[i].itemName){
      if(item.getQuantity() == 0)
        os << " Unable to fill " << getNameProduct() << '[' << items[i].itemName << "][" << 0 << "] out of stock\n";
         else{
          if(items[i].itemFilled)
            os << " Unable to fill " << getNameProduct() << '[' << items[i].itemName << "][" << items[i].itemSerialNumber << "] already filled\n";

          else{
            items[i].itemSerialNumber = item.getSerialNumber();
            items[i].itemFilled = true;
            item.operator--();
            os << " Filled " << getNameProduct() << '[' << items[i].itemName << "][" << items[i].itemSerialNumber << "]\n";
          }
        }
      }
    }
  }

bool CustomerOrder::isFilled() const{
  	for(size_t i = 0; i < numOfItems; i++)
		if(!items[i].itemFilled)
			return false;
	return true;
  }

bool CustomerOrder::isItemFilled(const std::string& item) const{
  	for(size_t i = 0; i < numOfItems; i++){
		if(items[i].itemName == item)
			if(!items[i].itemFilled)
				return false;
	}
	return true;
  }

std::string CustomerOrder::getNameProduct() const{
  	return std::string(customerName + " [" + productName + "]");
  }

void CustomerOrder::display(std::ostream& os, bool showDetail) const{
		os << std::left << std::setw(fieldWidth) << customerName << " [" << productName << "]\n";
		if(showDetail)
		for (size_t i = 0; i < numOfItems; ++i)
				os << std::setfill(' ') << std::setw(fieldWidth + 1) << ' '<< '[' << (items[i].itemFilled == true ? items[i].itemSerialNumber : 0)  << "] " << items[i].itemName << " - " << (items[i].itemFilled == true ? "FILLED" : "MISSING") << '\n';
    else
      for(int i = 0; i < numOfItems; i++)
        os << std::setfill(' ') << std::setw(fieldWidth + 1) << ' ' << std::setw(fieldWidth) << std::left << items[i].itemName << '\n';  	
  }


  
CustomerOrder::CustomerOrder(CustomerOrder&& src){
	*this = std::move(src);
}

CustomerOrder & CustomerOrder::operator=(CustomerOrder&& src){
	if (this != &src){
		customerName = src.customerName;
		productName = src.productName;
		numOfItems = src.numOfItems;
		items = src.items;
		src.items = nullptr;
		}
	return *this;
}

}
