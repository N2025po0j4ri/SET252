// --------------------------------------------------------------------------------
// Name: CStack
// Abstract: This class ...
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------

//#pragma once
#include "CNode.h"

//Declare only once even if included multiple times
#ifndef CSTACK_H
#define CSTACK_H

template<typename GenericDataType>
class CStack
{

protected:
	CNode* m_pclsHeadNode;

public:			// Never make public properties.  
				// Make protected or private with public get/set methods
	CStack();
	CStack(const CStack& clsOriginalToCopy);	// Deep copy!
	~CStack();	// Clean up any allocated memory
	void operator=(const CStack& clsOriginalToCopy);	// Deep copy!

	void Push(GenericDataType intValue);	// Add 1 value to the top of the stack
	GenericDataType Pop(); // Remove 1 value from the top of the stack
	bool IsEmpty() const;	// Return true if head node pointer is zero
	void Print(const char* pstrCaption) const;	// This will print the whole list. 

protected:

	

private:
	
	//CNode m_pclsTailNode;
	
	void Initialize();	// Set class properties to zero.
	void DeepCopy(const CStack& clsOriginalToCopy);
	void CleanUp();				// Delete the list


};
//Name: Constructor
//Abstract: No parameter Constructor
template<typename GenericDataType>
CStack<GenericDataType>::CStack<GenericDataType>()	// Default constructor
{
	//isEmpty = true;
	Initialize();
}

//Name: Constructor
//Abstract: Deep copy
template<typename GenericDataType>
CStack<GenericDataType>::CStack<GenericDataType>(const CStack<GenericDataType>& clsOriginalToCopy)	// Deep copy!
{
	Initialize();
	*this = clsOriginalToCopy;
}

//Name: Destructor
//Abstract: calls clean up
template<typename GenericDataType>
CStack<GenericDataType>::~CStack<GenericDataType>() // Clean up any allocated memory
{
	CleanUp();
}
//Name: Initialize
//Abstract: executes initialization
template<typename GenericDataType>
void CStack<GenericDataType>::Initialize()
{
	m_pclsHeadNode = 0;
}

//Name: operator =
//Abstract: Deep copy
template<typename GenericDataType>
void CStack<GenericDataType>::operator = (const CStack<GenericDataType>& clsOriginalToCopy)	// Deep copy!
{
	if (this != &clsOriginalToCopy) {
		CleanUp();
		DeepCopy(clsOriginalToCopy);

	}
}
//Name: CleanUp
//Abstract: executes clean up
template<typename GenericDataType>
void CStack<GenericDataType>::CleanUp()
{
	while (IsEmpty() == false) {
		Pop();
	}
}
//Name: Push
//Abstract: pushes value to Stack
template<typename GenericDataType>
void CStack<GenericDataType>::Push(GenericDataType intValue)	// Add 1 value to the top of the stack
{

	CNode* pclsNewNode = 0;

	pclsNewNode = new CNode(intValue);

	pclsNewNode->SetNextNode(m_pclsHeadNode);
	m_pclsHeadNode = pclsNewNode; /*
	CNode* pclsNewNode = new CNode(intValue, m_pclsHeadNode);
	m_pclsHeadNode = pclsNewNode; */
}
//Name: Pop
//Abstract: removes value from Stack in LIFO order
template<typename GenericDataType>
GenericDataType CStack<GenericDataType>::Pop()	// Remove 1 value from the top of the stack
{
	GenericDataType intValue = 0;
	CNode* pclsNextNode = 0;

	// Empty List?
	if (IsEmpty() == false)
	{
		// No, get value
		intValue = m_pclsHeadNode->GetValue();

		// Get next
		pclsNextNode = m_pclsHeadNode->GetNextNode();

		// Delete
		delete m_pclsHeadNode;
		m_pclsHeadNode = 0;

		// Move to next
		m_pclsHeadNode = pclsNextNode;
	}
	return intValue;

}
//Name: IsEmpty
//Abstract: returns boolean telling if empty
template<typename GenericDataType>
bool CStack<GenericDataType>::IsEmpty() const	// Return true if head node pointer is zero
{
	bool blnIsEmty = false;
	if (m_pclsHeadNode == 0) {
		blnIsEmty = true;
	}
	return blnIsEmty;
}
//Name: Print
//Abstract: Prints Stack values with index/location
template<typename GenericDataType>
void CStack<GenericDataType>::Print(const char* pstrCaption) const	// This will print the whole list.
{
	int intIndex = 0;
	CNode* pudtCurrentNode = 0; // m_pclsHeadNode;

	cout << pstrCaption << "------------------------" << endl;

	//CNode pudtNextNode;
	//printf("\n");
	//printf("%s\n", "val");
	//printf("----------------------------------------\n");
	if (IsEmpty() == false) {
		// Start at the top
		pudtCurrentNode = m_pclsHeadNode;
		while (pudtCurrentNode != 0)
		{
			// Count
			intIndex += 1;

			// Display current value
			cout << "Value at node #" << intIndex
				<< " is " << pudtCurrentNode->GetValue() << endl;

			// Get next node


			// Move to next node
			pudtCurrentNode = pudtCurrentNode->GetNextNode();
		}
	}
	else {
		cout << "emty stack" << endl;
	}
}
// It is non-destructive.  
// You can call it over and over

//Name: DeepCopy
//Abstract: executes DeepCopy
template<typename GenericDataType>
void CStack<GenericDataType>::DeepCopy(const CStack<GenericDataType>& clsOriginalToCopy)
{
	CNode* pclsCurrentOriginal = 0;
	GenericDataType intValue = 0;
	CNode* pclsNextNode = 0;

	//Get top of original to copy
	pclsCurrentOriginal = clsOriginalToCopy.m_pclsHeadNode;

	while (pclsCurrentOriginal != 0)
	{
		//Get Value
		intValue = pclsCurrentOriginal->GetValue();

		// Copy/Push value
		Push(intValue);

		// Get next
		pclsNextNode = pclsCurrentOriginal->GetNextNode();

		//Move to next
		pclsCurrentOriginal = pclsNextNode;
	}

	//return clsOriginalToCopy;
}


#endif