import numpy as np
import matplotlib.pyplot as plt 
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.animation as ani
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import os as bash

'''
#En estas cuatro lineas de codigo se ejecuta los archivos de C++ para ODE y PDE
comando_ODE = './ODE.o'
comando_PDE = './PDE.o'

#bash.system(comando_ODE)
#bash.system(comando_PDE)
'''

#ODE
#Importacion de los datos de ODE
datos_ODE = np.genfromtxt('ODE.dat', delimiter = ',')
#Clasificacion de los datos para cada angulo
tiempo_pos_45, x_45, y_45, tiempo_vel_45, vx_45, vy_45 = datos_ODE[0:1462,0], datos_ODE[0:1462,1], datos_ODE[0:1462,2], datos_ODE[0:1462,3], datos_ODE[0:1462,4], datos_ODE[0:1462,5]
tiempo_pos_10, x_10, y_10, tiempo_vel_10, vx_10, vy_10 = datos_ODE[1463:1996,0], datos_ODE[1463:1996,1], datos_ODE[1463:1996,2], datos_ODE[1463:1996,3], datos_ODE[1463:1996,4], datos_ODE[1463:1996,5]
tiempo_pos_20, x_20, y_20, tiempo_vel_20, vx_20, vy_20 = datos_ODE[1997:2843,0], datos_ODE[1997:2843,1], datos_ODE[1997:2843,2], datos_ODE[1997:2843,3], datos_ODE[1997:2843,4], datos_ODE[1997:2843,5]
tiempo_pos_30, x_30, y_30, tiempo_vel_30, vx_30, vy_30 = datos_ODE[2844:3956,0], datos_ODE[2844:3956,1], datos_ODE[2844:3956,2], datos_ODE[2844:3956,3], datos_ODE[2844:3956,4], datos_ODE[2844:3956,5]
tiempo_pos_40, x_40, y_40, tiempo_vel_40, vx_40, vy_40 = datos_ODE[3957:5309,0], datos_ODE[3957:5309,1], datos_ODE[3957:5309,2], datos_ODE[3957:5309,3], datos_ODE[3957:5309,4], datos_ODE[3957:5309,5]
tiempo_pos_50, x_50, y_50, tiempo_vel_50, vx_50, vy_50 = datos_ODE[5310:6874,0], datos_ODE[5310:6874,1], datos_ODE[5310:6874,2], datos_ODE[5310:6874,3], datos_ODE[5310:6874,4], datos_ODE[5310:6874,5]
tiempo_pos_60, x_60, y_60, tiempo_vel_60, vx_60, vy_60 = datos_ODE[6875:8616,0], datos_ODE[6875:8616,1], datos_ODE[6875:8616,2], datos_ODE[6875:8616,3], datos_ODE[6875:8616,4], datos_ODE[6875:8616,5]
tiempo_pos_70, x_70, y_70, tiempo_vel_70, vx_70, vy_70 = datos_ODE[8617::,0], datos_ODE[8617::,1], datos_ODE[8617::,2], datos_ODE[8617::,3], datos_ODE[8617::,4], datos_ODE[8617::,5]

#Grafica del recorrido del proyectil para 45 grados
plt.figure()
plt.plot(x_45, y_45)
plt.ylabel('$y$')
plt.xlabel('$x$')
plt.savefig('ODE_45.pdf')

#Grafica del recorrido del proyectil para cada uno de los angulos propuestos 
plt.figure()
plt.plot(x_10, y_10, label = '$10^o$')
plt.plot(x_20, y_20, label = '$20^o$')
plt.plot(x_30, y_30, label = '$30^o$')
plt.plot(x_40, y_40, label = '$40^o$')
plt.plot(x_50, y_50, label = '$50^o$')
plt.plot(x_60, y_60, label = '$60^o$')
plt.plot(x_70, y_70, label = '$70^o$')
plt.ylabel('$y$')
plt.xlabel('$x$')
plt.legend()
plt.savefig('ODE_todos.pdf')

