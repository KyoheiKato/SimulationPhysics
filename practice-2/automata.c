#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<memory.h>

#define STR_LEN 256

void initIndexes(int *indexes){
	for (int i = 0; i < 20; i++){
		indexes[i] = i;
	}
}

void swapElement(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void initCell(int *indexes){
	for (int i = 0; i < 10000; i++){
		int index1 = (int)(20.0 * rand() / (RAND_MAX + 1.0));
		int index2 = (int)(20.0 * rand() / (RAND_MAX + 1.0));
		if (index1 != index2){
			swapElement(&indexes[index1], &indexes[index2]);
		}
	}
}

void initLine(int *line, int indexes[], int density){
	for (int i = 0; i < 20; i++){
		line[i] = 0;
	}
	for (int i = 0; i < density; i++){
		line[indexes[i]] = 1;
	}
}

 

int checkAround(int a, int b, int c){
	char key1[STR_LEN] = {'\0'}, key2[STR_LEN] = {'\0'}, key3[STR_LEN] = {'\0'};
	char keyPattern[STR_LEN] = {'\0'};
	
	sprintf(key1, "%d", a);
	sprintf(key2, "%d", b);
	sprintf(key3, "%d", c);
	
	strcat(keyPattern, key1);
	strcat(keyPattern, key2);
	strcat(keyPattern, key3);

	if (!strcmp(keyPattern, "000")){
		return 0;
	}else if(!strcmp(keyPattern, "001")){
		return 0;
	}else if(!strcmp(keyPattern, "010")){
		return 0;
	}else if(!strcmp(keyPattern, "110")){
		return 0;
	}else if(!strcmp(keyPattern, "011")){
		return 1;
	}else if(!strcmp(keyPattern, "100")){
		return 1;
	}else if(!strcmp(keyPattern, "101")){
		return 1;
	}else if(!strcmp(keyPattern, "111")){
		return 1;
	}else{
		printf("exception value = %s\n", keyPattern); 
		return 0;
	}
}

void automate(int *line){
	int tmpLine[20];
	memcpy(tmpLine, line, sizeof(tmpLine));
	for (int i = 0; i < 20; i++){
		if (i == 0){
			line[i] = checkAround(tmpLine[19], tmpLine[0], tmpLine[1]);
		}else if(i == 19){
			line[i] = checkAround(tmpLine[18], tmpLine[19], tmpLine[0]);
		}else{
			line[i] = checkAround(tmpLine[i-1], tmpLine[i], tmpLine[i+1]);
		}
	}
}

void printLine(int line[]){
	for (int i = 0; i < 20; i++){
		//printf("%d ", line[i]);
		if(line[i] == 1){
			printf("* ");
		}else{
			printf("- ");
		} 
	}
}

void printLines(int *line){
	for (int i = 0; i < 21; i++){
		printf("t = %2d: ", i);
		printLine(line);
		automate(line);
		printf("\n");
	}
}

int main(){
	int indexes[20]; 
	int line[20] = {};
	const int density[3] = {6, 10, 14};
	
	srand(149);
	initIndexes(indexes);
	initCell(indexes);
	
	
	for (int i = 0; i < 3; i++){
		initLine(line, indexes, density[i]);
		printLines(line);
	}

	return 0;
}
