
src-y := $(wildcard src/card/*.c) $(wildcard src/filesyetem/*.c) 
#${info ${src-y}}

obj-y := $(patsubst %.c, %.o, ${src-y})
#${info ${obj-y}}

all: build src

build: violet.a

%.o:%.c
#       echo $^
	${CC} ${CFLAGS} -o $@  -c $<

violet.a: ${obj-y}
#       echo $^
	${AR} -rcv $@ $^
	cp violet.a test/

.PHONY:test
#test: violet.a
#	make -f test/Makefile
#	./testvcos.out -f test/apdu.apdu

clean:
	@find . -name "*.o" -exec rm {} \;
	@find . -name "*.a" -exec rm {} \;

