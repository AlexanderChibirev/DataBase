// DBLab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> ParseFile(std::string fileName, std::string userName, bool &wasError)
{
	std::ifstream  inputFile(fileName);
	std::vector<std::string> arrayRecordId;
	if (!inputFile.is_open())
	{
		wasError = true;
		return arrayRecordId;
	}
	std::string lineStr;
	while (!inputFile.eof())
	{
		std::getline(inputFile, lineStr);
		if (lineStr.find(userName) != std::string::npos)
		{
			int i = 0;
			std::string recordId = " ";
			while (lineStr[i] != ',')
			{
				recordId += lineStr[i];
				++i;
			}
			arrayRecordId.push_back(recordId);
		}
	}
	return arrayRecordId;
}

void OutputResult(std::vector<std::string> arrayRecordId)
{
	std::cout << "Record id: ";
	for (int i = 0; i < arrayRecordId.size(); ++i) {
		std::cout << arrayRecordId[i];
		if (i < arrayRecordId.size() - 1) {
			std::cout << ",";
		}
	}
}

int main()
{
	std::cout << "Enter username: ";
	std::string userName;
	std::cin >> userName;
	bool wasError = false;
	std::vector<std::string> arrayRecordId = ParseFile("db.csv", "Peter Winter-Smith", wasError);
	if (wasError) {
		std::cout << "Error in open file ";
		return 1;
	}
	OutputResult(arrayRecordId);
	return 0;
}