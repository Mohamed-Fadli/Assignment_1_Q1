//Mohamed Chouaib Fadli 
//ID : 40274781
//Assignment 1 : Question 1
//invoice.h
#ifndef INVOICE_H_
#define INVOICE_H_
#include<iostream>
#include<array>
#include<string>

using namespace std;

class Invoice
{
private:
	string part_number;
	string part_description;
	int quantity;
	int price_per_item;
public:
	//Default constructor
	Invoice();
	//Constractor that initializes the four data members
	Invoice(string n, string d, int q, int p);

	//Copy constructor 
	Invoice(const Invoice &other);
	
	//Destructor
	~Invoice();

	//getter and setter for part number
	string getPartNumber() ;
	void setPartNumber(string n);

	//getter and setter for part description 
	string getPartDescription() ;
	void setPartDescription(string d);

	//getter and setter for quantity
	int getQuantity() ;
	void setQuantity(int q);

	//getter and setter for price per quantity
	int getPrice() ;
	void setPrice(int p);

	//function invoice amount
	int getInvoiceAmount();

	//clone for current objet
	Invoice clone();

	//clone pass by refrence
	Invoice clone(const Invoice &obj);

	static int count;
};

#endif // !INVOICE_H_

