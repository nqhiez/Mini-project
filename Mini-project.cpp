#include <iostream>
#include <memory>
#include <vector>
#include "SmartAC.h"
#include "SmartLight.h"
using namespace std;
vector<unique_ptr<SmartDevice>> devices;
void Add(vector<unique_ptr<SmartDevice>> &d);
void list();
void toggle();
void save();
void upload();
int main() {
	bool menu = true;
	int func;
	while (menu) {
		cout << "------|Smart Devices Manager|------" << endl << "Welcome back! What do you want?" << endl;
		cout << "1. Add devices\n2. Show devices list\n3. Toggle device\n4. Save devices file\n5. Upload devices file\n6. Leave\n";
		cout << "Press a number: ";
		cin >> func; cin.ignore();
		switch (func) {
		case 1: Add(devices); break;
		case 2: list(); break;
		case 3: toggle(); break;
		case 4: save(); break;
		case 5: upload(); break;
		case 6: menu = false; break;
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
	cout << "Type: 1.Light || 2.AC === Enter: "; cin >> type;
	cout << "ID: "; cin >> id;
	cout << "Name: "; cin >> name;
	cout << "Status: 0. Off || 1. On"; cin >> status;
	switch (type) {
	case 1:

		d.push_back(make_unique<SmartLight>(id,name,status));
	}
}
void list() {
	cout << "test2";
}
void toggle() {
	cout << "test 3";
}
void save() {
	cout << "4";
}
void upload() {
	cout << "5";
}