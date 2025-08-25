g++ .\inout_functions.cpp -c -o inout.o
g++ tests.cpp -c -o tests.o
g++ urvnenie1.cpp -c -o urvnenie.o
g++ solver.cpp -c -o solver.o
g++ inout.o tests.o urvnenie.o solver.o -o krasota.exe
.\krasota.exe
