#include <iostream>
#include <string>
#include "SmartAC.h"
using namespace std;
double SmartAC::calculatePowerCost(int hours) const {
	return (hours * 1.2 * 3000);
}
void SmartAC::displayDetails() const {
	cout << "ID: " << id << endl << "Name: " << name << endl << "Status: " << getIsOn() << endl << "Temperature(C): " << temp << endl;
}
string SmartAC::getExtra() const { return to_string(temp); }