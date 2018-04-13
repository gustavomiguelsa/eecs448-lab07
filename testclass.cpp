/**
*	@author Gustavo Assuncao
*	@date 04/09/2018
*	@file testclass.cpp
*/

#include "testclass.h"


TestClass::TestClass()
{

}

void TestClass::printResult(bool var)
{
        if(var == true)
	{
		std::cerr << "\033[1;32m";
                std::cerr << "PASSED" << std::endl;
		std::cerr << "\033[1;0m";
	}        
	else
	{       
		std::cerr << "\033[1;31m";  
		std::cerr << "FAILED" << std::endl;
		std::cerr << "\033[1;0m";
	}
}

void TestClass::printDescription(int ntest, std::string description)
{	
	std::cerr << "\033[1;36m";
        std::cerr << "Test " << ntest << " -->  ";
	std::cerr << "\033[1;0m";
	std::cerr << description << " -->  ";
}

void TestClass::runTests()
{
	test_isEmpty1();
	test_size1();
	test_addBack1();
	test_addBack2();
	test_addFront1();
	test_addFront2();
	test_removeBack();
	test_removeFront();

	test_removeBack_empty();
	test_removeFront_empty();

	test_size2();
	test_size3();
	test_size4();
	test_size5();
	test_size6();
	test_size7();

	test_search1();
	test_search2();
	test_search3();
	
	test_isEmpty2();
}

