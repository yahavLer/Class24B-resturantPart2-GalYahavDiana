#pragma once

#ifndef __CAFETERIA_H
#define __CAFETERIA_H
#include "Building.h"
#include "CafeteriaWorker.h"

class Cafeteria : public Building
{
private:
	CafeteriaWorker** cafeteriaWorkers;
	int numOfcafeteriaWorkers;

public:
	Cafeteria();
	bool addWorker(const Worker* worker);
	bool fireWorker(const Worker* worker);
	bool setNameOfCafeteria(const char* nameOfCafeteria);
	char* getNameOfCafeteria() const;
	CafeteriaWorker** getCafeteriaWorkers() const;
	int getNumOfcafeteriaWorkers();
	void printCafeteria()const;
	~Cafeteria();
};

#endif // __CAFETERIA_H

