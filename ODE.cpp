#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h> 
#include <fstream>
#include <sstream>

float g = 10.0;
float c = 0.2;
float m = 0.2;
float h = 0.001;
float max_x = 0.0;
float max_angulo = 0.0;
float vx_prime(float v_x, float v_y);
float vy_prime(float v_x, float v_y);
void iteraciones(float theta, int si);

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

float vx_prime(float v_x, float v_y){
	
	return (-c* (v_x)*((v_x*v_x)+(v_y*v_y)))/(m*sqrt((v_x*v_x)+(v_y*v_y)));

}

float vy_prime(float v_x, float v_y){

	return -g -(c*(v_y)*((v_x*v_x)+(v_y*v_y))/(m*sqrt((v_x*v_x)+(v_y*v_y))));

 }

void iteraciones(float theta, int si){

	std::ofstream datos;
	datos.open("ODE.dat", std::ios::out | std::ios::app);

	float t_0 = 0.0;
	float x_0 = 0.0;
	float y_0 = 0.0;
	float theta_0 = theta;
	float vx_0 = 300*cos(theta_0);
	float vy_0 = 300*sin(theta_0);

	// Leap frog inicializacion
	
	float vx_thalf = vx_0 - h*vx_prime(vx_0,vy_0)/2;
	float vy_thalf = vy_0 - h*vy_prime(vx_0,vy_0)/2;
	float t_half = -h/2;
	float x_ini = x_0;
	float y_ini = y_0;

	datos << t_0 << "," << x_ini << "," << y_ini << "," << t_half << "," << vx_thalf << "," << vy_thalf << std::endl; 

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
			
			i = 10000;
		}

		datos << t_pos << "," << x_ini << "," << y_ini << "," << t_vel << "," << vx_thalf << "," << vy_thalf << std::endl;
		
		if(si == 1 and i == 10000){
			
			std::cout << "La distancia recorrida por el proyectil (con un angulo_0 = 45) es de: " << x_ini << "m" << std::endl;
		}
		
		if(x_ini > max_x and i == 10000){
		
			max_x = x_ini;
			max_angulo = theta_0*180/3.1415;
		}
	
	}

	datos.close();
}

