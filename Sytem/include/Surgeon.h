//Mostafa Raafat Kamal 20236094
//Moneer Magdy Shaaban 20236103
#pragma once
#include <iostream>
#include <string>
#include "Doctor.h"
class Surgeon : public Doctor
{
private:
	int numSurgeriesScheduled;
	surgerySchedule* array_;
public:
	//default constructor
	Surgeon() {
		numSurgeriesScheduled = 0;
		array_ = new surgerySchedule[numSurgeriesScheduled];
	}
	// parametrized constructor
	Surgeon(int n, string _name, string _id, int _duration, double _rate, surgerySchedule* sch) : Doctor(_id, _name, _duration, _rate) { // calling Doctor function
		numSurgeriesScheduled = n;
		array_ = new surgerySchedule[numSurgeriesScheduled];
		//copying array of surgeries
		for(int  i = 0 ; i < numSurgeriesScheduled; i ++){
            array_[i] = sch[i];
		}
	}
	//copy constructor
	Surgeon(const Surgeon & right) {
		numSurgeriesScheduled = right.numSurgeriesScheduled;
		for (int i = 0; i < numSurgeriesScheduled; i++)
		{
			right.array_[i] = array_[i];
		}
	}
	// destructor
	~Surgeon() {
		delete[] array_;
	}
	// overriding fee function
	double calculateTotalFee() {
        return (duration / 60.0) * rate; // cost per quarter hour
    }
	//overrindiing prettyprint function
	string PrettyPrint() {
		return "Dr. " + name + " is a surgeon with total fee is " + to_string(calculateTotalFee()) ; // to_string function is used to convert double to string
	}
	// printing Surgeries
	void printSurgeries() {
		for (int i = 0; i < numSurgeriesScheduled; i++)
		{
			cout << "Surgery " << i + 1 << endl;
			cout << "Patient name : " << array_[i].getPatientName() << endl;
			cout << "Surgery date : " << array_[i].getDate();
		}
	}


};