#PDE
#3D
x_PDE = np.arange(0,0.5,0.01) #Definicion de la grid en donde se van a contener los datos de la matriz guardada por el archivo de C++ 
y_PDE = np.arange(0,0.5,0.01) #Definicion de la grid en donde se van a contener los datos de la matriz guardada por el archivo de C++
x,y = np.meshgrid(x_PDE,y_PDE, sparse = True) #Definicion de la grid en donde se van a contener los datos de la matriz guardada por el archivo de C++
datos_PDE = np.genfromtxt('PDE.dat', delimiter = ',') #Importacion de los datos

#Clasificacion de los datos para las fronteras fijas
z_fijas_0 = datos_PDE[0:50][0:50]
z_fijas_1 = datos_PDE[51:101][0:50]
z_fijas_2 = datos_PDE[102:152][0:50]
z_fijas_3 = datos_PDE[153:203][0:50]

#Grafica en 3D para las fronteras fijas donde se tiene en cuenta los 4 momentos
fig = plt.figure(figsize = (15,10))
ax1 = fig.add_subplot(221, projection='3d')
surf = ax1.plot_surface(x, y, z_fijas_0, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax1.set_xlabel('Distancia ($m$)')
ax1.set_ylabel('Distancia ($m$)')
ax1.set_zlabel('Temperatura ($^o C$)')
ax2 = fig.add_subplot(222, projection='3d')
surf = ax2.plot_surface(x, y, z_fijas_1, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax2.set_xlabel('Distancia ($m$)')
ax2.set_ylabel('Distancia ($m$)')
ax2.set_zlabel('Temperatura ($^o C$)')
ax3 = fig.add_subplot(223, projection='3d')
surf = ax3.plot_surface(x, y, z_fijas_2, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax3.set_xlabel('Distancia ($m$)')
ax3.set_ylabel('Distancia ($m$)')
ax3.set_zlabel('Temperatura ($^o C$)')
ax4 = fig.add_subplot(224, projection='3d')
surf = ax4.plot_surface(x, y, z_fijas_3, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax4.set_xlabel('Distancia ($m$)')
ax4.set_ylabel('Distancia ($m$)')
ax4.set_zlabel('Temperatura ($^o C$)')
plt.savefig('PDE_fijas.pdf')

#Clasificacion de los datos para las fronteras abiertas
z_abiertas_0 = datos_PDE[204:254][0:50]
z_abiertas_1 = datos_PDE[255:305][0:50]
z_abiertas_2 = datos_PDE[306:356][0:50]
z_abiertas_3 = datos_PDE[357:407][0:50]

#Grafica en 3D para las fronteras abiertas donde se tiene en cuenta los 4 momentos
fig = plt.figure(figsize = (15,10))
ax1 = fig.add_subplot(221, projection='3d')
surf = ax1.plot_surface(x, y, z_abiertas_0, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax1.set_xlabel('Distancia ($m$)')
ax1.set_ylabel('Distancia ($m$)')
ax1.set_zlabel('Temperatura ($^o C$)')
ax2 = fig.add_subplot(222, projection='3d')
surf = ax2.plot_surface(x, y, z_abiertas_1, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax2.set_xlabel('Distancia ($m$)')
ax2.set_ylabel('Distancia ($m$)')
ax2.set_zlabel('Temperatura ($^o C$)')
ax3 = fig.add_subplot(223, projection='3d')
surf = ax3.plot_surface(x, y, z_abiertas_2, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax3.set_xlabel('Distancia ($m$)')
ax3.set_ylabel('Distancia ($m$)')
ax3.set_zlabel('Temperatura ($^o C$)')
ax4 = fig.add_subplot(224, projection='3d')
surf = ax4.plot_surface(x, y, z_abiertas_3, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax4.set_xlabel('Distancia ($m$)')
ax4.set_ylabel('Distancia ($m$)')
ax4.set_zlabel('Temperatura ($^o C$)')
plt.savefig('PDE_abiertas.pdf')


#Clasificacion de los datos para las fronteras periodicas
z_peri_0 = datos_PDE[408:458][0:50]
z_peri_1 = datos_PDE[459:509][0:50]
z_peri_2 = datos_PDE[510:560][0:50]
z_peri_3 = datos_PDE[561:611][0:50]

#Grafica en 3D para las fronteras periodicas donde se tiene en cuenta los 4 momentos
fig = plt.figure(figsize = (15,10))
ax1 = fig.add_subplot(221, projection='3d')
surf1 = ax1.plot_surface(x, y, z_peri_0, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax1.set_xlabel('Distancia ($m$)')
ax1.set_ylabel('Distancia ($m$)')
ax1.set_zlabel('Temperatura ($^o C$)')
ax2 = fig.add_subplot(222, projection='3d')
surf2 = ax2.plot_surface(x, y, z_peri_1, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax2.set_xlabel('Distancia ($m$)')
ax2.set_ylabel('Distancia ($m$)')
ax2.set_zlabel('Temperatura ($^o C$)')
ax3 = fig.add_subplot(223, projection='3d')
surf3 = ax3.plot_surface(x, y, z_peri_2, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax3.set_xlabel('Distancia ($m$)')
ax3.set_ylabel('Distancia ($m$)')
ax3.set_zlabel('Temperatura ($^o C$)')
ax4 = fig.add_subplot(224, projection='3d')
surf4 = ax4.plot_surface(x, y, z_peri_3, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax4.set_xlabel('Distancia ($m$)')
ax4.set_ylabel('Distancia ($m$)')
ax4.set_zlabel('Temperatura ($^o C$)')
plt.savefig('PDE_periodicas.pdf')

#Promedios
#Clasificacion de los datos para los promedios de cada caso
x_promedio = [datos_PDE[50][0], datos_PDE[101][0], datos_PDE[152][0], datos_PDE[203][0]]
fijas_promedio = [datos_PDE[50][1], datos_PDE[101][1], datos_PDE[152][1], datos_PDE[203][1]]
abiertas_promedio = [datos_PDE[254][1], datos_PDE[305][1], datos_PDE[356][1], datos_PDE[407][1]]
peri_promedio = [datos_PDE[458][1], datos_PDE[509][1], datos_PDE[560][1], datos_PDE[611][1]]

#Grafica de los promedios
plt.figure()
plt.plot(x_promedio,fijas_promedio, label = 'Fronteras fijas', c='g')
plt.plot(x_promedio,abiertas_promedio, label = 'Fronteras abiertas', c='b')
plt.plot(x_promedio,peri_promedio, label = 'Fronteras periodicas', c='c')
plt.legend()
plt.ylabel('Temperatura promedio ($^o C$)')
plt.xlabel('Tiempo ($s$)')
plt.savefig('PDE_promedio.pdf')

#Animaciones

z_fijas = [z_fijas_0, z_fijas_1,z_fijas_2,z_fijas_3]

def update_fijas(i, z, line):
    	z1 = z[i]
	ax.clear()
    	line = ax.plot_surface(x, y, z1, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
	return line,
    	

fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')
line = ax.plot_surface(x, y, z_fijas_0, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
animacion = ani.FuncAnimation(fig, update_fijas, fargs = (z_fijas, line), frames = 4, interval =30, blit=False)
animacion.save('fijas.gif', writer='imagemagick', fps=2)

z_abiertas = [z_abiertas_0, z_abiertas_1,z_abiertas_2,z_abiertas_3]

def update_abiertas(i, z, line):
    	z1 = z[i]
	ax.clear()
    	line = ax.plot_surface(x, y, z1, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
	return line,
    	

fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')
line = ax.plot_surface(x, y, z_abiertas_0, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
animacion = ani.FuncAnimation(fig, update_fijas, fargs = (z_abiertas, line), frames = 4, interval =30, blit=False)
animacion.save('abiertas.gif', writer='imagemagick', fps=2)

z_peri = [z_peri_0, z_peri_1,z_peri_2,z_peri_3]

def update_peri(i, z, line):
    	z1 = z[i]
	ax.clear()
    	line = ax.plot_surface(x, y, z1, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
	return line,
    	

fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')
line = ax.plot_surface(x, y, z_peri_0, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
animacion = ani.FuncAnimation(fig, update_peri, fargs = (z_peri, line), frames = 4, interval =30, blit=False)
animacion.save('periodicas.gif', writer='imagemagick', fps=2)

