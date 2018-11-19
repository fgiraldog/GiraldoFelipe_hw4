#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h> 
#include <fstream>
#include <sstream>

//Definicion de las variables y funciones
float g = 10.0;
float c = 0.2;
float m = 0.2;
float h = 0.001;
float max_x = 0.0; //Esta variable se usa para poder encontrar el angulo con mayor distancia
float max_angulo = 0.0; //Esta variable se usa para poder relacionar la distancia anterior con el angulo
float vx_prime(float v_x, float v_y); //Retorna la aceleracion en x
float vy_prime(float v_x, float v_y); //Retorna la aceleracion en y
void iteraciones(float theta, int si); //Imprime las iteraciones teniendo en cuenta un angulo y una variable binaria (con el fin de imprimir la distancia solo para theta = 45)

int main(){
	
	iteraciones(45*3.1415/180,1);
	iteraciones(10*3.1415/180,0);
	iteraciones(20*3.1415/180,0);
	iteraciones(30*3.1415/180,0);
	iteraciones(40*3.1415/180,0);
	iteraciones(50*3.1415/180,0);
	iteraciones(60*3.1415/180,0);
	iteraciones(70*3.1415/180,0);

	std::cout << "El angulo para el cual la distancia recorrida es mayor es: " << max_angulo << " grados " << std::endl;

	return 0;
}

float vx_prime(float v_x, float v_y){ //Aca es importante mencionar que solo se tienen en cuenta los componentes de los vectores en el eje x
	
	return (-c* (v_x)*((v_x*v_x)+(v_y*v_y)))/(m*sqrt((v_x*v_x)+(v_y*v_y)));

}

float vy_prime(float v_x, float v_y){ //Aca es importante mencionar que solo se tienen en cuenta los componentes de los vectores en el eje y, tal como la gravedad

	return -g -(c*(v_y)*((v_x*v_x)+(v_y*v_y))/(m*sqrt((v_x*v_x)+(v_y*v_y))));

 }

void iteraciones(float theta, int si){
	//Esta linea abre el archivo ODE.dat con el fin de guardar los datos
	std::ofstream datos;
	datos.open("ODE.dat", std::ios::out | std::ios::app); //El ios lo que hace es acumular los datos y no reescribirlos

	//Definicion de las variables 
	float t_0 = 0.0;
	float x_0 = 0.0;
	float y_0 = 0.0;
	float theta_0 = theta;
	float vx_0 = 300*cos(theta_0);
	float vy_0 = 300*sin(theta_0);

	// Leap frog inicializacion donde la velocidad se desfasa un h/2 hacia atras teniendo en cuenta la posicion
	float vx_thalf = vx_0 - h*vx_prime(vx_0,vy_0)/2;
	float vy_thalf = vy_0 - h*vy_prime(vx_0,vy_0)/2;
	float t_half = -h/2;
	float x_ini = x_0;
	float y_ini = y_0;

	datos << t_0 << "," << x_ini << "," << y_ini << "," << t_half << "," << vx_thalf << "," << vy_thalf << std::endl;  //Aca se guardan los datos

	//Iteraciones teniendo en cuenta el desfase mencionado anteriormente
	for(int i=1; i<10000; i++){
		
		float vx_siguiente = vx_thalf + h*vx_prime(vx_thalf,vy_thalf);
		float vy_siguiente = vy_thalf + h*vy_prime(vx_thalf,vy_thalf);
		
		float x_siguiente = x_ini + vx_siguiente*h;
		float y_siguiente = y_ini + vy_siguiente*h;

		vx_thalf = vx_siguiente;
		vy_thalf = vy_siguiente;

		x_ini = x_siguiente;
		y_ini = y_siguiente;

		float t_pos = i*h;
		float t_vel = t_pos - h/2;
		
		if(y_ini < 0.1 and i > 10){
			
			i = 10000; //Esto se hace para parar el codigo cuando el proyectil vuelve a y = 0. (se usa 0.1 para aproximar el comportamiento)
		}

		datos << t_pos << "," << x_ini << "," << y_ini << "," << t_vel << "," << vx_thalf << "," << vy_thalf << std::endl;
		
		if(si == 1 and i == 10000){
			
			std::cout << "La distancia recorrida por el proyectil (con un angulo_0 = 45) es de: " << x_ini << "m" << std::endl; //Para imprimir en consola la distancia para 45 grados
		}
		
		if(x_ini > max_x and i == 10000){
		
			max_x = x_ini;
			max_angulo = theta_0*180/3.1415; //Para determinar el angulo optimo en donde se recorre una mayor distancia en el eje x
		}
	
	}

	datos.close(); //Esta linea cierra el documento abierto anteriormente
}

