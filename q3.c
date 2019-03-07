#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** parameters){

	//This block counts the number of leters in the list of words submitted
	int numberOfChars = 0;
	for (int wordNum = 1; wordNum < argc; wordNum++){
		numberOfChars += strlen(parameters[wordNum]);
	}

	//After you know how many letters there are, you can properly allocate space to save them as a concatenated string of the letters AND a string that is printable
	char* allCharacters = malloc(numberOfChars + 1);
	char* fullPrintThing = malloc(numberOfChars + 1 + argc);	

	for (int wordNum = 1; wordNum < argc; wordNum ++){
		strcat(allCharacters, parameters[wordNum]);
		strcat(fullPrintThing, parameters[wordNum]);
		if(wordNum + 1 != argc){
			strcat(fullPrintThing, " ");
		}
	}

	//You're going to count up through the string and count down through the string until these points converge
	int countDown = numberOfChars - 1;
	for (int countUp = 0; countUp < countDown; countUp++){
		
		if(allCharacters[countUp] != allCharacters[countDown]){
			printf("\"%s\" is NOT a palindrome!\n", fullPrintThing);
			return 1;
		}
		
		countDown = numberOfChars - countUp - 2;		
	}

	printf("\"%s\" is a palindrome!\n", fullPrintThing);
	return 0;

}
