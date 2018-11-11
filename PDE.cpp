#include <iostream>
#include <stdio.h>
#include <cmath>

void fronteras_fijas();
void fronteras_abiertas();

int main(){

	fronteras_abiertas();

	return 0;
}

void fronteras_fijas(){

	static float temperatura[50][50];
	float delta_x = 1.0;
	float delta_y = 1.0;
	float nu = 1.62/(820*0.0271);
	float delta_t = 0.1;

	//condiciones iniciales
	for(int i=0; i<50; i++){
		for(int j=0; j<50; j++){

			if(i<19 or i>29){
				temperatura[i][j] = 10.0;
			}
			else{
				temperatura[i][j] = 100.0;
			}
			if(i == 0 or i == 49){
				temperatura[i][j] = 10.0;
			}
			if((j == 0 or j == 49) and (i<19 or i>29)){
				temperatura[i][j] = 10.0;
			}

			std::cout << temperatura[i][j] << ",";
		}

		std::cout << std::endl;
	}

	//iteraciones

	static float temperatura_futuro[50][50];
	int contador = 0;	
	
	for(int t=0; t<=10000; t++){
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){

				temperatura_futuro[i][j] = temperatura[i][j];
				if(i!=0 and i!=49 and j!=0 and j!=49 and (i<19 or i>29)){
					temperatura_futuro[i][j] = (nu*delta_t)*(((temperatura[i+1][j]+temperatura[i-1][j]-(2*temperatura[i][j]))/(delta_x*delta_x))+((temperatura[i][j+1]+temperatura[i][j-1]-(2*temperatura[i][j]))/(delta_y*delta_y))) + temperatura[i][j];
				}
				temperatura[i][j] = temperatura_futuro[i][j];
				if(contador == 2500){
					std::cout << temperatura[i][j] << ",";
				}
			}

			if(contador == 2500){
				std::cout << std::endl;
			}
		}

		if(contador == 2500){
			contador = 0;
		}
		else{
			contador = contador + 1;
		}
	}
}

void fronteras_abiertas(){

	static float temperatura[50][50];
	float delta_x = 1.0;
	float delta_y = 1.0;
	float nu = 1.62/(820*0.0271);
	float delta_t = 0.1;

	//condiciones iniciales
	for(int i=0; i<50; i++){
		for(int j=0; j<50; j++){

			if(i<19 or i>29){
				temperatura[i][j] = 0.0;
			}
			else{
				temperatura[i][j] = 100.0;
			}
			std::cout << temperatura[i][j] << ",";
		}

		std::cout << std::endl;
	}

	//iteraciones

	static float temperatura_futuro[50][50];
	int contador = 0;	
	
	for(int t=0; t<=10000; t++){
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){

				temperatura_futuro[i][j] = temperatura[i][j];
				if(i!=0 and i!=49 and j!=0 and j!=49 and (i<19 or i>29)){
					temperatura_futuro[i][j] = (nu*delta_t)*(((temperatura[i+1][j]+temperatura[i-1][j]-(2*temperatura[i][j]))/(delta_x*delta_x))+((temperatura[i][j+1]+temperatura[i][j-1]-(2*temperatura[i][j]))/(delta_y*delta_y))) + temperatura[i][j];
				}
				for(int k=0; k<50; k++){
					temperatura_futuro[0][i] = temperatura_futuro[1][i];
					temperatura_futuro[49][i] = temperatura_futuro[48][i];
				}
				for(int l=1; l<49; l++){
					temperatura_futuro[l][0] = temperatura_futuro[l][1];
					temperatura_futuro[l][49] = temperatura_futuro[l][48];
				}
				temperatura[i][j] = temperatura_futuro[i][j];
				if(contador == 2500){
					std::cout << temperatura[i][j] << ",";
				}
			}

			if(contador == 2500 and i!=49){
				std::cout << std::endl;
			}
		}

		if(contador == 2500){
			contador = 0;
		}
		else{
			contador = contador + 1;
		}
	}
}
	

