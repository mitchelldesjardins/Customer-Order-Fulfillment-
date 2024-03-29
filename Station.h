//Mitchell Desjardins 
// mtdesjardins@myseneca.ca
// Student Number - 059863126

#ifndef SICT_STATION_H
#define SICT_STATION_H

#include <queue>
#include <iostream>
#include <string>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict
{
	class Station	{
		std::deque<CustomerOrder> m_stationCustomerOrders;
		std::string m_stationName;
		ItemSet m_stationInventory;
	public:
		explicit Station(const std::string&);
		Station(const Station&) = delete;
		Station& operator=(const Station&) = delete;
		Station(Station&&) = delete;
		Station& operator=(Station&&) = delete;
		void display(std::ostream&) const;
		void fill(std::ostream&);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;
	};
}

#endif