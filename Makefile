CXX := g++
CXX_FLAGS := -Wall -Wextra -std=c11

.PHONY:all
all:
	$(MAKE) app

.PHONY:app
app:
	$(CXX) $(CXX_FLAGS) ./src/*.cpp ./src/Blocks/*.cpp -I ./include -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

run:
	./sfml-app