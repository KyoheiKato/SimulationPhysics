#include<stdio.h>
#include<stdlib.h>

int main(){
		int pointNum;
		int seed;
		double x,y;
		printf("seed :");
		scanf("%d", &seed);
		printf("point_num:");
		scanf("%d", &pointNum);
		srand(seed);
		FILE *outputFile;
		char *fileName;
		fileName = "points.csv";
		outputFile = fopen(fileName, "w");
		for(int i = 0; i < pointNum;){
				x = (double) (3.0 * rand() / (RAND_MAX + 1.0)) - 1;
				y = (double) (3.0 * rand() / (RAND_MAX + 1.0)) - 1;
				if ((x*x + y*y) <= 1){
						fprintf(outputFile, "%f,%f\n", x, y);
						i++;
				} 
		}
		fclose(outputFile);	
	
		return 0;
}
