execution_file = oyamo-chat-client

sources = $(wildcard src/*.c)
includes = $(wildcard include/*.h)
objects = $(sources:.c=.o)
flags = -g -w -fPIC -std=c99 -ljson-c -loyamo -luuid

$(execution_file): $(objects)
	gcc $(objects) $(flags) -o ./bin/$(execution_file)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

clean:
	-rm -rf ./bin/*
	-rm -rf ./build/*
	-rm -rf ./src/*.o

run: 
	./bin/$(execution_file)
