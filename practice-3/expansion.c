#include<stdio.h>
#include<stdlib.h>

const double h = 3.5;
const double org = 50.0;
const double dt = 0.1;

const int nk = 20;

double move_planet(double initialPoint){
	double initialVelocity = h * initialPoint;
	initialPoint += org;
	for (int counter = 0; counter < nk; counter++){
		initialPoint = initialPoint + initialVelocity * dt;
	}
	
	return initialPoint;
}

int main(){
	const int point = 500;
	const int seed = 149;
	double x,y;
	FILE *beforeExpandFile, *afterExpandFile;
	char *beforeName = "before_points.csv";
	char *afterName = "after_points.csv";

	srand(seed);
	beforeExpandFile = fopen(beforeName, "w");
	afterExpandFile = fopen(afterName, "w");
	
	for(int i = 0; i < point;){
		x = (double) (10.0 * rand() / (RAND_MAX)) - 5;
		y = (double) (10.0 * rand() / (RAND_MAX)) - 5;
		if ((x*x + y*y) <= 25){
			fprintf(beforeExpandFile, "%f,%f\n", x + 50.0, y + 50.0);
			fprintf(afterExpandFile, "%f,", move_planet(x));
			fprintf(afterExpandFile, "%f\n", move_planet(y));
			i++;
		} 
	}

	fclose(beforeExpandFile);	
	fclose(afterExpandFile);
	
	return 0;
}
