// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: A resizeable array class with all the inner workings hidden.
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CResizableArray.h"


// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Default constructor
// --------------------------------------------------------------------------------
CResizableArray::CResizableArray( )
{
	Initialize( 0, 0 );
}


// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Parameterized constructor
// --------------------------------------------------------------------------------
CResizableArray::CResizableArray( long lngInitialSize )
{
	Initialize( lngInitialSize, 0 );
}


// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Parameterized constructor
// --------------------------------------------------------------------------------
CResizableArray::CResizableArray( long lngInitialSize, long lngDefaultValue )
{
	Initialize( lngInitialSize, lngDefaultValue );
}


// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Parameterized constructor
// --------------------------------------------------------------------------------
CResizableArray::CResizableArray( const CResizableArray &clsOriginalToCopy )
{
	Initialize( 0, 0 );

	*this = clsOriginalToCopy;
}


	// --------------------------------------------------------------------------------
	// Name: Initialize
	// Abstract: Set class properties to zero
	// --------------------------------------------------------------------------------
	void CResizableArray::Initialize( long lngInitialSize, long lngDefaultValue )
	{
		m_lngArraySize = 0;
		m_palngValues = 0;

		SetSize( lngInitialSize, lngDefaultValue );
	}


// --------------------------------------------------------------------------------
// Name: Assignment operator
// Abstract: Perform a deep copy
// --------------------------------------------------------------------------------
void CResizableArray::operator = ( const CResizableArray &clsOriginalToCopy )
{
	// Self assignment?  Compare instance addresses
	if( this != &clsOriginalToCopy )
	{
		// No, clean up and copy
		CleanUp( );
		DeepCopy( clsOriginalToCopy );	
	}
}


	// --------------------------------------------------------------------------------
	// Name: DeepCopy
	// Abstract: Because we have pointers to dynamically allocated memory
	//		we must manually allocate duplicate blocks and copy all of the values
	//		in the original blocks of memory to the copy instance.  This is
	//		known as a deep copy.  The default behavior is a shallow copy.
	// --------------------------------------------------------------------------------
	void CResizableArray::DeepCopy( const CResizableArray &clsOriginalToCopy )
	{
		long lngSize = 0;
		long lngIndex = 0;

		// How big?
		lngSize = clsOriginalToCopy.GetSize( );

		// Allocate space
		SetSize( lngSize );

		// Deep copy
		for( lngIndex = 0; lngIndex < lngSize; lngIndex += 1 )
		{
			(*this)[ lngIndex ] = clsOriginalToCopy[ lngIndex ];
		}
	}
	

// --------------------------------------------------------------------------------
// Name: Destructor
// Abstract: Destructor
// --------------------------------------------------------------------------------
CResizableArray::~CResizableArray( )
{
	CleanUp( );
}


	// --------------------------------------------------------------------------------
	// Name: CleanUp
	// Abstract: This place is a mess.
	// --------------------------------------------------------------------------------
	void CResizableArray::CleanUp( )
	{
		SetSize( 0, 0 );
	}


// --------------------------------------------------------------------------------
// Name: subscript operator - set
// Abstract: return pointer to long 
// --------------------------------------------------------------------------------
long& CResizableArray::operator[ ]( long lngIndex )
{
	long* plngValue = 0;

	// Size not 0?
	if( m_lngArraySize > 0 )
	{
		// Yes, boundary check the index
		if( lngIndex <                  0 ) lngIndex = 0;
		if( lngIndex > m_lngArraySize - 1 ) lngIndex = m_lngArraySize - 1;

		// Get the address
		plngValue = m_palngValues + lngIndex;
	}

	return *plngValue;
}


// --------------------------------------------------------------------------------
// Name: subscript operator - get
// Abstract: return const pointer to long - read only
// --------------------------------------------------------------------------------
const long& CResizableArray::operator[ ]( long lngIndex ) const
{
	long* plngValue = 0;

	// Size not 0?
	if( m_lngArraySize > 0 )
	{
		// Yes, boundary check the index
		if( lngIndex <                  0 ) lngIndex = 0;
		if( lngIndex > m_lngArraySize - 1 ) lngIndex = m_lngArraySize - 1;

		// Get the address
		plngValue = m_palngValues + lngIndex;
	}

	return *plngValue;
}


