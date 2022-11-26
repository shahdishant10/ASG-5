#pragma once

#include <iostream>//includes input-output stream to display output to console.
#include <fstream>//includes the file stream functions.
#include <string> //includes the string functions.
#include "BSTNode.h"

using namespace std;
//! Binary Search Tree  Class.
/*!
 Name of Class  : BST

 Author         : Dishant Shah

 Date Of Creation  : 21 Nov 2022

 Superclass     : None

 Subclass       : None

 Description    : This class stores the starting root node and pointer of left and right child.

*/
class BST {

private:
    /**
     @brief Insert the node in the binary MorseCode Tree.
     @param variableOne The Node.
     @param variableTwo character.
     @param varThree coded string.
     @author Dishant Shah
     @date 21 Nov 2022
 */
    void insert(BSTNode*& newNode, const char C, string Str)
    {
        if (newNode == nullptr) {
            BSTNode* pMem = new BSTNode(C);
            newNode = pMem;
        }

            for(int i=0;i<Str.size();i++)
           {

            if (Str[i]=='.') {
                Str.erase(0, 1);
                insert(newNode->getLeft(), C, Str);
            }
            else if (Str[i]=='-') {
                Str.erase(0, 1);
                insert(newNode->getRight(), C, Str);
              }

           }

             }

    /**
  @brief Prints the binary MorseCode Tree in pre-order.
  @param variableOne The Tree pointer.
  @author Dishant Shah
  @date 21 Nov 2022
*/
    void print(BSTNode* Tree)
    {
        if (Tree != nullptr) {

            cout << "Character: " << Tree->getChr() << endl;
            if (Tree->isLeft() || Tree->isRight())
            print(Tree->getLeft());
            if (Tree->isLeft() && Tree->isRight())
            print(Tree->getRight());
        }
    }


public:
    /**
        * A constructor.
        * Built the morse code tree using Morsecode.txt.
        */
    BST()
    {
        char C;
        string S;
        pHead = new BSTNode('*');
        file.open("Morsecode.txt");
        while (!file.eof()) {

            file >> C;
            file>> S;
            insert(C, S);


        }
    }

    /**
      * A  destructor.
      * closes the file after building the tree.
      */
    ~BST()
    {
        if (file.is_open())
        {

            file.close();
        }

    }

    /**
 @brief insert the node in the binary MorseCode Tree.
 @param variableOne character.
 @param variableTwo coded string.
 @author Dishant Shah
 @date 21 Nov 2022
*/
    void insert(const char newC, string str)
    {
       insert(pHead, newC, str);
    }

    /**
 @brief Print the binary MorseCode Tree in Pre-order.
 @author Dishant Shah
 @date 21 Nov 2022
*/
    void print()
    {
        print(pHead);
    }

    /**
 @brief Search the Morse code tree using the MorseCode to find the corresponding character.
 @param variableOne The Root node pointer.
 @param variableTwo coded string.
 @author Dishant Shah
 @date 21 Nov 2022
*/

   char search1(BSTNode* Tree, string c)
    {
       if (c == " " && Tree!=nullptr)
       {
           return Tree->getChr();
       }

           for (int i = 0; i < c.size(); i++)
           {
               if (c[i] == '.')
               {
                   c.erase(0, 1);
                   return search1(Tree->getLeft(), c);
               }
               else if (c[i] == '-')
               {
                   c.erase(0, 1);
                   return search1(Tree->getRight(), c);
               }
           }
           return ' ';
     }

   /**
 @brief Search the Morse code tree using the MorseCode to find the corresponding character.
 @param variableOne coded string.
 @author Dishant Shah
 @date 21 Nov 2022
*/
     char search(string a)
    {
       return search1(pHead, a);

    }
     /**
         * a public variable.
         * Root node.
         */
    BSTNode* pHead;
    /**
       * a public variable.
       * File sstream variable to access the Morsecode.txt.
       */
    fstream file;

};







