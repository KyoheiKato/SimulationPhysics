#include<stdio.h>
#include<stdlib.h>

int main () {
	int points[3] = {100, 1000, 10000};
	int seeds[10] = {149, 193, 251, 383, 457, 503, 691, 761, 829, 991};
	const int pointsLen = sizeof points / sizeof points[0];
	const int seedsLen = sizeof seeds / sizeof seeds[0];
	double x,y;
	double hitNum, squSizeSum;
	const double pi = 3.14;
		
	for (int i = 0; i < pointsLen; i++) {
		squSizeSum = 0;
		for (int j = 0; j < seedsLen; j++) {
			srand(seeds[j]);
			hitNum = 0;
			for (int k = 0; k < points[i]; k++) {
				x = (double) (2.0 * rand() / (RAND_MAX + 1.0)) -1.0;
				y = (double) (2.0 * rand() / (RAND_MAX + 1.0)) -1.0;
				if ((x * x + y * y) <= 1) {
					hitNum++;
				}
			}
			squSizeSum += hitNum / points[i];
		}
		printf("point_num = %d\n", points[i]);
		printf("size_average = %f\n", squSizeSum / seedsLen);
		printf("pi_per_average = %f\n\n", (pi -squSizeSum / seedsLen) / pi);
	}

	return 0;
}
