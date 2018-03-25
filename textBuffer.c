#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN_ROW 100
#define MAX_LEN_COL 50

//Returns the number of lines of the initial text file
//Inserts each line into an array of char*
int fillBuffer(char* file, char* textBuffer[], int lineCount){
	FILE *in;
	in = fopen(file, "r");
	int i;
	//Allocate memory for each pointer of the buffer
	for (i = 0; i < MAX_LEN_ROW; i++){
		textBuffer[i] = malloc(MAX_LEN_ROW * sizeof *textBuffer);
	}
	
	//Inserts the line into textBuffer[lineCount] and incrememnts lineCount
	while (lineCount < MAX_LEN_ROW && fgets(textBuffer[lineCount], MAX_LEN_COL, in)){
		lineCount++;	
	}
	return lineCount;
}

struct buffer{
	char* textBuffer[MAX_LEN_ROW];
	char file[20];
	int lineCount;
};
	
int main(){
	//Creating a ptr to the buffer struct and allocating memory
	struct buffer* ptr = (struct buffer *)malloc(sizeof(struct buffer));
	
	//initialize variables of the struct buffer
	ptr->lineCount = 0;
	char* file = ptr->file;
	file = "textfile.txt";
	char** textBufferPtr = ptr->textBuffer;

	//Pass in those values
	//Maybe the lineCount is useful?
	//ptr->textBuffer should have everything
	ptr->lineCount = fillBuffer(file, textBufferPtr, ptr->lineCount);
	
	return 0;
}	



