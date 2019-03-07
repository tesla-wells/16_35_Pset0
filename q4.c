#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Node structure

typedef struct Node {
	struct Node* upper;
	struct Node* lower;
	char* item;
} node; 

void insert(node* root, char* str) {
	if(strcmp(root->item, str) > 0){
		if(root->upper == NULL){
			node* newNode = malloc(sizeof(node));
			newNode->upper = NULL;
			newNode->lower = NULL;
			newNode->item = str;
			root->upper = newNode;
		} else {
			insert(root->upper, str);
		}
	} else {
		if(root->lower == NULL){
			node* newNode = malloc(sizeof(node));
			newNode->upper = NULL;
			newNode->lower = NULL;
			newNode->item = str;
			root->lower = newNode;
		} else {
			insert(root->lower, str);
		}
	}
}

void print_tree(node* root){
	if(root->lower != NULL){
		print_tree(root->lower);
	} 
	
	printf("%s ", root->item);
	
	if(root->upper != NULL){
		print_tree(root->upper);
	}
}

void free_tree(node* root){
	if (root!= NULL){
		free_tree(root->upper);
		free_tree(root->lower);
		free(root);
	}
}

int main(int argc, char** argv){
	node* root = malloc(sizeof(node));
	root->upper = NULL;
	root->lower = NULL;
	root->item = "";
	for(int i = 1; i < argc; i++){
		insert(root, argv[i]);
	}
	print_tree(root);
	free_tree(root);
}

