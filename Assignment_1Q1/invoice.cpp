//Mohamed Chouaib Fadli
//ID : 40274781
//Assignment 1 : Question 1
//invoice.cpp
#include "invoice.h"
#include <iostream>
#include <string>
#include <array>

using namespace std;

//Counter
int Invoice::count = 0;

// Default constructor: Initializes members with default values and increments Count
Invoice::Invoice() : part_number(""), part_description(""), quantity(0), price_per_item(0) { count++; }

//Constractor that initializes the four data members
Invoice::Invoice(string n, string d, int q, int p) :part_number(n), part_description(d), quantity(q), price_per_item(p) {
	count++;
}

//getter for part number
string Invoice::getPartNumber() {
	return part_number;
}
//setter for part number
void Invoice::setPartNumber(string n) {
	part_number = n;
}
//getter for part description 
string Invoice::getPartDescription() {
	return part_description;
}
//setter for part description 
void Invoice::setPartDescription(string d) {
	part_description = d;
}
//getter for quantity
int Invoice::getQuantity() {
	return quantity;
}
//setter for quantity
void Invoice::setQuantity(int q) {
	quantity = q;
}
//getter for price
int Invoice::getPrice() {
	return price_per_item;
}
//setter for price 
void Invoice::setPrice(int p) {
	price_per_item = p;
}
//Invoice function 
int Invoice::getInvoiceAmount() {
	if (price_per_item < 0 or quantity < 0) 
	{
		return 0;
	}
	else
		return price_per_item * quantity;
}
//Copy constructor 
Invoice::Invoice(const Invoice& other) {
	part_number = other.part_number;
	part_description = other.part_description;
	quantity = other.quantity;
	price_per_item = other.price_per_item;
}

//Destructor
Invoice::~Invoice() {
	count--;
}

//clone for current obj
Invoice Invoice::clone() {
	return  Invoice(*this);
}

//clone by reference
Invoice Invoice::clone(const Invoice & obj) {
	return Invoice(obj);
}