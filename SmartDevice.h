#pragma once
#include <iostream>
class SmartDevice {
protected:
	std::string id;
	std::string name;
	bool isOn;
	friend std::ostream& operator<<(std::ostream& os, SmartDevice& device);
public:
	virtual ~SmartDevice() = default;
	virtual void displayDetails() const = 0;
	virtual double calculatePowerCost(int hours) const = 0;
	void togglePower();
	std::string getId() const;
	std::string getIsOn() const;
	bool operator==(const SmartDevice& device) const;
	SmartDevice(std::string ID, std::string Name, bool stat = false) :id(ID), name(Name), isOn(stat) {}
};