bool TestClass::test_isEmpty1()
{
	LinkedListOfInts testableList;

	std::vector<int> test_vector = testableList.toVector();	//Since it is known that toVector() works
	
	bool test_result = (test_vector.empty() == testableList.isEmpty());

	printDescription(1,"newly created list is empty by isEmpty()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_size1()
{
	LinkedListOfInts testableList;

	bool test_result = (testableList.size() == 0);
	
	printDescription(2,"newly created list has size 0 by size()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_addBack1()
{
	LinkedListOfInts testableList;
	testableList.addBack(14);

	std::vector<int> test_vector = testableList.toVector();	//Since it is known that toVector() works

	bool test_result = (!test_vector.empty() && test_vector.size() == 1 && ( test_vector[0] == 14 ) );

	printDescription(3,"one element successfully added to list by addBack()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_addBack2()
{
	LinkedListOfInts testableList;
	int n_values = 30;

	for(int i = 1; i <= n_values; ++i)
		testableList.addBack(i);
	
	std::vector<int> test_vector = testableList.toVector();	//Since it is known that toVector() works
	//It will be {1,2,3,4,...};

	bool test_result = false;

	if(!test_vector.empty() && test_vector.size() == 30)
		for(int i = 1; i <= n_values; ++i)
		{
			test_result = ( test_vector[i-1] == i );
			if(test_result == false)
				break;
		}

	printDescription(4,"multiple elements successfully added to list by addBack() in correct order");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_addFront1()
{
	LinkedListOfInts testableList;
	testableList.addFront(14);

	std::vector<int> test_vector = testableList.toVector();	//Since it is known that toVector() works

	bool test_result = (!test_vector.empty() && test_vector.size() == 1 && ( test_vector[0] == 14 ) );

	printDescription(5,"one element successfully added to list by addFront()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_addFront2()
{
	LinkedListOfInts testableList;
	int n_values = 30;

	for(int i = 1; i <= n_values; ++i)
		testableList.addFront(i);
	
	std::vector<int> test_vector = testableList.toVector();	//Since it is known that toVector() works
	//It will be {30,29,28,...}

	bool test_result = false;

	if(!test_vector.empty() && test_vector.size() == 30)
		for(int i = 1; i <= n_values; ++i)
		{
			test_result = ( test_vector[i-1] == n_values-(i-1) );
			if(test_result == false)
				break;
		}

	printDescription(6,"multiple elements successfully added to list by addFront() in correct order");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_removeBack()
{
	LinkedListOfInts testableList;
	
	//At this point it is already know that addFront() works correctly.
	for(int i = 1; i <= 30; ++i)
		testableList.addFront(i);
	
	bool success = testableList.removeBack();	//Remove 30 from list which is leftmost element

	std::vector<int> test_vector = testableList.toVector();	//Since it is known that toVector() works
	//It will be {30,29,28,...,2}

	bool test_result = false;

	if(!test_vector.empty() && test_vector.size() == 29)
		for(int i = 2; i <= 30; ++i)
		{
			test_result = ( test_vector[i-2] == 30-(i-2) );	//Check if list was harmed
			if(test_result == false)
				break;
		}

	printDescription(7,"one element successfully removed from back of populated list and order preserved");

	printResult(test_result && success);
	return (test_result && success);		
}

bool TestClass::test_removeFront()
{
	LinkedListOfInts testableList;
	
	//At this point it is already know that addFront() works correctly.
	for(int i = 1; i <= 30; ++i)
		testableList.addFront(i);

	bool success = testableList.removeFront();	//Remove 1 from list, which is rightmost element

	std::vector<int> test_vector = testableList.toVector();	//Since it is known that toVector() works
	//It will be {29,28,...,1}

	bool test_result = false;
	if(!test_vector.empty() && test_vector.size() == 29)
		for(int i = 1; i <= 29; ++i)
		{
			test_result = ( test_vector[i-1] == 29-(i-1) ); //Check if list was harmed
			if(test_result == false)
				break;
		}
	
	printDescription(8,"one element successfully removed from front of populated list and order preserved");

	printResult(test_result && success);
	return (test_result && success);
}

bool TestClass::test_removeBack_empty()
{
	LinkedListOfInts testableList;
	bool test_result;

	if(testableList.removeBack() == false)
		test_result = true;
	else
		test_result = false;

	printDescription(9,"false is returned on empty list from removeBack()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_removeFront_empty()
{
	LinkedListOfInts testableList;
	bool test_result;

	if(testableList.removeFront() == false)
		test_result = true;
	else
		test_result = false;

	printDescription(10,"false is returned on empty list from removeFront()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_size2()
{
	LinkedListOfInts testableList;
	testableList.addBack(14);

	bool test_result = (testableList.size() == 1);

	printDescription(11,"size returns correct value after 1 addBack()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_size3()
{
	LinkedListOfInts testableList;
	testableList.addFront(14);

	bool test_result = (testableList.size() == 1);

	printDescription(12,"size returns correct value after 1 addFront()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_size4()
{
	LinkedListOfInts testableList;
	testableList.addBack(14);
	testableList.addBack(15);
	testableList.addBack(16);	

	bool test_result = (testableList.size() == 3);

	printDescription(13,"size returns correct value after multiple addBack()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_size5()
{
	LinkedListOfInts testableList;
	testableList.addFront(14);
	testableList.addFront(15);
	testableList.addFront(16);	

	bool test_result = (testableList.size() == 3);

	printDescription(14,"size returns correct value after multiple addFront()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_size6()
{
	LinkedListOfInts testableList;
	testableList.addFront(14);
	testableList.addFront(15);
	testableList.addFront(16);

	testableList.removeBack();	//Here it is already known that removeBack fails

	bool test_result = (testableList.size() == 3);

	printDescription(15,"true if list size is unchanged after removeBack has failed");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_size7()
{
	LinkedListOfInts testableList;
	testableList.addFront(14);
	testableList.addFront(15);
	testableList.addFront(16);

	testableList.removeFront();	//Here it is already known that removeFront fails

	bool test_result = (testableList.size() == 3);

	printDescription(16,"true if list size is unchanged after removeFront has failed");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_search1()
{
	LinkedListOfInts testableList;	//Newly created list is definitely empty
	bool test_result;

	if(testableList.search(14) == false)
		test_result = true;
	else
		test_result = false;

	printDescription(17,"false is returned on empty list from search()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_search2()
{
	LinkedListOfInts testableList;
	testableList.addFront(15);
	testableList.addFront(40);
	bool test_result;

	if(testableList.search(14) == false)
		test_result = true;
	else
		test_result = false;

	printDescription(18,"false is returned when value not in list, from search()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_search3()
{
	LinkedListOfInts testableList;
	for(int i = 1; i <= 1'000'000; ++i)
		testableList.addFront(i);
	
	bool test_result;

	if(testableList.search(14) == true)
		test_result = true;
	else
		test_result = false;

	printDescription(19,"true is returned when value present in large list, from search()");

	printResult(test_result);
	return test_result;
}

bool TestClass::test_isEmpty2()
{
	LinkedListOfInts testableList;

	testableList.addFront(30);
	testableList.addFront(40);
	testableList.addFront(50);

	std::vector<int> test_vector = testableList.toVector();	//Since it is known that toVector() works
	
	bool test_result = (test_vector.empty() == testableList.isEmpty());

	printDescription(20,"check if populated list is not empty, by isEmpty()");

	printResult(test_result);
	return test_result;
}





