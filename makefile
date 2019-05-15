###############################################################
# Program:
#     Team Activity 04, Classes
#     Brother Dudley, CS165
# Author:
#     Drazen Lucic, group 10
# Summary:
#     This is a team activity project to write a class
#     that represents rational numbers.
###############################################################


a.out : rational.h rational.cpp ta04.cpp
	g++ -std=c++11 rational.cpp ta04.cpp
	tar -cf ta04.tar makefile *.h *.cpp

