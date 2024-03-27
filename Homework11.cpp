// --------------------------------------------------------------------------------
// Name: Nirupama Poojari
// Class: C++ 3
// Assignment: Resizeable Arrays with deep copy
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//#include "CResizableArray.cpp"
//#ifndef CRESIZABLE_ARRAY_H
//#define CRESIZABLE_ARRAY_H
#include "CResizableArray.h"
 #include "CStack.h"
//#ifndef CRESIZABLE_ARRAY_CPP
//#define CRESIZABLE_ARRAY_CPP
// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// User Defined Types
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
void Test1( CResizableArray<long> &clsValues );		// By Reference
void Test2( CResizableArray<long> clsValues );		// By Value
void longTemplateTest();
void charTemplateTest();
void doubleTemplateTest();
void StackTests1(CStack<int>& clsOriginal);
void StackTests2(CStack<int> clsCopy);
void StackTests();
// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts.
// --------------------------------------------------------------------------------
int main()
{   
	StackTests();
	//longTemplateTest();
	
	//charTemplateTest();// char Test
	//doubleTemplateTest();

	// system( "pause" );  
	return 1;

}
void doubleTemplateTest() {
	CResizableArray<double> clsValues(0);
	/* CResizableArray<double> clsValues(4);

	// Populate Array (value, index)
	clsValues[0] = 2.0;
	clsValues[1] = 5.0;
	clsValues[2] = 4.0;
	clsValues[3] = 3.0; */

	clsValues.Print();

	/* 	// Test 1
		Test1( clsValues );
		printf( "After Test 1 ------------------------------\n" );
		clsValues.Print( );

		// Test 2
		Test2( clsValues );
		printf( "After Test 2 ------------------------------\n" );
		clsValues.Print( ); */

		// Self assignment test
	clsValues = clsValues;
	clsValues.Print("After self assignment");

	CResizableArray<double> clsValues2;

	clsValues2 = clsValues;
	clsValues2.Print("After copy");

	clsValues += clsValues;
	clsValues.Print("After append self");

	clsValues += clsValues2;
	clsValues.Print("After append copy");

	CResizableArray<double> clsValues3;

	clsValues3 = clsValues + clsValues2;
	clsValues3.Print("After plus");

	clsValues = clsValues + clsValues2;
	clsValues.Print("After plus to self");
}
void charTemplateTest() {
	CResizableArray<char> clsValuesChar(4);

	// Populate Array (value, index)
	clsValuesChar[0] = 'd';
	clsValuesChar[1] = 'c';
	clsValuesChar[2] = 'x';
	clsValuesChar[3] = 'y';

	clsValuesChar.Print();

	/* 	// Test 1
		Test1( clsValues );
		printf( "After Test 1 ------------------------------\n" );
		clsValues.Print( );

		// Test 2
		Test2( clsValues );
		printf( "After Test 2 ------------------------------\n" );
		clsValues.Print( ); */

		// Self assignment test
	clsValuesChar = clsValuesChar;
	clsValuesChar.Print("After self assignment");

	CResizableArray<char> clsValues2;

	clsValues2 = clsValuesChar;
	clsValues2.Print("After copy");

	clsValuesChar += clsValuesChar;
	clsValuesChar.Print("After append self");

	clsValuesChar += clsValues2;
	clsValuesChar.Print("After append copy");

	CResizableArray<char> clsValues3;

	clsValues3 = clsValuesChar + clsValues2;
	clsValues3.Print("After plus");

	clsValuesChar = clsValuesChar + clsValues2;
	clsValuesChar.Print("After plus to self");
}
void longTemplateTest() {
	CResizableArray<long> clsValues(4);

	// Populate Array (value, index)
	clsValues[0] = 2;
	clsValues[1] = 4;
	clsValues[2] = 6;
	clsValues[3] = 8;

	clsValues.Print();
	/* 
	 	// Test 1
		Test1( clsValues );
		printf( "After Test 1 ------------------------------\n" );
		clsValues.Print( );

		// Test 2
		Test2( clsValues );
		printf( "After Test 2 ------------------------------\n" );
		clsValues.Print( ); 
     */
		// Self assignment test
	clsValues = clsValues;
	clsValues.Print("After self assignment");

	CResizableArray<long> clsValues2;

	clsValues2 = clsValues;
	clsValues2.Print("After copy");

	clsValues += clsValues;
	clsValues.Print("After append self");

	clsValues += clsValues2;
	clsValues.Print("After append copy");

	CResizableArray<long> clsValues3;

	clsValues3 = clsValues + clsValues2;
	clsValues3.Print("After plus");

	clsValues = clsValues + clsValues2;
	clsValues.Print("After plus to self");
}
/* 
// --------------------------------------------------------------------------------
// Name: Test1
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void Test1( CResizableArray<long>&clsValues )
{
	printf( "Test 1 ------------------------------\n" );
	clsValues.Print( );
}


// --------------------------------------------------------------------------------
// Name: Test2
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void Test2( CResizableArray<long> clsCopyOfOriginal )
{
	printf( "Test 2 ------------------------------\n" );
	clsCopyOfOriginal.Print( );

} */

 
//Name: StackTests
//Abstract: Tests on Stack
void StackTests()
{
	CStack<int> clsStack1;
	clsStack1.Print("Empty Stack");

	//Push
	clsStack1.Push(2);
	clsStack1.Push(4);
	clsStack1.Push(6);
	clsStack1.Push(8);
	// 	clsStack1.Print("after pushing 2,4,6");
		//clsStack1.Push();

		//Pop
	//	cout << "Pop() =" << clsStack1.Pop() << endl;
	//	clsStack1.Print("After popping 6");

	//	cout << "Pop() =" << clsStack1.Pop() << endl;
	//	cout << "Pop() =" << clsStack1.Pop() << endl;
	//	cout << "Pop() =" << clsStack1.Pop() << endl;
	//	clsStack1.Print("After popping all");

		//Push
	//	clsStack1.Push(8);
	//	clsStack1.Print("after pushing 8"); 
	clsStack1.Print("after pushing 2,4,6,8");
	// cout << "I like C++" << endl; 
	clsStack1.Print("Stack Test 1 Before Pass By Ref");
	StackTests1(clsStack1);
	clsStack1.Print("Stack Test 1 After Pass By Ref");


	clsStack1.Print("Stack Test 2 Before Pass By Value");
	StackTests2(clsStack1);
	clsStack1.Print("Stack Test2 After Pass By Value");
}

//Name: QueueTest1
//Abstract: Tests on Stack Pass By ref
void StackTests1(CStack<int>& clsOriginal)
{
	clsOriginal.Print("Stack Test 1 Pass By Ref");

}

//Name: StackTest2
//Abstract: Tests on Stack Pass By value
void StackTests2(CStack<int> clsCopy)
{
	clsCopy.Print("Stack Test 2 Pass By value");
} 


//endif