//File: f7.cpp
//Project: SENG1000, Focused Assignment 7.
//Programmer: Robin Wagubi.
//First version: 13th November 2023.
//Description: program to give you practice at creating text and binary files.



#include<stdio.h>
#pragma warning(disable: 4996)

const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

//Main function
int main() {

	FILE* textFile = fopen("myTextFile.txt", "w");

	//Error checking
	if (textFile != NULL) {

		fprintf(textFile, "This is line 1\n");

		fprintf(textFile, "This is line 2\n");

		//Closing the text file
		fclose(textFile);

		printf("The file has been created.\n");
	}

	else {

		printf("Error: The file has not been created.\n");

	}


	//open binary file
	FILE* binaryFile = fopen("myBinaryFile.data", "wb");


	if (binaryFile == NULL) {
		printf("Error while opening the file. \n");

		return 1;
	}
	size_t binaryData = fwrite(kBinaryData, sizeof(unsigned short), sizeof(kBinaryData) / sizeof(unsigned short), binaryFile);

	if (binaryData != sizeof(kBinaryData) / sizeof(unsigned short)) {

		printf("Error\n");


		//closing binary file.
		fclose(binaryFile);

		return 1;

		fclose(binaryFile);
		printf("File has been created. \n");

		return 0;
	}


	return 0;
}// End of main