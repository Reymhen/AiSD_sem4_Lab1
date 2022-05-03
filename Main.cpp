#include "Red-Black tree.h"

int main()
{
	cout << "Create an empty map\n";
	RBtree<int, int> CustomMap;
	CustomMap.print();
	cout << endl;

	cout << "Add an element to the map\n";
	CustomMap.insert(13, 31);
	CustomMap.print();
	cout << endl;


	cout << "Remove element with key 2\n";
	try {
		CustomMap.remove(2);
	}
	catch (const out_of_range error) {
		cout << error.what() << endl;
	}
	cout << endl;


	cout << "Add more elements to the map\n";
	CustomMap.insert(11, 32);
	CustomMap.insert(15, 21);
	CustomMap.insert(9, 22);
	CustomMap.insert(14, 9);
	CustomMap.insert(12, 4);
	CustomMap.insert(17, 4);
	CustomMap.print();
	cout << endl;
	cout << "Remove element with key 11\n";
	try {
		CustomMap.remove(11);
	}
	catch (const out_of_range error) {
		cout << error.what() << endl;
	}
	CustomMap.print();
	cout << endl;


	cout << "Derive all keys of an map\n";
	CustomMap.get_keys();
	cout << endl << endl;

	cout << "Derive all values of an map\n";
	CustomMap.get_values();
	cout << endl << endl;

	cout << "Clear the map\n";
	CustomMap.clear();
	CustomMap.print();

}
	