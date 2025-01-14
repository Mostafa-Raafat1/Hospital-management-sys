//Mostafa Raafat Kamal 20236094
//Moneer Magdy Shaaban 20236103
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Doctor {
protected:
    string id;
    string name;
    int duration; //  number of minutes with patients
    double rate;

public:
    // Default
    Doctor() : id(""), name(""), duration(0), rate(0.0) {}

    // Parameterized
    Doctor(string _id, string _name, int _duration, double _rate)
    {
        id = _id;
        name = _name;
        duration = _duration;
        rate = _rate;
    }
    virtual double calculateTotalFee() {
        return (duration / 60.0) * rate; // presenting the time in hours then calc the cost per hour
    }
    virtual string PrettyPrint() {
        return "Doctor ID is : " + id + ", and name is " + name;
    }
    ~Doctor() {}
};
class surgerySchedule {
private:
    string patientname;
    string Date;
public:

    surgerySchedule() : patientname(""), Date("") {} // Default
    surgerySchedule(string patient_name, string _Date) :patientname(patient_name), Date(_Date) {} //Parameterized

    void setPatientName(string patient_Name) {
        patientname = patient_Name;
    }
    string getPatientName() {
        return patientname;
    }// Setter and getter for patientname


    void setDate(string _Date) {
        Date = _Date;
    }


    string getDate() {
        return Date;
    }// Setter and getter for Date
};
class Specialist : public Doctor {
private:
    string speciality;

public:
    // Default
    Specialist() : Doctor(), speciality("") {}

    // Parameterized
    Specialist(string _id, string _name, int _duration, double _rate, string _speciality)
        : Doctor(_id, _name, _duration, _rate), speciality(_speciality) {}

    // Override calculateTotalFee()
     double calculateTotalFee() {
        return (duration / 15.0) * rate; // cost per quarter hour
    }

    // Override PrettyPrint()
    string PrettyPrint() {
        return "Dr. " + name + " is a Specialist with total fee is " + to_string(calculateTotalFee()) + "."; //to_string function is used to convert double to string
    }
};
