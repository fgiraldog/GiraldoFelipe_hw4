import numpy as np
import matplotlib.pyplot as plt 
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
from matplotlib.ticker import LinearLocator, FormatStrFormatter
import os as bash

#comando_ODE = './a.out >> datos_ODE.dat'

datos_ODE = np.genfromtxt('ODE.dat', delimiter = ',')

tiempo_pos_45, x_45, y_45, tiempo_vel_45, vx_45, vy_45 = datos_ODE[0:1462,0], datos_ODE[0:1462,1], datos_ODE[0:1462,2], datos_ODE[0:1462,3], datos_ODE[0:1462,4], datos_ODE[0:1462,5]
tiempo_pos_10, x_10, y_10, tiempo_vel_10, vx_10, vy_10 = datos_ODE[1463:1996,0], datos_ODE[1463:1996,1], datos_ODE[1463:1996,2], datos_ODE[1463:1996,3], datos_ODE[1463:1996,4], datos_ODE[1463:1996,5]
tiempo_pos_20, x_20, y_20, tiempo_vel_20, vx_20, vy_20 = datos_ODE[1997:2843,0], datos_ODE[1997:2843,1], datos_ODE[1997:2843,2], datos_ODE[1997:2843,3], datos_ODE[1997:2843,4], datos_ODE[1997:2843,5]
tiempo_pos_30, x_30, y_30, tiempo_vel_30, vx_30, vy_30 = datos_ODE[2844:3956,0], datos_ODE[2844:3956,1], datos_ODE[2844:3956,2], datos_ODE[2844:3956,3], datos_ODE[2844:3956,4], datos_ODE[2844:3956,5]
tiempo_pos_40, x_40, y_40, tiempo_vel_40, vx_40, vy_40 = datos_ODE[3957:5309,0], datos_ODE[3957:5309,1], datos_ODE[3957:5309,2], datos_ODE[3957:5309,3], datos_ODE[3957:5309,4], datos_ODE[3957:5309,5]
tiempo_pos_50, x_50, y_50, tiempo_vel_50, vx_50, vy_50 = datos_ODE[5310:6874,0], datos_ODE[5310:6874,1], datos_ODE[5310:6874,2], datos_ODE[5310:6874,3], datos_ODE[5310:6874,4], datos_ODE[5310:6874,5]
tiempo_pos_60, x_60, y_60, tiempo_vel_60, vx_60, vy_60 = datos_ODE[6875:8616,0], datos_ODE[6875:8616,1], datos_ODE[6875:8616,2], datos_ODE[6875:8616,3], datos_ODE[6875:8616,4], datos_ODE[6875:8616,5]
tiempo_pos_70, x_70, y_70, tiempo_vel_70, vx_70, vy_70 = datos_ODE[8617::,0], datos_ODE[8617::,1], datos_ODE[8617::,2], datos_ODE[8617::,3], datos_ODE[8617::,4], datos_ODE[8617::,5]


plt.figure()
plt.plot(x_45, y_45)
plt.ylabel('$y$')
plt.xlabel('$x$')
#plt.show()


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
#plt.show()

x_PDE = np.linspace(0,50,50)
y_PDE = np.linspace(50,0,50)
datos_PDE = np.genfromtxt('PDE.dat', delimiter = ',')


z_abiertas_0 = datos_PDE[0:49][0:49]

print(z_abiertas_0[27][12])

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
surf = ax.plot_surface(x_PDE, y_PDE, z_abiertas_0, cmap=cm.coolwarm, linewidth=0, antialiased=False)
fig.colorbar(surf, shrink=0.5, aspect=5)
plt.show()
