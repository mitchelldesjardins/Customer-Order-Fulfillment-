//Mitchell Desjardins 
// mtdesjardins@myseneca.ca
// Student Number - 059863126

#ifndef SICT_LINEMANAGER_H
#define SICT_LINEMANAGER_H

#include <vector>
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sict
{
	class LineManager{
		std::vector<Station*> m_stationAddresses;
		std::deque<CustomerOrder> m_complete;
		std::deque<CustomerOrder> m_incomplete;
		std::deque<CustomerOrder> m_ordersToFill;
		std::vector<size_t> m_indexNextStation;
		size_t m_indexStartingStation;
		size_t m_indexLastStation;
		size_t m_orderSize;
		std::vector<size_t> m_stationOrder;
	public:
		LineManager(std::vector<Station*>&, std::vector<size_t>&, std::vector<CustomerOrder>&, size_t, std::ostream&);
		void display(std::ostream&) const;
		bool run(std::ostream&);
	private:
		size_t createAssemblyOrder(std::vector<size_t>&, size_t);
	};
}

#endif