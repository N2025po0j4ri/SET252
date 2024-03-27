// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: A resizeable array class with all the inner workings hidden.
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Compiler Directives
// --------------------------------------------------------------------------------
#pragma once		// Only include this file once

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <iostream>
using namespace std;


class CResizableArray
{
	// --------------------------------------------------------------------------------
	// Constants
	// --------------------------------------------------------------------------------

	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
	public:			// Never make public properties.  
					// Make protected or private with public get/set methods

	protected:
			long m_lngArraySize;
			long* m_palngValues;

	private:

	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
	public:
			// Constructors
			CResizableArray( );
			CResizableArray( long lngInitialSize );
			CResizableArray( long lngInitialSize, long lngDefaultValue );
			CResizableArray( const CResizableArray &clsOriginalToCopy );

			// Destructor
			~CResizableArray( );

			// Assignment Operator
			void operator = ( const CResizableArray &clsOriginalToCopy );

			// Subscript Operator
			long &operator[ ]( long lngIndex );				// Set
			const long &operator[ ]( long lngIndex ) const;	// Get - read only

			// Plus Equal +=
			void operator += ( const CResizableArray &clsOriginalToAppend );

			// Plus +
			CResizableArray operator + ( const CResizableArray &clsRight ) const;

			// Set/Get Size
			void SetSize( long lngNewSize );
			void SetSize( long lngNewSize, long lngDefaultValue );
			long GetSize( ) const;

			// Set/Get Value
			void SetValueAt( long lngValue, long lngIndex );
			long GetValueAt( long lngIndex ) const;

			// Add to Front/End
			void AddValueToFront( long lngValueToAdd );
			void AddValueToEnd( long lngValueToAdd );
			
			// Insert At
			void InsertValueAt( long lngValueToInsert, long lngInsertAtIndex );

			// Remove At
			void RemoveAt( long lngRemoveAtIndex );

			// Print
			void Print( ) const;
			void Print( const char* pstrCaption ) const;

	protected:
			// Can't touch this
			void Initialize( long lngInitialSize, long lngDefaultValue );
			void DeepCopy( const CResizableArray &clsOriginalToCopy );
			void CleanUp( );

	private:

};
