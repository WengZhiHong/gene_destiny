all: compile exec

compile:
	g++ -static -o myProgram main.cpp 3num.cpp gene_num.cpp 


exec:
	./myProgram.exe

clean:

	del myProgram.exe