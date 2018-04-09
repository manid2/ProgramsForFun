#ifndef CONSUMER_H
#define CONSUMER_H

#include <string>
#include <algorithm>
#include "producer.h"

class Consumer {
public:
	Consumer(Producer * p): producer(p){}
	int countLevelOfDomain(const std::string & url) const {
		std::string domain = producer->getDomainFromUrl(url);
		return std::count(domain.begin(), domain.end(), '.') + 1;
	}
private:
	Producer * producer;
};

#endif /*CONSUMER_H*/