// --------------------------------------------------------------------------------
// Name: Plus Equal
// Abstract: Append the other array
// --------------------------------------------------------------------------------
void CResizableArray::operator += ( const CResizableArray &clsOriginalToAppend )
{
	long lngNewSize = 0;
	long* palngNewValues = 0;
	long lngSourceIndex = 0;
	long lngDestinationIndex = 0;

	// New size?
	lngNewSize = GetSize( ) + clsOriginalToAppend.GetSize( );

	// Do not call SetSize because could be appending self

	// Allocate space
	palngNewValues = new long[ lngNewSize ];	// Not a string so no +1 for terminator

	// Copy 1st half
	for( lngSourceIndex = 0; lngSourceIndex < GetSize( ); lngSourceIndex += 1 )
	{
		palngNewValues[ lngDestinationIndex ] = (*this)[ lngSourceIndex ];
		lngDestinationIndex += 1;
	}

	// Copy 2nd half
	for( lngSourceIndex = 0; lngSourceIndex < clsOriginalToAppend.GetSize( ); lngSourceIndex += 1 )
	{
		palngNewValues[ lngDestinationIndex ] = clsOriginalToAppend[ lngSourceIndex ];
		lngDestinationIndex += 1;
	}

	// Delete old memory
	CleanUp( );

	// Assign new array
	m_palngValues = palngNewValues;
	m_lngArraySize = lngNewSize;
}


// --------------------------------------------------------------------------------
// Name: Plus
// Abstract: Append the other array
// --------------------------------------------------------------------------------
CResizableArray CResizableArray::operator + ( const CResizableArray &clsRight ) const
{
	CResizableArray clsLeftAndRight;

	clsLeftAndRight = *this;		// Left
	clsLeftAndRight += clsRight;	// Right

	return clsLeftAndRight;
}


// --------------------------------------------------------------------------------
// Name: SetSize
// Abstract: Resize the array
// --------------------------------------------------------------------------------
void CResizableArray::SetSize( long lngNewSize )
{
	SetSize( lngNewSize, 0 );
}
	

// --------------------------------------------------------------------------------
// Name: SetSize
// Abstract: Resize the array
// --------------------------------------------------------------------------------
void CResizableArray::SetSize( long lngNewSize, long lngDefaultValue )
{
	long* palngNewValues = 0;
	long lngIndex = 0;
	long lngStop = 0;

	// Boundary check inputs
	if( lngNewSize <      0 ) lngNewSize = 0;
	if( lngNewSize > 100000 ) lngNewSize = 100000;

	// Did the size change?
	if( lngNewSize != m_lngArraySize )
	{
		// Yes, is it larger than 0?
		if( lngNewSize > 0 ) 
		{
			// Yes, allocate space
			palngNewValues = new long [ lngNewSize ];
		}

		// Initialize new memory
		for( lngIndex = 0; lngIndex < lngNewSize; lngIndex += 1 )
		{
			// (Base pointer + offset)
			*( palngNewValues + lngIndex ) = lngDefaultValue;
		}

		// How many values can we preserve?
		if( lngNewSize < m_lngArraySize ) lngStop = lngNewSize;
		else							  lngStop = m_lngArraySize;

		// Copy values from old array into new array
		for( lngIndex = 0; lngIndex < lngStop; lngIndex += 1 )
		{
			*( palngNewValues + lngIndex ) = *( m_palngValues + lngIndex );
		}

		// Delete old array
		if( m_palngValues != 0 )
		{
			delete [] m_palngValues;
			m_palngValues = 0;
		}

		// Assign new array
		m_palngValues = palngNewValues;

		// Assign new size
		m_lngArraySize = lngNewSize;
	}

}


// --------------------------------------------------------------------------------
// Name: GetSize
// Abstract: How big is the array
// --------------------------------------------------------------------------------
long CResizableArray::GetSize( ) const
{
	return m_lngArraySize;
}


// --------------------------------------------------------------------------------
// Name: SetValueAt
// Abstract: Set the value at the specified location
// --------------------------------------------------------------------------------
void CResizableArray::SetValueAt( long lngValue, long lngIndex )
{
	// Size not 0?
	if( m_lngArraySize > 0 )
	{
		// Yes, boundary check the index
		if( lngIndex <                  0 ) lngIndex = 0;
		if( lngIndex > m_lngArraySize - 1 ) lngIndex = m_lngArraySize - 1;

		// Set the value
		*( m_palngValues + lngIndex ) = lngValue;
	}
}


// --------------------------------------------------------------------------------
// Name: GetValueAt
// Abstract: Return the value at the specified location
// --------------------------------------------------------------------------------
long CResizableArray::GetValueAt( long lngIndex ) const
{
	long lngValue = 0;

	// Size not 0?
	if( m_lngArraySize > 0 )
	{
		// Yes, boundary check the index
		if( lngIndex < 0                  ) lngIndex = 0;
		if( lngIndex > m_lngArraySize - 1 ) lngIndex = m_lngArraySize - 1;

		// Get the value
		lngValue = *( m_palngValues + lngIndex );
	}

	return lngValue;
}


