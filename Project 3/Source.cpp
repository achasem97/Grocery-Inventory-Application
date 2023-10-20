#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <stdexcept>
#include <algorithm>
#include "GroceryItem.h"

using namespace std;

void printMenu();

int main() {
	string name;
	string productName;
	string remainingText;
	int quantity; 
	int userInput     = NULL;
	int searchOption  = 1;
	int displayOption = 2;
	int printOption	  = 3;
	int exitOption	  = 4;
	set<GroceryItem> items;
	GroceryItem* item = nullptr;
	ifstream inventoryFS;
	ofstream dataOutFS;
	

	while (userInput != exitOption) {
		// items set is cleared and updated at the begininng of each loop to ensure that the data is current
		items.clear();
		//open inventory input file
		inventoryFS.open("inventory.txt");

		//ensure the file opened
		if (!inventoryFS.is_open()) {
			cout << "Inventory.txt was not opened" << endl;
			return 1;
		}

		while (!inventoryFS.eof()) {
			inventoryFS >> name;
			// create a grocery item with the input name
			item = new GroceryItem(name);
			auto existingItem = items.find(*item);
			// check if the grocery item exists
			if (existingItem != items.end()) {
				// stores existing data, deletes previous item, and creates new pointer
				name = existingItem->getName();
				quantity = existingItem->getQuantity();
				items.erase(*item);
				item = new GroceryItem(name, quantity);
			}
			// add one quantity count to the grocery item and add to the set
			item->addItem();
			items.insert(*item);
			// discard memory as the item has now been stored in the set
			delete item;
		}

		//close input stream
		inventoryFS.close();

		//open output stream and loop through the set while writing to the file
		dataOutFS.open("frequency.dat");

		if (!dataOutFS.is_open()) {
			cout << "frequency.dat was not opened" << endl;
		}

		for (GroceryItem item : items) {
			dataOutFS << item.getName() << " " << item.getQuantity() << endl;
		}

		//close output stream
		dataOutFS.close();
		try {
			cin.exceptions(ios::failbit);
			printMenu();
			cin >> userInput;
			if (userInput < 1 || userInput > 4) {
				throw runtime_error("Invalid input, please try again.");
			}
		
			if (userInput == searchOption) {
				
				cout << "Enter product name: ";
				cin >> productName;
				// Create a new grocery item to search the set for
				item = new GroceryItem(productName);

				auto existingItem = items.find(*item);
				// See if the new item is in the ful set
				if (existingItem != items.end()) {
						// Retrieve and print the name and quantity of the desired item
						name = existingItem->getName();
						quantity = existingItem->getQuantity();
						cout << existingItem->getName() << " total: " << existingItem->getQuantity() << endl;
				}
				else {
					throw runtime_error("Item not currently in inventory.");
				}
				// deallocate space that was used
				delete item;
				}
			
			if (userInput == displayOption) {
				// loop through and print all items and quantities
				for (GroceryItem item : items) {
					cout << item.getName() << " " << item.getQuantity() << endl;
				}
			}
		
			if (userInput == printOption) {
				// loop through and print all items and quantities in the form of an *
				for (GroceryItem item : items) {
					cout << item.getName() << ": ";
					for (int i = 0; i < item.getQuantity(); ++i) {
						cout << "*";
					}
					cout << endl;
				}
			}
		}
		catch (std::ios_base::failure excpt) {
			// clear error state and remaining text
			cin.clear();
			getline(cin, remainingText);
			cout << "Invalid input, please try again." << endl;
		}

		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
			cin.clear();
		}
		cout << endl;
	}
	return 0;
} 

void printMenu() {
	cout << "MENU OPTIONS" << endl;
	cout << "1. Search for an item" << endl;
	cout << "2. Display all frequencies" << endl;
	cout << "3. Print histogram" << endl;
	cout << "4. Exit" << endl;
}
