//HW2-2

#include <iostream>
#include <list>

using namespace std;

int main() {

	//Let user input the node numbers
	int node_number;
	cout << "Please entered the number of node: ";
	cin >> node_number;

	//Create an input
	list<char> input;

	//Push the ASC|| into input
	for (int i = 0; i < node_number; i++) {
		input.push_back(0x41 + i);
	}

	//Create the counter
	int count = 1;

	//Create the odd node and even node
	list<char> odd;
	list<char> even;

	//Show the input and divide the odd node and even node
	cout << "Input: ";
	for (list<char>::iterator item = input.begin(); item != input.end(); ++item) {
		if (count % 2 == 1) {
			odd.push_back(*item);
		}
		else {
			even.push_back(*item);
		}

		count++;

		cout << *item;
	}
	cout << endl;

	//Concatenate the even after odd
	odd.splice(odd.end(), even);

	//Output the result
	cout << "Output: ";
	for (list<char>::iterator item = odd.begin(); item != odd.end(); ++item) {
		cout << *item;
	}
	cout << endl;

	system("pause");
	return 0;
}