#ifndef OBSERVER_HPP
#define OBSERVER_HPP


class Observer {
public:
	virtual void notify(int what, void* data, int size) = 0;

};


#endif 