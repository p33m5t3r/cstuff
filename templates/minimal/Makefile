
# all src files in ./src, all objects/executables sent to ./bin
CFLAGS 	= -Wall -Wextra -Wpedantic -Werror -O0 -g -std=c11
bin/main: $(patsubst src/%.c, bin/%.o, $(wildcard src/*.c)); cc $(CFLAGS) -o bin/main $^
bin/%.o: src/%.c; cc $(CFLAGS) -c $< -o $@
clean:; rm -rf bin/*
.PHONY: bin/main clean
