#pragma once
#include <iostream>
#include "SmartDevice.h"
class SmartAC :public SmartDevice {
private:
	int temp;
public:
	void setTemperatureC(double temp) {
		this->temp = temp;
	}
	int getTemperature() {
		return temp;
	}
	double calculatePowerCost(int hours) const override;
	void displayDetails() const override;
	SmartAC(std::string ID, std::string Name, bool stat, int Temp) : SmartDevice(ID, Name, stat), temp(Temp) {}
};