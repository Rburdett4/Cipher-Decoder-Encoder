// CipherDecoder.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
void Encode();
void Decode();
int main()
{
	std::cout << "Caesarian Cipher Program!" << std::endl << std::endl;
	std::cout << "Select your preferred action: " << std::endl;
	std::cout << "1: Encode Text" << std::endl;
	std::cout << "2: Decode Text" << std::endl;
	std::cout << "0: Quit" << std::endl << std::endl;
	std::cout << "Number: ";
	int entry;
	std::cin >> entry;
	while (entry != 0)
	{
		switch (entry)
		{
			case 1:
			{
				Encode();
				break;
			}
			case 2:
			{
				Decode();
				break;
			}
		}
		std::cout << "Select your preferred action: " << std::endl;
		std::cout << "1: Encode Text" << std::endl;
		std::cout << "2: Decode Text" << std::endl;
		std::cout << "0: Quit" << std::endl << std::endl;
		std::cout << "Number: ";
		std::cin >> entry;
	}
}

void Encode()
{ 
	std::cout << std::endl << "Enter string: " << std::endl;
	std::string x;
	std::cin.ignore();
	std::getline(std::cin, x);
	std::cout << std::endl << "Enter shift amount: "; 
	int shift;
	std::cin >> shift;
	std::string newBuild;
	for (size_t i = 0; i < x.length(); i++)
	{
		char ascii = x.at(i) + shift;
		newBuild += ascii;
	} 
	std::cout << newBuild << std::endl;
	//write/read with file?-----------------------------------------------------------------
}

void Decode()
{
	std::cout << std::endl << "Enter the English string to be decoded: " << std::endl; 
	std::cin.ignore();
	std::string input;
	std::getline(std::cin, input);
	double freq[26] = {8.12, 1.49, 2.71, 4.32, 12.02, 2.3, 2.03, 5.92, 7.31, .1, .69, 3.98, 2.61, 6.95, 7.68, 1.82, .11, 6.02, 6.28, 9.10, 2.88, 1.11, 2.09, .17, 2.11, .07};
	for (int i = 0; i < 26; i++) 
	{
		std::string newBuild;
		int finalVal = 0;
		for (size_t j = 0; j < input.length(); j++)			//shift
		{
			char ascii = input.at(j) - i;
			newBuild += ascii;
			int freqVal = ((int)(ascii - 19) % 26); 
			int tempVal = freq[freqVal];
			finalVal += tempVal;
		}
		if (finalVal < 0)
		{
			finalVal = 0;
		}

		//std::cout << newBuild << std::setw(30) << finalVal << std::endl;
		GiveResults();
	}
}



void GiveResults()
{

}