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

}

void print_tree(node* root){

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
	for(int i = 2; i < argc; i++){
//		insert(root, argv[i])
	}
//	print_tree(root);
//	free_tree(root);
}

