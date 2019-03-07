#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** parameters){

	//check to make sure you have the right number of arguments. Remember that the file name counts as 1 argument
	
	if(argc < 4){
		printf("Too few arguments. Please give paramters <number> <operator> <number");
	}

	//convert the numerical arguments from strings to numbers
	float flone = atof(parameters[1]);
	float fltwo = atof(parameters[3]);
	char operation = parameters[2][0];	

	//maybe add something here to make sure that the operation provided isn't larger than 1 char

	//use a switch statement to figure out which of the operations you're performing 
	switch(operation){
		case '+':
			printf("%.3f", (flone + fltwo));
			return 0;
			break;
		case '-':
			printf("%.3f", (flone - fltwo));
			return 0;
			break;
		case '*':
		case 'x':
		case 'X':
			printf("%.3f", flone * fltwo);
			return 0;
			break;
		case '/':
			printf("%.3f", flone/fltwo);
			return 0;
			break;
		default:
			printf("Operation not permitted. Please use +, -, *, x, X, or /");
			return 1;		
			break;
	}
}

