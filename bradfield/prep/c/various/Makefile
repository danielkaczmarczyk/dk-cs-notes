CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g3

# this is a dependency line.
# it says that if somebody types "make all"
# make must first make "hello-world".
# by default the left-hand-side of the first dependency is what you 
# get if you just type "make" with no arguments
all: hello-world

# how to make hello-world?
# the dependency line says youn need to first make hello-world.o
# and hello-library.o

hello-world: hello-world.o hello-library.o
				# subsequent lines starting with a TAB give 
				# commands to execute
				# this command uses amake built-in variables
				# to avoid retyping (and getting things wrong):
				#   $@ = target hello-world
				#   $^ = dependencies hello-world.o and hello-library.o