// --------------------------------------------------------------------------------
// Name: AddValueToFront
// Abstract: Add a value to the front
// --------------------------------------------------------------------------------
void CResizableArray::AddValueToFront( long lngValueToAdd )
{
	InsertValueAt( lngValueToAdd, 0 );
}



// --------------------------------------------------------------------------------
// Name: AddValueToEnd
// Abstract: Add a value to the End
// --------------------------------------------------------------------------------
void CResizableArray::AddValueToEnd( long lngValueToAdd )
{
	InsertValueAt( lngValueToAdd, GetSize( ) );
}



// --------------------------------------------------------------------------------
// Name: InsertValueAt
// Abstract: Insert a value in the middle
// --------------------------------------------------------------------------------
void CResizableArray::InsertValueAt( long lngValueToInsert, long lngInsertAtIndex )
{
	long* palngNewValues = 0;
	long lngIndex = 0;

	// Boundary check index
	if( lngInsertAtIndex < 0              ) lngInsertAtIndex = 0;
	if( lngInsertAtIndex > m_lngArraySize ) lngInsertAtIndex = m_lngArraySize;

	// Make a new array of size one larger
	palngNewValues = new long[ GetSize( ) + 1 ];

	// Copy 1st half of values from old array into new array
	for( lngIndex = 0; lngIndex < lngInsertAtIndex; lngIndex += 1 )
	{
		// Old-school C pointer way
		*( palngNewValues + lngIndex ) = *( m_palngValues + lngIndex );
	}

	// Insert
	*( palngNewValues + lngInsertAtIndex ) = lngValueToInsert;

	// Copy 2nd half of values from old array into new array
	for( lngIndex = lngInsertAtIndex; lngIndex < GetSize( ); lngIndex += 1 )
	{
		// Old-school C pointer way
		*( palngNewValues + lngIndex + 1 ) = *( m_palngValues + lngIndex );
	}

	// Delete old array
	delete [] m_palngValues;
	m_palngValues = 0;

	// Assign new array
	m_palngValues = palngNewValues;

	// Assign size
	m_lngArraySize += 1;
}


// --------------------------------------------------------------------------------
// Name: RemoveAt
// Abstract: Remove a value at the specified index
// --------------------------------------------------------------------------------
void CResizableArray::RemoveAt( long lngRemoveAtIndex )
{
	long* palngNewValues = 0;
	long lngIndex = 0;

	// Is there anything to remove?
	if( GetSize( ) > 0 )
	{
		// Yes

		// Boundary check index
		if( lngRemoveAtIndex < 0                  ) lngRemoveAtIndex = 0;
		if( lngRemoveAtIndex > m_lngArraySize - 1 ) lngRemoveAtIndex = m_lngArraySize - 1;

		// Make a new array of size one smaller
		palngNewValues = new long[ GetSize( ) - 1 ];

		// Copy 1st half of values from old array into new array
		for( lngIndex = 0; lngIndex < lngRemoveAtIndex; lngIndex += 1 )
		{
			// Old-school C pointer way
			*( palngNewValues + lngIndex ) = *( m_palngValues + lngIndex );
		}

		// Copy 2nd half of values from old array into new array
		for( lngIndex = lngRemoveAtIndex + 1; lngIndex < GetSize( ); lngIndex += 1 )
		{
			// Old-school C pointer way
			*( palngNewValues + lngIndex - 1 ) = *( m_palngValues + lngIndex );
		}

		// Delete old array
		delete [] m_palngValues;
		m_palngValues = 0;

		// Assign new array
		m_palngValues = palngNewValues;

		// Assign size
		m_lngArraySize -= 1;
	}
}


// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Print all the values
// --------------------------------------------------------------------------------
void CResizableArray::Print( ) const
{
	Print( "Print Array" );
}


// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Print all the values
// --------------------------------------------------------------------------------
void CResizableArray::Print( const char* pstrCaption ) const
{
	long lngIndex = 0;

	// Caption
	cout << endl;
	cout << pstrCaption << " ----------" << endl;

	// Size not 0?
	if( m_lngArraySize > 0 )
	{

		// Print each cell
		for( lngIndex = 0; lngIndex < GetSize( ); lngIndex += 1 )
		{
			cout << "Location[ " << ( lngIndex + 1 ) << " ] = " 
				 << GetValueAt( lngIndex ) << endl;
		}
	}
	else
	{
		printf( "-Empty array\n" );
	}

	cout << endl;

}

