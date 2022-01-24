DEPS = MazeGeneration.c Genetics.c FitnessFunctions.c


all: 
		gcc -o Main Main.c $(DEPS)

run:
		./Main

debug:
		gcc -o Main -ggdb Main.c $(DEPS)

clean:
		$(RM) myprogram