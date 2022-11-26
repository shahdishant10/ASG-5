#pragma once
#include "BinaryST.h"
#include <iostream>//includes input-output stream to display output to console.
#include <fstream>//includes the file stream functions.
#include <algorithm>//for using the algorithm header for filling random values in vector.
#include<vector>//for declaring vector and using vector functions.


using namespace std;
/**
 @brief decode the message from the tree and give the character related to the morse code.
 @param variableOne Binary tree.
 @param variableTwo encoded message.
 @author Dishant Shah
 @date 21 Nov 2022
*/
void decode_message(BST& Tree, string encode)
{
	vector<string> words{};
	char del = ' ';
	stringstream sstream(encode);
	string word;
	while (getline(sstream, word, del))
	{
		if (word != " ")
			words.push_back(word);
	}
	for (const auto& decode : words) {

		char a = Tree.search(decode + " ");
		if (a == '*')
		{
			a = ' ';
		}
		cout << a;
	}
	cout << endl;
}

/**
 @brief encode the message return the encoding message.
 @param variableOne the message to encode.
 @param variableTwo the encoded string.
 @author Dishant Shah
 @date 21 Nov 2022
*/
void encode_message(string& message, string& encode)
{
	for (int i = 0; i < message.size(); i++)
	{
		ifstream infile;
		infile.open("Morsecode.txt");
		char a = message[i];
		if (a == ' ')
		{
			encode = encode + a;
		}

		while (!infile.eof())
		{
			string S;
			char C;
			infile >> C;
			infile >> S;

			if (a == C)
			{
				string b = " ";
				encode = encode + S;
				encode = encode + b;
			}

		}

		infile.close();
	}

}
