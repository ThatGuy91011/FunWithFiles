#include <iostream>
#include <fstream>
#include <string>

int keywords, reserved;

int main()
{
	//Creating a variable to hold the original file
	std::fstream file;
	//Strings to hold each individual word of the file and the name of the file
	std::string word, filename;
	//Variable to hold the output file
	std::ofstream obj_file_handle;

	//Name of the original file
	filename = "CPP_Reference.txt";
	
	std::cout << "\tOpening original file..." << std::endl;
	file.open(filename.c_str());

	std::cout << "\tCounting Keywords..." << std::endl;

	//For each word in the file...
	while (file >> word)
	{
		//Counts keywords
		if (word == "-")
		{
			keywords += 1;
		}

		//Move on to the next set of words
		if (word == "Reserved")
		{
			break;
		}
		
	}
	std::cout << "\tCounting Reserved Keywords..." << std::endl;

	//Counts reserved words
	while (file >> word)
	{
		if (word == "-")
		{
			reserved += 1;
		}
	}
	std::cout << "\tReopening old file..." << std::endl;

	//Reopens file to start at the beginning
	file.close();
	file.open(filename.c_str());
	
	std::cout << "\tOpening New File..." << std::endl;
	//Creates a file to hold new values
	obj_file_handle.open("CPP_Enhanced_Reference.txt");
	
	std::cout << "\tWriting to file..." << std::endl;
	obj_file_handle << "Keywords Defined: " << keywords << std::endl;

	//Fore each word...
	while (file >> word)
	{
		//Basic formatting to make the new file look nice, each new line in the original file is represented by a >
		if (word == ">")
		{
			word = "\n";
		}

		//Moves on to the next set of words
		if (word == "Reserved")
		{
			break;
		}

		//Writes each word to the file
		obj_file_handle << word << " ";
	}

	obj_file_handle << "Reserved Keywords Defined: " << reserved << std::endl;
	while (file >> word)
	{
		if (word == ">")
		{
			word = "\n";
		}
		obj_file_handle << word << " "; 
	}

	//Closes both files to finish the program
	std::cout << "\tClosing old file..." << std::endl;
	file.close();
	
	std::cout << "\tClosing new file..." << std::endl;
	obj_file_handle.close();
	
	std::cout << "\tAll done, have a nice day" << std::endl;
}