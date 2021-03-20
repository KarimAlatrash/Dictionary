# Makefile for Project 2
#
# You will need to rename this file to “Makefile” (note the capital M)
# and test it in  the ECE servers, with the command “make”
#
# Ensure that after the “make” command an executable with the expected name is
# created. For this example the expected name for the excecutable is dequeaslisttest
#

# List all the drivers
all: trietest


# list the test program all classes (cpp files)
#  cpp files must use #include , to include *.h or *.hpp files

trietest: trietest.cpp Trie_Node.h Trie.cpp
	g++ -std=c++11 -o triedriver trietest.cpp Trie_Node.h Trie.cpp

# List all the executables under 'all:'
clean:
	rm *.o triedriver
