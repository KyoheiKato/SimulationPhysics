#include<stdio.h>

double ro(double x, double y){
	return 6 * x - 3 * y;
}

int main(){
	const int nm = 2;
	const double G = 1.0;
	const double dx = 1.0;

	double phi[4][4] = {0};
	int converFlag[2][2] = {0};	
	double last_phi[4][4] = {0};
	
	phi[1][3] = 22.5;
	phi[2][3] = 36.0;
	phi[3][1] = -4.5;
	phi[3][2] = 9.0;

	while(1){
		for (int ix = 1; ix <= nm; ix++){
			for (int iy = 1; iy <= nm; iy++){
				double p1 = phi[ix+1][iy] + phi[ix-1][iy] + phi[ix][iy+1] + phi[ix][iy-1];
				double p2 = G * ro(ix, iy) * dx * dx; 
				phi[ix][iy] = p1 / 4 - p2 / 4;
				double diff = phi[ix][iy] - last_phi[ix][iy];
				printf("phi[%d][%d] = %f\n", ix, iy, phi[ix][iy]);
	
				if (diff  < 0.1 && diff > -0.1){
					converFlag[ix-1][iy-1] = 1;
				}else{
					converFlag[ix-1][iy-1] = 0;
				}
				last_phi[ix][iy] = phi[ix][iy];
			}
		}
		if (converFlag[0][0] && converFlag[0][1] &&
				converFlag[1][0] && converFlag[1][1]){
			break;
		}
	}
	
	for (int ix = 1; ix <= nm; ix++){
		for (int iy = 1; iy <= nm; iy++){
			printf("phi[%d][%d] = %f\n", ix, iy, phi[ix][iy]);
		}
	}

	return 0;
}	
