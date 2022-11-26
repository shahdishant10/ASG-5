#pragma once

#include <iostream>//includes input-output stream to display output to console.
#include <fstream>//includes the file stream functions.
#include <string>//includes the string functions.
#include <time.h>
#include<sstream>//includes the string stream functions.
#include<cstring>//includes the string functions.

using namespace std;
//! Binary Search Tree  Class.
/*!
 Name of Class  : BST

 Author         : Dishant Shah

 Date Of Creation  : 21 Nov 2022

 Superclass     : None

 Subclass       : None

 Description    : This class stores the node data and pointer of left and right child.

*/

class BSTNode {

public:
	/**
		* A constructor.
		* Sets the Character data, left and right child pointer.
		*/
	BSTNode(char c)
	{
		Char = c;
		pLeft = nullptr;
		pRight = nullptr;
	}
	/**
		* A  destructor.
		*
		*/
	~BSTNode() {}
	/**
	   @brief Gets the character data stored in the Node.
	   @return the character data.
	   @author Dishant Shah
	   @date 21 Nov 2022
   */
	char getChr()
	{
		return this->Char;
	}

	/**
	   @brief It returns true if it has left child or false if it has no left child.
	   @return boolean value.
	   @author Dishant Shah
	   @date 21 Nov 2022
   */
	bool isLeft()
	{
		if (pLeft != nullptr)
			return true;
		else
			return false;
	}

	/**
   @brief It returns true if it has right child or false if it has no right child.
   @return boolean value.
   @author Dishant Shah
   @date 21 Nov 2022
   */
	bool isRight()
	{
		if (pRight != nullptr)
			return true;
		else
			return false;
	}

	/**
   @brief It returns pointer of left child.
   @return pointer of the node.
   @author Dishant Shah
   @date 21 Nov 2022
*/
	BSTNode*& getLeft()
	{
		return this->pLeft;
	}

	/**
 @brief It returns pointer of Right child.
 @return pointer of the node.
 @author Dishant Shah
 @date 21 Nov 2022
*/
	BSTNode*& getRight()
	{
		return this->pRight;
	}


private:
	/**
	  * a private variable.
	  * character data.
	  */
	char Char;
	/**
	  * a private variable.
	  * Left Child.
	  */
	BSTNode* pLeft;
	/**
	  * a private variable.
	  * Right Child.
	  */
	BSTNode* pRight;

};




