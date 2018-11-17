import numpy as np
import matplotlib.pyplot as plt 
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import os as bash

#comando_ODE = './a.out >> datos_ODE.dat'

#ODE

datos_ODE = np.genfromtxt('ODE.dat', delimiter = ',')

tiempo_pos_45, x_45, y_45, tiempo_vel_45, vx_45, vy_45 = datos_ODE[0:1462,0], datos_ODE[0:1462,1], datos_ODE[0:1462,2], datos_ODE[0:1462,3], datos_ODE[0:1462,4], datos_ODE[0:1462,5]
tiempo_pos_10, x_10, y_10, tiempo_vel_10, vx_10, vy_10 = datos_ODE[1463:1996,0], datos_ODE[1463:1996,1], datos_ODE[1463:1996,2], datos_ODE[1463:1996,3], datos_ODE[1463:1996,4], datos_ODE[1463:1996,5]
tiempo_pos_20, x_20, y_20, tiempo_vel_20, vx_20, vy_20 = datos_ODE[1997:2843,0], datos_ODE[1997:2843,1], datos_ODE[1997:2843,2], datos_ODE[1997:2843,3], datos_ODE[1997:2843,4], datos_ODE[1997:2843,5]
tiempo_pos_30, x_30, y_30, tiempo_vel_30, vx_30, vy_30 = datos_ODE[2844:3956,0], datos_ODE[2844:3956,1], datos_ODE[2844:3956,2], datos_ODE[2844:3956,3], datos_ODE[2844:3956,4], datos_ODE[2844:3956,5]
tiempo_pos_40, x_40, y_40, tiempo_vel_40, vx_40, vy_40 = datos_ODE[3957:5309,0], datos_ODE[3957:5309,1], datos_ODE[3957:5309,2], datos_ODE[3957:5309,3], datos_ODE[3957:5309,4], datos_ODE[3957:5309,5]
tiempo_pos_50, x_50, y_50, tiempo_vel_50, vx_50, vy_50 = datos_ODE[5310:6874,0], datos_ODE[5310:6874,1], datos_ODE[5310:6874,2], datos_ODE[5310:6874,3], datos_ODE[5310:6874,4], datos_ODE[5310:6874,5]
tiempo_pos_60, x_60, y_60, tiempo_vel_60, vx_60, vy_60 = datos_ODE[6875:8616,0], datos_ODE[6875:8616,1], datos_ODE[6875:8616,2], datos_ODE[6875:8616,3], datos_ODE[6875:8616,4], datos_ODE[6875:8616,5]
tiempo_pos_70, x_70, y_70, tiempo_vel_70, vx_70, vy_70 = datos_ODE[8617::,0], datos_ODE[8617::,1], datos_ODE[8617::,2], datos_ODE[8617::,3], datos_ODE[8617::,4], datos_ODE[8617::,5]

#45 grados
plt.figure()
plt.plot(x_45, y_45)
plt.ylabel('$y$')
plt.xlabel('$x$')
plt.savefig('ODE_45.pdf')

#Todos los grados
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
x_PDE = np.arange(0,50,1)
y_PDE = np.arange(0,50,1)
x,y = np.meshgrid(x_PDE,y_PDE, sparse = True)
datos_PDE = np.genfromtxt('PDE.dat', delimiter = ',')


z_fijas_0 = datos_PDE[0:50][0:50]
z_fijas_1 = datos_PDE[50:101][0:50]
z_fijas_2 = datos_PDE[100:151][0:50]
z_fijas_3 = datos_PDE[150:201][0:50]

fig = plt.figure(figsize = (10,8))
ax = fig.add_subplot(221, projection='3d')
surf = ax.plot_surface(x, y, z_fijas_0, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax = fig.add_subplot(222, projection='3d')
surf = ax.plot_surface(x, y, z_fijas_1, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax = fig.add_subplot(223, projection='3d')
surf = ax.plot_surface(x, y, z_fijas_2, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax = fig.add_subplot(224, projection='3d')
surf = ax.plot_surface(x, y, z_fijas_3, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
plt.savefig('PDE_fijas.pdf')

z_abiertas_0 = datos_PDE[200:251][0:50]
z_abiertas_1 = datos_PDE[250:301][0:50]
z_abiertas_2 = datos_PDE[300:351][0:50]
z_abiertas_3 = datos_PDE[350:401][0:50]

fig = plt.figure(figsize = (10,8))
ax = fig.add_subplot(221, projection='3d')
surf = ax.plot_surface(x, y, z_abiertas_0, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax = fig.add_subplot(222, projection='3d')
surf = ax.plot_surface(x, y, z_abiertas_1, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax = fig.add_subplot(223, projection='3d')
surf = ax.plot_surface(x, y, z_abiertas_2, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax = fig.add_subplot(224, projection='3d')
surf = ax.plot_surface(x, y, z_abiertas_3, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
plt.savefig('PDE_abiertas.pdf')

z_peri_0 = datos_PDE[400:451][0:50]
z_peri_1 = datos_PDE[450:501][0:50]
z_peri_2 = datos_PDE[500:551][0:50]
z_peri_3 = datos_PDE[550::][0:50]

fig = plt.figure(figsize = (10,8))
ax = fig.add_subplot(221, projection='3d')
surf = ax.plot_surface(x, y, z_peri_0, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax = fig.add_subplot(222, projection='3d')
surf = ax.plot_surface(x, y, z_peri_1, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax = fig.add_subplot(223, projection='3d')
surf = ax.plot_surface(x, y, z_peri_2, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax = fig.add_subplot(224, projection='3d')
surf = ax.plot_surface(x, y, z_peri_3, rstride=1, cstride=1, cmap='hot', linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
plt.savefig('PDE_periodicas.pdf')

#Promedios

x_promedio = np.linspace(1,4,4)
fijas_promedio = [np.sum(z_fijas_0)/250, np.sum(z_fijas_1)/250, np.sum(z_fijas_2)/250, np.sum(z_fijas_3)/250]
abiertas_promedio = [np.sum(z_abiertas_0)/250, np.sum(z_abiertas_1)/250, np.sum(z_abiertas_2)/250, np.sum(z_abiertas_3)/250]
peri_promedio = [np.sum(z_peri_0)/250, np.sum(z_peri_1)/250, np.sum(z_peri_2)/250, np.sum(z_peri_3)/250]

plt.figure()
plt.plot(x_promedio,fijas_promedio, label = 'Fronteras fijas', c='g')
plt.plot(x_promedio,abiertas_promedio, label = 'Fronteras abiertas', c='b')
plt.plot(x_promedio,peri_promedio, label = 'Fronteras periodicas', c='c')
plt.legend()
plt.ylabel('Temperatura promedio ($^o C$)')
plt.xlabel('Tiempo')
plt.savefig('PDE_promedio.pdf')

