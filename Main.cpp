/**
 Name of File : Main.cpp

 Author       : Dishant Shah

 Date         : 21 Nov 2022
**/

#include "Header.h"   //includes the Header.h file

int main()

{
	string message,encode;   //variable message, encode of string type.
	BST Tree;  //MorseCode Tree.
	cout << "Enter a message"<<endl;
	getline(cin, message, '\n');

	transform(message.begin(), message.end(), message.begin(), ::tolower);  //Switching all the letters to lowercase.
	encode_message(message, encode);   //Encoding the message by calling the function.

	cout << "Coded message" << endl;
	cout << encode<<endl;

	cout << "Decoded message " << endl;
	decode_message(Tree, encode);  //Decoding the message by calling the function.

	return 0;
}

