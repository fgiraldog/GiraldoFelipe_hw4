Resultados_hw4.pdf:Resultados_hw4.tex ODE_45.pdf ODE_todos.pdf PDE_abiertas.pdf PDE_fijas.pdf PDE_periodicas.pdf
	pdflatex Resultados_hw4.tex

ODE_45.pdf ODE_todos.pdf PDE_abiertas.pdf PDE_fijas.pdf PDE_periodicas.pdf:Plots_hw4.py PDE.dat ODE.dat
	python Plots_hw4.py

PDE.dat:PDE.o
	./PDE.o

ODE.dat:ODE.o
	./ODE.o

PDE.o:PDE.cpp
	g++ -o PDE.o PDE.cpp

ODE.o:ODE.cpp
	g++ -o ODE.o ODE.cpp
	
