DEPS=MazeGeneration.cpp


all: 
		gcc -o Main Main.cpp $(DEPS)

run:
		./Main

clean:
		$(RM) myprogram