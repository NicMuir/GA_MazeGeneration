DEPS = MazeGeneration.c Genetics.c FitnessFunctions.c


all: 
		gcc -o Main Main.c $(DEPS)

run:
		./Main

clean:
		$(RM) myprogram