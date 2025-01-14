//Mostafa Raafat Kamal 20236094
//Moneer Magdy Shaaban 20236103
#include <iostream>
#include "Doctor.h"
#include "Surgeon.h"
#include <string>
#include <fstream>
#include <typeinfo> // this library is used for typeid function
using namespace std;

int main()
{
	int num; // stores num  of doctores u wish to add
	cout << "Enter the number of Doctors u wish to add : ";
	cin >> num;
	cout << endl;
	Doctor* array__[100];
	string type_; // stores the Dr type;
	// following variables stores the attributes of the classes
	string _name;
	string _id;
	int _duration;
	double _rate;
	int numOfSur;
	string _speciality;
	for (int i = 0; i < num; i++)
	{
		cout << "The doctor is specialist or surgeon ? (su) or (sp) : ";
		cin >> type_;
		while(type_ != "su" && type_ != "sp"){
            cout << "Wrong option!! try again !! " << endl;
            cout << "The doctor is specialist or surgeon ? (su) or (sp) : ";
            cin>> type_;
		}
		if (type_ == "su")
		{	// Reading Doctor info from the user
			cout << "Enter the surgeon name : " << endl;
			cin >> _name;
			cout << "Enter the surgeon id : " << endl;
			cin.ignore();
			cin >> _id;
			cout << "Enter the surgeon duration" << endl;
			cin >> _duration;
			cout << "Enter the surgeon rate " << endl;
			cin >> _rate;
			cout << "Enter the number of surgeries " << endl;
			cin >> numOfSur;

			surgerySchedule *schedule = new surgerySchedule[numOfSur];
			string pn; // store patient name
			string sur_date; // store surgery date;

			for(int j = 0 ; j < numOfSur ; j++){
                cout << "Patient " << j+1 << endl;
                cout << "Enter the patient name : " ;
                cin  >> pn;
                cout << "\nEnter Surgery date : " ;
                cin.ignore();
                cin >> sur_date;
                schedule[i].setPatientName(pn);
                schedule[i].setDate(sur_date);
			}
			array__[i] = new Surgeon(numOfSur,_name, _id, _duration, _rate, schedule); // using constructor to intialize each attribute
		}
		else if (type_ == "sp") {
            // Reading Data from the user
			cout << "Enter the specialist name : " << endl;
			cin >> _name;
			cout << "Enter the specialist id : " << endl;
			cin.ignore();
			cin >> _id;
			cout << "Enter the specialist duration" << endl;
			cin >> _duration;
			cout << "Enter the specialist rate " << endl;
			cin >> _rate;
			cout << "Enter the speciality " << endl;
			cin >> _speciality;
			array__[i] =  new Specialist(_id, _name, _duration, _rate, _speciality);

		}
	}
	// file handling
	fstream doctors_;
	doctors_.open("doctors.txt", ios::out);
	if (doctors_.is_open()) {
		for (int i = 0; i < num; i++)
		{
			cout << array__[i]->PrettyPrint() << endl; // Displaying on screen
			doctors_ << array__[i]->PrettyPrint() << endl;; // writing to the output file
			if (typeid(array__[i]) == typeid(Surgeon)) {					//typeid() Function is used to check the type of the looped index to be surgeon or not
				((Surgeon*)array__[i])->printSurgeries(); // typecasting to call the printSurgeries function
			}
		}
	}
	else{
        cout << "File is not opened successfuly \n" ;
	}
	doctors_.close();
}

