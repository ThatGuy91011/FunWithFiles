#include <iostream>
#include <fstream>
#include <string>

int keywords, reserved;

int main()
{
	/**
	std::cout << "\t***Memory Machine***" << std::endl;
	std::cout << "Enter what you need remembered: ";
	std::string stuffToRemember;
	std::getline(std::cin, stuffToRemember);
	//Create object file handle
	std::ofstream obj_file_handle;
	
	//Opening file 
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
	**/
	//Read files
	std::fstream file;
	std::string word, filename;
	std::ofstream obj_file_handle;
	obj_file_handle.open("CPP_Enhanced_Reference.txt");
	
	filename = "CPP_Reference.txt";
	file.open(filename.c_str());

	while (file >> word)
	{
		if (word == "-")
		{
			keywords += 1;
		}

		if (word == ">")
		{
			word = "\n";
		}

		if (word == "Reserved")
		{
			break;
		}
		obj_file_handle << word << " ";
	}

	while (file >> word)
	{
		if (word == "-")
		{
			reserved += 1;
		}

		if (word == ">")
		{
			word = "\n";
		}
		obj_file_handle << word << " ";
	}
	std::cout << "\n\nKeywords: " << keywords << std::endl << "Reserved Words: " << reserved << std::endl;
}