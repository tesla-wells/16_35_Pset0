#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** parameters){

	int numberOfChars = 0;
	
	for (int wordNum = 1; wordNum < argc; wordNum++){
		numberOfChars += strlen(parameters[wordNum]);
	}

	char* allCharacters = malloc(numberOfChars + 1);
	char* fullPrintThing = malloc(numberOfChars + 1 + argc);	

	for (int wordNum = 1; wordNum < argc; wordNum ++){
		strcat(allCharacters, parameters[wordNum]);
		strcat(fullPrintThing, parameters[wordNum]);
		if(wordNum + 1 != argc){
			strcat(fullPrintThing, " ");
		}
	}

	int mismatchFlag = 0;
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
