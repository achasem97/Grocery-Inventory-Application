#include "GroceryItem.h"

//Base Constructor. Quantity set to 0 if only name is given
//@param value - string: name of the item
//@returns - Constructor
GroceryItem::GroceryItem(std::string& name) {
	this->name = name;
	this->quantity = 0;
}

//Overloaded constructor. Takes an integer value to store for quantity
//@param value - string: name of the item, int: quantity of the item
//@returns - Constructor
GroceryItem::GroceryItem(std::string& name, int quantity) {
	this->name = name;
	this->quantity = quantity;
}

//Getter for the name of an object
//@param value - none
//@returns - string: the name of that object
std::string GroceryItem::getName() const {
	return name;
}

//Getter for the quantity of an object
//@param value - none
//@returns - integer: Objects quantity
int GroceryItem::getQuantity() const {
	return quantity;
}

//Increments the quantity of an objects quantity
//@param value - none
//@returns - void
void GroceryItem::addItem() {
	quantity += 1;
}

//Decrements the quantity of an item
//@param value - none
//@returns - void
void GroceryItem::removeItem() {
	quantity -= 1;
}

//Reassigns the < operator to sort the grocery items alphabetically
//@param value - takes a grocery item as a parameter
//@returns - returns the bool value of whether the one object is alphabetically before the other
bool GroceryItem::operator<(const GroceryItem& other) const {
	return name.compare(other.getName()) < 0;
}