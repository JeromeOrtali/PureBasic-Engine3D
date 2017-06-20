#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <algorithm>
#include <vector>
#include "Observer.hpp"

class Subject {
public:

	void notifyObservers(int what, void* data, int size) const;
	
	void attachObserver(Observer* observer);

	void removeObserver(Observer* observer);

private:
	std::vector<Observer*>	m_observer;

};

#endif // !SUBJECT_HPP
