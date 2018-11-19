#include <iostream>
#include <stdio.h>
#include <cmath>
#include <fstream>

void fronteras_fijas();
void fronteras_abiertas();
void fronteras_periodicas();

int main(){
	
	fronteras_fijas();
	fronteras_abiertas();
	fronteras_periodicas();
	
	return 0;
}

void fronteras_fijas(){

	std::ofstream datos;
	datos.open("PDE.dat", std::ios::out | std::ios::app);

	static float temperatura[50][50];
	float delta_x = 0.01;
	float delta_y = 0.01;
	float nu = 1.62/(820*2710);
	float delta_t = 0.1*delta_x*delta_y/nu;

	//condiciones iniciales
	for(int i=0; i<50; i++){
		for(int j=0; j<50; j++){

			if((i-25)*(i-25)+(j-25)*(j-25) <= 25){
				temperatura[i][j] = 100.0;
			}
			else{
				temperatura[i][j] = 10.0;
			}
			if(j!=49){
				datos << temperatura[i][j] << ",";
			}
			else{
				datos << temperatura[i][j];
			}
		}

		datos << std::endl;
		float promedio_0 = 0.0;
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){
				promedio_0 = promedio_0 + temperatura[i][j];
			}
		}
		if(i == 49){
			datos << 0 << "," << promedio_0/250.0;
			
			for(int m=0; m<49; m++){
				if(m != 48){
					datos << 0 << ",";
				}
				else{
					datos << 0 << std::endl;
				}
			}
		}
	}

	//iteraciones

	static float temperatura_futuro[50][50];
	int contador = 0;	
	
	for(int t=0; t<=1000; t++){
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){

				temperatura_futuro[i][j] = temperatura[i][j];
				if(i!=0 and i!=49 and j!=0 and j!=49 and ((i-25)*(i-25)+(j-25)*(j-25) > 25)){
					temperatura_futuro[i][j] = (nu*delta_t)*(((temperatura[i+1][j]+temperatura[i-1][j]-(2*temperatura[i][j]))/(delta_x*delta_x))+((temperatura[i][j+1]+temperatura[i][j-1]-(2*temperatura[i][j]))/(delta_y*delta_y))) + temperatura[i][j];
				}
				if(contador == 250 and j!=49){
					datos << temperatura_futuro[i][j] << ",";
				}
				else if(contador == 250 and j == 49){
					datos << temperatura_futuro[i][j];
				}				
			}

			if(contador == 250){
				datos << std::endl;
				
				float promedio = 0.0;
				for(int i=0; i<50; i++){
					for(int j=0; j<50; j++){
						promedio = promedio + temperatura_futuro[i][j];
					}
				}
				if(i == 49){
					datos << t*delta_t << "," << promedio/250.0;

					for(int m=0; m<49; m++){
						if(m != 48){
							datos << 0 << ",";
						}
						else{
							datos << 0 << std::endl;
						}
					}
				}
			}
		}

		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){
				temperatura[i][j] = temperatura_futuro[i][j];
			}
		}

		if(contador == 250){
			contador = 0;
		}
		else{
			contador = contador + 1;
		}
	}

	datos.close();
}

