
CFLAGS +=-Wall -g -lpthread -I. # -I/usr/X11R6/include -DLINUX # -I/sw/include  -c #`sdl-config --cflags` 
#CFLAGS = -I. -I/usr/X11R6/include -I/sw/include -c `sdl-config --cflags` -DLINUX
#LDFLAGS = -L/usr/X11R6/lib -lGL -lGLU -lglut #-L/sw/lib  -lm #-lpng -lz #`sdl-config --libs` -lSDL_image

#LIBS=-lm 

PTHREAD_SRC = testpthreads.c

#SRCS=$(wildcard *.c *.cpp)
HDRS=$(wildcard *.h)


CPP = g++
CC = gcc

all: test_pthread

rpi_iotest:


test_pthread: $(PTHREAD_SRC) $(HDRS) 
	$(CC) -o testpthread $(PTHREAD_SRC) $(CFLAGS)


clean:
	rm -f *.o testpthread