
# c stuff


## makefiles

a makefile consists of a set of rules of the form
```
<target> : <prereqs>
    <recipie>
```

where "target" is the thing you are building, 
prereqs are things "target" needs, 
and "recipie" is a command or build instruction


e.g.

``` ???
release: main.o utils.o
    cc -o release -O3 main.o utils.o

main.o: main.c utils.o
    cc -c main.c

utils.o: utils.c
    cc -c utils.c
```

### VARIABLES
if you have `CC = gcc` then `$(CC)` evaluates to `gcc`

you can do file extension substitution like this:
```
files = main.c foo.c bar.c
objs = $(files:.c=.o)
```
which results in `objs = main.o foo.o bar.o`


you can also set variables in `target` prereqs to bind them only in `target`'s recipies:
```
dev: CFLAGS = $(DEV_CFLAGS)
prod: CFLAGS = $(PROD_CFLAGS)
```

### PHONY 
why `.PHONY: foo`:

if we have something like:
```
clean:
    rm *.o
```

since `clean` has no prereqs and no file exists called `clean`, 
make will never run `make clean` even if you call it explicitly; 
it thinks there's nothing to be done.

so we do this:
```
.PHONY: clean
clean:
    rm *.o
```
which tells gcc "hey, clean isn't a real target, it's just a command, so run it when i ask"


### PATTERNS

"a pattern rule contains the character '%'".

`%.o : %.c ; <recipie>` -> `main.o : main.c <recipie>`

but now you cant hardcode your target/prereq names in the recipie. use these:
- `$@` to match the target
- `$^` to match all prereqs
- `$<` to match the first prereq


### WILDCARDS

make doesn't let you write: `SRCS = $(SRC)/*.c`

instead, write: `SRCS = $(wildcard $(SRC)/*.c)

### CFLAGS
here are some nice flags for compiling:
- `-Wall`, `-Wextra` `-Wpedantic` for increasing warning levels
- `-Werror` for treating warnings as errors
- `-O0` disables optimization, `-O3` maxxes it out
- `-g` generates debug info for GDB
- `std=c11` tells cc to use the c11 standard
- `march=native` enables cpu-specific optimizations

so for development:
```
CFLAGS = -Wall -Wextra -Wpedantic -Werror -O0 -g -std=c11
```

and for release:
```
CFLAGS = -O3 -march=native -Wall -Wextra -std=c11
```
