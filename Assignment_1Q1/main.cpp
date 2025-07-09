//Mohamed Chouaib Fadli 
//ID : 40274781
//Assignment 1 : Question 1
//main.cpp
#include <iostream>
#include "invoice.h"
#include <string>
#include <array>

using namespace std;

int test_count = 0;
int pass_count = 0;
int fail_count = 0;

//test for get Invoice function (case negative or zero price/quantity + check for the quantity * price)
bool test_getInvoiceAmount(Invoice obj) {
	test_count++;
	if (obj.getPrice() < 0 or obj.getQuantity() < 0) {
		if (obj.getInvoiceAmount() == 0) {
			pass_count++;
			return true;
		}
		else {
			fail_count++;
			return false;
		}
	}
	else {
		if (obj.getInvoiceAmount() == obj.getPrice() * obj.getQuantity()) {
			pass_count++;
			return true;
		}
		else {
			fail_count++;
			return false;
		}
	}
}

//test of the copy instructor
bool test_CopyInstructor(Invoice obj1, Invoice obj2) {
	test_count++;
	if (obj1.getQuantity() == obj2.getQuantity()) {
		pass_count++;
		return true;
	}
	else {
		fail_count++;
		return false;
	}
}

//test of the destructor
bool test_Destructor() {
	test_count++;
	for (int i = 0;i < 2;i++) {
		Invoice obj("", "", 0, 0);
	}
	if (Invoice::count == test_count) {
		pass_count++;
		return true;
	}
	else {
		fail_count++;
		return false;
	}
}

int main() {
	Invoice object1("", "", 8, 5);
	Invoice object2(object1);
	Invoice object3 = object1.clone();
	Invoice object4 = object1.clone(object1);

	
	//Detructor test check
	string test_destructor = test_Destructor() ? "Pass!" : "Fail";
	cout << "Destructor : " << test_destructor << endl;

	//testing the Invoice function and the tset itself  
	string test1 = test_getInvoiceAmount(object1) ? "Pass!" : "Fail!";
	cout << "Invoice amount for objet 1 is : " << object1.getInvoiceAmount() << " Invoice test : " << test1 << "\n" << endl;;

	//testing  the copy constructor through the object2(object1)
	string test2 = test_getInvoiceAmount(object2) ? "Pass!" : "Fail!";
	cout << "Invoice amount for object 2 is : " << object2.getInvoiceAmount() << " Invoice test : " << test2 << "\n";
	string test3 = test_CopyInstructor(object1, object2) ? "Pass!" : "Fail!";
	cout << "Copy construcor : " << test3 << endl << endl;

	//testing the normal clone 
	string test4 = test_getInvoiceAmount(object3) ? "Pass!" : "Fail!";
	cout << "Invoice amount for object 3 is : " << object3.getInvoiceAmount() << " Invoice test : " << test4 << endl;
	string test5 = test_CopyInstructor(object1, object3) ? "Pass!" : "Fail!";
	cout << "Clone function : " << test4 << endl << endl;

	//testing the pass by reference clone 
	string test6 = test_getInvoiceAmount(object4) ? "Pass!" : "Fail";
	cout << "Invoice amount for object 4 is : " << object4.getInvoiceAmount() << " Invoice test : " << test6 << endl;
	string test7 = test_CopyInstructor(object1, object4) ? "Pass!" : "Fail!";
	cout << "Clone pass-by-reference function : " << test7 << endl << endl;

	//testing the negative invoice case
	Invoice object5("", "", -4, 6);
	string test8 = test_getInvoiceAmount(object5) ? "Pass!" : "Fail!";
	cout << "Invoice for object 5 is : " << object5.getInvoiceAmount() << " Invoice test : " << test8 << endl;

	//display of the statistics 
	cout << "the total number of successful tests is : " << pass_count << "/" << test_count << " , and the total number of unsuccessful tests is : " << fail_count << "/" << test_count << endl;

}	