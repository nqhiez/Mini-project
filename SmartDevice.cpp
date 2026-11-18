#include <iostream>
#include "SmartDevice.h"
using namespace std;
void SmartDevice::togglePower() {
	if (isOn == false) {
		isOn = true;
	}
	else {
		isOn = false;
	}
}
string SmartDevice::getName() const {
	return name;
}
string SmartDevice::getId() const {
	return id;
}
string SmartDevice::getIsOn() const {
	if (isOn == false) {
		return "Off";
	}
	else {
		return "On";
	}
}
bool SmartDevice::operator==(const SmartDevice& device) const {
	if (id == device.id) {
		return true;
	}
	else {
		return false;
	}
}
ostream& operator<<(ostream& os, SmartDevice& device) {
	device.displayDetails();
	return os;
}