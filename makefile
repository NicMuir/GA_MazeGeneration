DEPS=MazeGeneration.c


all: 
		gcc -o Main Main.c

run:
		./Main

clean:
		$(RM) myprogram