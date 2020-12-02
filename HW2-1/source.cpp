//HW2-1

#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

//Print function
void print(stack<int>);
void print(queue<int>);
void print(vector<vector<int> > &);

int main() {

	//Passenger number
	const int number = 20;

	//Data
	int data[number] = {70, 67, 75, 55, 51, 40, 87, 65, 58, 86,
						66, 43, 57, 76, 68, 61, 60, 63, 39, 74};

	//Create the passenger list
	queue<int> passenger;
	for (int i = 0; i < number; i++) {
		passenger.push(data[i]);
	}

	//Create the bus station
	queue<int> station;

	//Create the bus
	stack<int> bus;

	//Create the school
	vector<vector<int> > school;

	//Start the bus transform
	while (passenger.empty() != true) {
		
		//Put the people from passenger into station
		while (station.size() < 8) {

			//Print
			system("cls");
			print(station);
			print(bus);
			print(school);
			system("pause");

			station.push(passenger.front());
			passenger.pop();
		}

		//Set the bus weight
		int weight = 0;

		//Put the people from station into bus
		while (bus.size() < 4) {	//Check if the bus have four people or not

			//Print
			system("cls");
			print(station);
			print(bus);
			print(school);
			system("pause");

			bus.push(station.front());
			weight += station.front();
			station.pop();

			while (weight >= 260) {	//Check if the bus weight over 260

				//Print
				system("cls");
				print(station);
				print(bus);
				print(school);
				system("pause");

				station.push(bus.top());
				weight -= bus.top();
				bus.pop();
			}
		}

		//Put the people from bus to school
		vector<int> tempSchool;

		while (bus.empty() != true) {

			//Print
			system("cls");
			print(station);
			print(bus);
			print(school);
			system("pause");

			tempSchool.insert(tempSchool.begin(), bus.top());
			bus.pop();
		}

		school.push_back(tempSchool);
		tempSchool.clear();

		//Put rest of the people into bus then to school
		if (passenger.empty() == true) {
			while (station.empty() != true) {

				//Print
				system("cls");
				print(station);
				print(bus);
				print(school);
				system("pause");

				bus.push(station.front());
				station.pop();
			}

			while (bus.empty() != true) {

				//Print
				system("cls");
				print(station);
				print(bus);
				print(school);
				system("pause");

				tempSchool.insert(tempSchool.begin(), bus.top());
				bus.pop();
			}

			school.push_back(tempSchool);
			tempSchool.clear();
		}
	}

	//Print
	system("cls");
	print(station);
	print(bus);
	print(school);
	system("pause");

	return 0;
}

void print(stack<int> data) {
	vector<int> output;

	while (data.empty() != true) {
		output.insert(output.begin(), data.top());
		data.pop();
	}

	cout << "Bus: ";
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << " ";
	}
	cout << endl;
}

void print(queue<int> data) {
	vector<int> output;

	while (data.empty() != true) {
		output.push_back(data.front());
		data.pop();
	}

	cout << "Station: ";
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << " ";
	}
	cout << endl;
}

void print(vector<vector<int> > &other) {
	cout << "School:" << endl;
	for (int i = 0; i < other.size(); i++) {
		cout << " " << i + 1 << " :";
		for (int j = 0; j < other[i].size(); j++) {
			cout << other[i][j] << " ";
		}
		cout << endl;
	}
}