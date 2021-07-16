.PHONY: clean bin
all: clean bin build

clean:
	rm -f -r ./bin

bin:
	mkdir bin

CC=gcc
CFLAGS=-pthread
SRCD=src
BIND=bin

build:
	$(CC)	$(SRCD)/main.c $(SRCD)/CPU/ClockGenerator/clock_generator.c $(CFLAGS) -o $(BIND)/nes-emulator