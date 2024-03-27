// --------------------------------------------------------------------------------
// Name: Pat Callahan
// Class: C++ 3
// Assignment: Resizeable Arrays with deep copy
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "CResizableArray.h"


// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// User Defined Types
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
void Test1( CResizableArray &clsValues );		// By Reference
void Test2( CResizableArray clsValues );		// By Value

// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts.
// --------------------------------------------------------------------------------
void main()
{
	CResizableArray clsValues( 4 );

	// Populate Array (value, index)
	clsValues[ 0 ] = 2;
	clsValues[ 1 ] = 4;
	clsValues[ 2 ] = 6;
	clsValues[ 3 ] = 8;

	clsValues.Print( );

	// Test 1
	Test1( clsValues );
	printf( "After Test 1 ------------------------------\n" );
	clsValues.Print( );

	// Test 2
	Test2( clsValues );
	printf( "After Test 2 ------------------------------\n" );
	clsValues.Print( );

	// Self assignment test
	clsValues = clsValues;
	clsValues.Print( "After self assignment" );

	CResizableArray clsValues2;

	clsValues2 = clsValues;
	clsValues2.Print( "After copy" );

	clsValues += clsValues;
	clsValues.Print( "After append self" );

	clsValues += clsValues2;
	clsValues.Print( "After append copy" );

	CResizableArray clsValues3;

	clsValues3 = clsValues + clsValues2;
	clsValues3.Print( "After plus" );

	clsValues = clsValues + clsValues2;
	clsValues.Print( "After plus to self" );

	system( "pause" );
}


// --------------------------------------------------------------------------------
// Name: Test1
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void Test1( CResizableArray &clsValues )
{
	printf( "Test 1 ------------------------------\n" );
	clsValues.Print( );
}


// --------------------------------------------------------------------------------
// Name: Test2
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void Test2( CResizableArray clsCopyOfOriginal )
{
	printf( "Test 2 ------------------------------\n" );
	clsCopyOfOriginal.Print( );

}