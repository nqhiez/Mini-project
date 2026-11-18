#include <iostream>
#include "SmartLight.h"
using namespace std;
void SmartLight::displayDetails() const {
	cout << "ID: " << id << endl << "Name: " << name << endl << "Status: " << getIsOn() << endl << "Brightness(%): " << brightness << endl;
}
double SmartLight::calculatePowerCost(int hours) const {
	return (hours * 0.015 * (brightness / 100.0) * 3000);
}