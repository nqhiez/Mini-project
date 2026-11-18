#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "SmartAC.h"
#include "SmartLight.h"
using namespace std;
vector<unique_ptr<SmartDevice>> devices;
void Add(vector<unique_ptr<SmartDevice>>& d);
void list(vector<unique_ptr<SmartDevice>>& d);
void toggle(string ID);
void save(vector<unique_ptr<SmartDevice>>& d);
void upload(vector<unique_ptr<SmartDevice>>& d);
int main() {
	bool menu = true;
	int func;
	while (menu) {
		cout <<endl<< "------|Smart Devices Manager|------" << endl << "Welcome back! What do you want?" << endl;
		cout << "1. Add devices\n2. Show devices list\n3. Toggle device\n4. Save devices file\n5. Upload devices file\n6. Leave\n";
		cout << "Press a number: ";
		cin >> func; cin.ignore();
		switch (func) {
		case 1: Add(devices); break;
		case 2: list(devices); break;
		case 3: {
			string id;
			cout << "Enter device ID to toggle: ";
			cin >> id; cin.ignore();
			toggle(id);
			break;
		}
		case 4: save(devices); break;
		case 5: upload(devices); break;
		case 6: cout << "Leaving the program..." << endl;
			menu = false; break;
		default:
			cout << "Incorrect number! Try again!\n";
			break;
		}
	}
}
void Add(vector<unique_ptr<SmartDevice>> &d) {
	string id;
	string name;
	bool status;
	int type;
	cout << "Enter device information:"<<endl;
	cout << "ID: "; cin >> id; cin.ignore();
	cout << "Name: "; getline(cin, name);
	cout << "Status: 0. Off || 1. On ===== Enter: "; cin >> status; cin.ignore();
	cout << "Type: 1.Light || 2.AC === Enter: "; cin >> type; cin.ignore();
	if (type == 1) {
		int bright;
		cout << "Brightness: "; cin >> bright; cin.ignore();
		d.push_back(make_unique<SmartLight>(id, name, status, bright));
	}
	else if (type == 2) {
		int temp;
		cout << "Temperature: "; cin >> temp; cin.ignore();
		d.push_back(make_unique<SmartAC>(id, name, status, temp));
	}
	else {
		cout << "Incorrect type! Try again!" << endl;
		return;
	}
	cout << "Device added successfully!" << endl;
}
void list(vector<unique_ptr<SmartDevice>> &d) {
	double totalCost = 0;
	for (const unique_ptr<SmartDevice>& dec : d) {
		cout << "--------------------" << endl;
		dec->displayDetails();
		if (dec->getIsOn() == "On") {
			totalCost += dec->calculatePowerCost(5);
		}
	}
	cout << "--------------------" << endl << "Total devices: " << d.size() << endl<< "Estimated electricity cost if run for 5 hours: "<< totalCost << endl;
}
void toggle(string ID) {
	for (const unique_ptr<SmartDevice>& dec : devices) {
		if (dec->getId() == ID) {
			dec->togglePower();
			cout << "Device toggled successfully!" << endl;
			return;
		}
	}
	cout << "Device not found!" << endl;
}
void save(vector<unique_ptr<SmartDevice>> &d) {
	ofstream saveFile("Devices.txt");
	for (const unique_ptr<SmartDevice>& dec : d) {
		saveFile<< dec->getType() << "|" << dec->getId() << "|" << dec->getName() << "|" << dec->getIsOn() << "|" << dec->getExtra() << endl;
	}
	saveFile.close();
	cout << "Devices saved successfully!" << endl;
}
void upload(vector<unique_ptr<SmartDevice>>& d) {
	ifstream loadFile("Devices.txt");
	if (!loadFile.is_open()) {
		cout << "Cannot open Devices.txt!" << endl;
		return;
	}

	d.clear(); // Xóa danh sách cũ trên RAM trước khi nạp từ file
	string line;
	while (getline(loadFile, line)) {
		if (line.empty()) continue;

		stringstream ss(line);
		string type, id, name, statStr, extraStr;

		getline(ss, type, '|');
		getline(ss, id, '|');
		getline(ss, name, '|');
		getline(ss, statStr, '|');
		getline(ss, extraStr, '|');

		bool status = (statStr == "On");
		int extraVal = stoi(extraStr);

		if (type == "Light") { // Khớp với chuỗi mà dec->getType() trả về
			d.push_back(make_unique<SmartLight>(id, name, status, extraVal));
		}
		else if (type == "AC") {
			d.push_back(make_unique<SmartAC>(id, name, status, extraVal));
		}
	}
	loadFile.close();
	cout << "Devices uploaded successfully!" << endl;
}