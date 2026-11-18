#pragma once
#include <iostream>
#include "SmartDevice.h"
class SmartLight : public SmartDevice {
private:
	int brightness;
public:
	void setBrightness(int brightness) {
		if (brightness < 0 || brightness >100) {
			std::cout << "Wrong amount! Please enter a number between 0-100 !!" << std::endl;
		}
		else {
			this->brightness = brightness;
		}
	}
	int getBrightness() {
		return brightness;
	}
	void displayDetails() const override;
	double calculatePowerCost(int hours) const override;
	SmartLight(std::string ID, std::string Name, bool stat, int bright = 0) : SmartDevice(ID, Name, stat), brightness(bright){}
};