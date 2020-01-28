#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::cout << "\t***Memory Machine***" << std::endl;
	std::cout << "Enter what you need remembered: ";
	std::string stuffToRemember;
	std::getline(std::cin, stuffToRemember);
	//Create object file handle
	std::ifstream input_file;
	std::ofstream obj_file_handle;
	
	//Opening file
	input_file.open("CPP_Reference.txt");
	obj_file_handle.open("memory.txt");
	//Using file stream
	std::cout << "Uploading '" << stuffToRemember << "' to file..." <<std::endl;
	//Writing to file
	obj_file_handle << stuffToRemember;
	std::cout << "File is written" << std::endl;
	//Closing file
	std::cout << "Closing file..." << std::endl;
	obj_file_handle.close();
	std::cout << "File closed" << std::endl;
}