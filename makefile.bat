@echo off
cd src
gcc main.c graph.c input_output.c dijkstra.c navigation.c user_interface.c -o "../navigation_program"
cd ../