void fronteras_abiertas(){

	std::ofstream datos;
	datos.open("PDE.dat", std::ios::out | std::ios::app);

	static float temperatura[50][50];
	float delta_x = 0.01;
	float delta_y = 0.01;
	float nu = 1.62/(820*2710);
	float delta_t = 0.1*delta_x*delta_y/nu;

	//condiciones iniciales
	for(int i=0; i<50; i++){
		for(int j=0; j<50; j++){

			if((i-25)*(i-25)+(j-25)*(j-25) <= 25){
				temperatura[i][j] = 100.0;
			}
			else{
				temperatura[i][j] = 10.0;
			}
			if(j!=49){
				datos << temperatura[i][j] << ",";
			}
			else{
				datos << temperatura[i][j];
			}
		}

		datos << std::endl;
		float promedio_0 = 0.0;
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){
				promedio_0 = promedio_0 + temperatura[i][j];
			}
		}
		if(i == 49){
			datos << 0 << "," << promedio_0/250.0;

			for(int m=0; m<49; m++){
				if(m != 48){
					datos << 0 << ",";
				}
				else{
					datos << 0 << std::endl;
				}
			}
		}
	}

	//iteraciones

	static float temperatura_futuro[50][50];
	int contador = 0;	
	
	for(int t=0; t<=1000; t++){
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){

				temperatura_futuro[i][j] = temperatura[i][j];
				if(i!=0 and i!=49 and j!=0 and j!=49 and ((i-25)*(i-25)+(j-25)*(j-25) > 25)){
					temperatura_futuro[i][j] = (nu*delta_t)*(((temperatura[i+1][j]+temperatura[i-1][j]-(2*temperatura[i][j]))/(delta_x*delta_x))+((temperatura[i][j+1]+temperatura[i][j-1]-(2*temperatura[i][j]))/(delta_y*delta_y))) + temperatura[i][j];
				}
				if(contador == 250 and j!=49){
					datos << temperatura_futuro[i][j] << ",";
				}
				else if(contador == 250 and j == 49){
					datos << temperatura_futuro[i][j];
				}
			}

			if(contador == 250){
				datos << std::endl;
				
				float promedio = 0.0;
				for(int i=0; i<50; i++){
					for(int j=0; j<50; j++){
						promedio = promedio + temperatura_futuro[i][j];
					}
				}
				if(i == 49){
					datos << t*delta_t << "," << promedio/250.0;
					for(int m=0; m<49; m++){
						if(m != 48){
							datos << 0 << ",";
						}
						else{
							datos << 0 << std::endl;
						}
					}
				}
			}
		}
		for(int k=0; k<50; k++){
			temperatura_futuro[0][k] = temperatura_futuro[1][k];
			temperatura_futuro[49][k] = temperatura_futuro[48][k];
		}
		for(int l=1; l<49; l++){
			temperatura_futuro[l][0] = temperatura_futuro[l][1];
			temperatura_futuro[l][49] = temperatura_futuro[l][48];
		}
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){
				temperatura[i][j] = temperatura_futuro[i][j];
			}
		}
		if(contador == 250){
			contador = 0;
		}
		else{
			contador = contador + 1;
		}
	}

	datos.close();
}
	
void fronteras_periodicas(){

	std::ofstream datos;
	datos.open("PDE.dat", std::ios::out | std::ios::app);

	static float temperatura[50][50];
	float delta_x = 0.01;
	float delta_y = 0.01;
	float nu = 1.62/(820*2710);
	float delta_t = 0.1*delta_x*delta_y/nu;

	//condiciones iniciales
	for(int i=0; i<50; i++){
		for(int j=0; j<50; j++){

			if((i-25)*(i-25)+(j-25)*(j-25) <= 25){
				temperatura[i][j] = 100.0;
			}
			else{
				temperatura[i][j] = 10.0;
			}
			if(j!=49){
				datos << temperatura[i][j] << ",";
			}
			else{
				datos << temperatura[i][j];
			}
		}

		datos << std::endl;
		float promedio_0 = 0.0;
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){
				promedio_0 = promedio_0 + temperatura[i][j];
			}
		}
		if(i == 49){
			datos << 0 << "," << promedio_0/250.0;
			for(int m=0; m<49; m++){
				if(m != 48){
					datos << 0 << ",";
				}
				else{
					datos << 0 << std::endl;
				}
			}
		}
	}

	//iteraciones

	static float temperatura_futuro[50][50];
	int contador = 0;	
	
	for(int t=0; t<=1000; t++){
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){

				temperatura_futuro[i][j] = temperatura[i][j];
				if(i!=0 and j!=0 and ((i-25)*(i-25)+(j-25)*(j-25) > 25)){
					temperatura_futuro[i][j] = (nu*delta_t)*(((temperatura[i+1][j]+temperatura[i-1][j]-(2*temperatura[i][j]))/(delta_x*delta_x))+((temperatura[i][j+1]+temperatura[i][j-1]-(2*temperatura[i][j]))/(delta_y*delta_y))) + temperatura[i][j];
				}
				if(contador == 250 and j!=49){
					datos << temperatura_futuro[i][j] << ",";
				}
				else if(contador == 250 and j == 49){
					datos << temperatura_futuro[i][j];
				}
			}

			if(contador == 250){
				datos << std::endl;
				
				float promedio = 0.0;
				for(int i=0; i<50; i++){
					for(int j=0; j<50; j++){
						promedio = promedio + temperatura_futuro[i][j];
					}
				}
				if(i == 49){
					datos << t*delta_t << "," << promedio/250.0;
					for(int m=0; m<49; m++){
						if(m != 48){
							datos << 0 << ",";
						}
						else{
							datos << 0 << std::endl;
						}
					}
				}
			}
		}
		for(int k=0; k<50; k++){
			temperatura_futuro[0][k] = temperatura_futuro[49][k];
		}
		for(int l=0; l<50; l++){
			temperatura_futuro[l][0] = temperatura_futuro[l][49];
		}
		for(int i=0; i<50; i++){
			for(int j=0; j<50; j++){
				temperatura[i][j] = temperatura_futuro[i][j];
			}
		}
		if(contador == 250){
			contador = 0;
		}
		else{
			contador = contador + 1;
		}
	}

	datos.close();
}
