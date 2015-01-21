#include<stdio.h>
#include<stdlib.h>

int main(){
	const int point = 500;
	const int seed = 149;
	double x,y;
	FILE *outputFile;
	char *fileName = "points.csv";

	srand(seed);
	outputFile = fopen(fileName, "w");
	
	for(int i = 0; i < point;){
		x = (double) (2.0 * rand() / (RAND_MAX + 1.0)) - 1;
		y = (double) (2.0 * rand() / (RAND_MAX + 1.0)) - 1;
		if ((x*x + y*y) <= 1){
			fprintf(outputFile, "%f,%f\n", x, y);
			i++;
		} 
	}
	fclose(outputFile);	
	
	return 0;
}
