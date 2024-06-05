#pragma once

#ifndef __NURSE_H
#define __NURSE_H
#include "Worker.h"
#include "Patient.h"
class Nurse : public Worker
{
private:

	Patient** patientsGotCare;
	int numOfPatientsGotCare;

public:
	Nurse();
	bool addPatient(const Patient* patient);
	bool callDoctor(const Doctor* Doctor);
	Patient** getPatientsGotCare() const;
	void printNurse() const;
	int getNumOfPatientsGotCare()const;
	~Nurse();
};

#endif // __NURSE_H

