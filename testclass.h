/**
*	@file testclass.h
*	@author Gustavo Assuncao
*	@date 04/09/2018
*	@brief A header file for the test class
*/

#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <iostream>
#include <vector>
#include "LinkedListOfInts.h"

class TestClass
{
	public:

	/** @pre None
	*   @post Default constructor for TestClass
	*/
	TestClass();

	/**
	*   @pre None
	*   @post Runs all tests implemented in the test class
	*   @return None	
	*/
	void runTests();

	bool test_isEmpty1();		//Test if isEmpty() works for a newly created empty list
	bool test_isEmpty2();		//Test if isEmpty() works for a populated list
	bool test_size1();		//Test if size of empty list is 0
	bool test_addBack1();		//Test if one element successfully added to end of list
	bool test_addBack2();		//Test if multiple elements successfully added to end of list in correct order
	bool test_addFront1();		//Test if one element successfully added to front of list
	bool test_addFront2();		//Test if multiple elements successfully added to front of list	in correct order


	bool test_removeBack();		//Test if element was successfully removed from back of populated list and order preserved
	bool test_removeFront();	//Test if element was successfully removed from front of populated list and order preserved
	bool test_removeBack_empty();	//Test if false is returned on empty list
	bool test_removeFront_empty();	//Test if false is returned on empty list


	bool test_size2();		//Test size after 1 addBack
	bool test_size3();		//Test size after 1 addFront
	bool test_size4();		//Test size after multiple addBack
	bool test_size5();		//Test size after multiple addFront
	bool test_size6();		//Test size unchanged after removeBack fails
	bool test_size7();		//Test size unchanged after removeFront fails

	bool test_search1();		//Test if false is returned on empty list
	bool test_search2();		//Test if false when value not in list
	bool test_search3();		//Test if true when value is in large list
	


	private:

	/**
	*   @pre A boolean variable specifying whether a test was passed or not
	*   @post Prints the result of a test, either PASSED or FAILED
	*   @return None	
	*/
	void printResult(bool var);

	/**
	*   @pre An integer with the number of the test and a string containing the description of the test
	*   @post Prints the test number and a brief description of the test
	*   @return None	
	*/
	void printDescription(int ntest, std::string description);
};

#endif 



