#include <iostream>
#include <stdio.h>
#include <cmath>
#include <fstream>

//Declaracion de las funciones
void fronteras_fijas(); //Esta funcion calcula las iteraciones para el caso de las fronteras fijas
void fronteras_abiertas(); //Esta funcion calcula las iteraciones para el caso de las fronteras abiertas
void fronteras_periodicas(); //Esta funcion calcula las iteraciones para el caso de las fronteras periodicas

int main(){
	
	fronteras_fijas();
	fronteras_abiertas();
	fronteras_periodicas();
	
	return 0;
}

void fronteras_fijas(){
	//Esta linea de codigo lo que hace es abrir el archivo PDE.day y guardar las iteraciones para este metodo
	std::ofstream datos;
	datos.open("PDE.dat", std::ios::out | std::ios::app); //El ios ayuda a guardar los datos y no sobreescribirlos

	//Definicion de las variables
	static float temperatura[50][50];
	float delta_x = 0.01;
	float delta_y = 0.01;
	float nu = 1.62/(820*2710);
	float delta_t = 0.1*delta_x*delta_y/nu; //Para estabilidad numerica se necesita que delta t = 0.5*delta_x*delta_y/nu, pero para asegurar, se uso 0.1

	//Condiciones iniciales
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
		for(int h=0; h<50; h++){
			for(int a=0; a<50; a++){
				promedio_0 = promedio_0 + temperatura[h][a]; //Calculo del promedio
			}
		}
		if(i == 49){
			datos << 0 << "," << promedio_0/2500.0; //Calculo del promedio
			
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

	//Iteraciones, para este caso se uso forward difference para poder calcular las iteraciones. Esto se debe a que si se usaba central difference, para que hubiera estabilidad numerica, el delta 	x tenia que ser demasiado pequenho
	//Declaracion de variables
	static float temperatura_futuro[50][50];
	int contador = 0;	
	
	for(int t=0; t<=1000; t++){ //For para el tiempo
		for(int i=0; i<50; i++){ //For para las filas
			for(int j=0; j<50; j++){ //For para las columnas

				temperatura_futuro[i][j] = temperatura[i][j];
				if(i!=0 and i!=49 and j!=0 and j!=49 and ((i-25)*(i-25)+(j-25)*(j-25) > 25)){ //El for no se corre en las fronteras para que estas siempre sean fijas
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
				for(int h=0; h<50; h++){
					for(int a=0; a<50; a++){
						promedio = promedio + temperatura_futuro[h][a]; //Calculo del promedio
					}
				}
				if(i == 49){
					datos << t*delta_t << "," << promedio/2500.0; //Calculo del promedio

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

		for(int l=0; l<50; l++){
			for(int p=0; p<50; p++){
				temperatura[l][p] = temperatura_futuro[l][p];
			}
		}

		if(contador == 250){ //Se trabaja con un contador para poder imprimir iteraciones especificas
			contador = 0;
		}
		else{
			contador = contador + 1;
		}
	}

	datos.close(); //Esta linea cierra el archivo abierto anteriormente
}

void fronteras_abiertas(){
	//Esta linea de codigo lo que hace es abrir el archivo PDE.day y guardar las iteraciones para este metodo
	std::ofstream datos;
	datos.open("PDE.dat", std::ios::out | std::ios::app); //El ios ayuda a guardar los datos y no sobreescribirlos

	//Definicion de las variables
	static float temperatura[50][50];
	float delta_x = 0.01;
	float delta_y = 0.01;
	float nu = 1.62/(820*2710);
	float delta_t = 0.1*delta_x*delta_y/nu; //Para estabilidad numerica se necesita que delta t = 0.5*delta_x*delta_y/nu, pero para asegurar, se uso 0.1

	//Condiciones iniciales
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
		for(int h=0; h<50; h++){
			for(int a=0; a<50; a++){
				promedio_0 = promedio_0 + temperatura[h][a]; //Calculo del promedio
			}
		}
		if(i == 49){
			datos << 0 << "," << promedio_0/2500.0; //Calculo del promedio

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

	//Iteraciones, para este caso se uso forward difference para poder calcular las iteraciones. Esto se debe a que si se usaba central difference, para que hubiera estabilidad numerica, el delta 	x tenia que ser demasiado pequenho
	//Declaracion de variables
	static float temperatura_futuro[50][50];
	int contador = 0;	
	
	for(int t=0; t<=1000; t++){ //For para el tiempo
		for(int i=0; i<50; i++){ //For para las lineas
			for(int j=0; j<50; j++){ //For para las columnas

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
				for(int h=0; h<50; h++){
					for(int a=0; a<50; a++){
						promedio = promedio + temperatura_futuro[h][a]; //Calculo del promedio
					}
				}
				if(i == 49){
					datos << t*delta_t << "," << promedio/2500.0; //Calculo del promedio
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
			temperatura_futuro[0][k] = temperatura_futuro[1][k]; //Condiciones para fronteras abiertas
			temperatura_futuro[49][k] = temperatura_futuro[48][k];
		}
		for(int l=1; l<49; l++){
			temperatura_futuro[l][0] = temperatura_futuro[l][1]; //Condiciones para fronteras abiertas
			temperatura_futuro[l][49] = temperatura_futuro[l][48];
		}
		for(int y=0; y<50; y++){
			for(int q=0; q<50; q++){
				temperatura[y][q] = temperatura_futuro[y][q];
			}
		}
		if(contador == 250){ //Se trabaja con un contador para poder imprimir iteraciones especificas
			contador = 0;
		}
		else{
			contador = contador + 1;
		}
	}

	datos.close(); //Esta linea cierra el archivo abierto anteriormente
}
	
void fronteras_periodicas(){
	//Esta linea de codigo lo que hace es abrir el archivo PDE.day y guardar las iteraciones para este metodo
	std::ofstream datos;
	datos.open("PDE.dat", std::ios::out | std::ios::app); //El ios ayuda a guardar los datos y no sobreescribirlos

	//Definicion de las variables
	static float temperatura[50][50];
	float delta_x = 0.01;
	float delta_y = 0.01;
	float nu = 1.62/(820*2710);
	float delta_t = 0.1*delta_x*delta_y/nu; //Para estabilidad numerica se necesita que delta t = 0.5*delta_x*delta_y/nu, pero para asegurar, se uso 0.1

	//Condiciones iniciales
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
		for(int h=0; h<50; h++){
			for(int a=0; a<50; a++){
				promedio_0 = promedio_0 + temperatura[h][a]; //Calculo del promedio
			}
		}
		if(i == 49){
			datos << 0 << "," << promedio_0/2500.0; //Calculo del promedio
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

	//Iteraciones, para este caso se uso forward difference para poder calcular las iteraciones. Esto se debe a que si se usaba central difference, para que hubiera estabilidad numerica, el delta 	x tenia que ser demasiado pequenho
	//Declaracion de variables
	static float temperatura_futuro[50][50];
	int contador = 0;	
	
	for(int t=0; t<=1000; t++){ //For para el tiempo 
		for(int i=0; i<50; i++){ //For para las lineas
			for(int j=0; j<50; j++){ //For para las columnas

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
				for(int h=0; h<50; h++){
					for(int a=0; a<50; a++){
						promedio = promedio + temperatura_futuro[h][a]; //Calculo del promedio
					}
				}
				if(i == 49){
					datos << t*delta_t << "," << promedio/2500.0; //Calculo del promedio
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
			temperatura_futuro[0][k] = temperatura_futuro[48][k]; //Condiciones para fronteras periodicas
		}
		for(int l=0; l<50; l++){
			temperatura_futuro[l][0] = temperatura_futuro[l][48]; //Condiciones para fronteras periodicas
		}
		for(int y=0; y<50; y++){
			for(int q=0; q<50; q++){
				temperatura[y][q] = temperatura_futuro[y][q];
			}
		}
		if(contador == 250){ //Se trabaja con un contador para poder imprimir iteraciones especificas
			contador = 0;
		}
		else{
			contador = contador + 1;
		}
	}

	datos.close(); //Esta linea cierra el archivo abierto anteriormente
}
