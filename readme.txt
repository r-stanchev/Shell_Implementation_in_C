Author: Radomir Boyanov Stanchev

This is the readme file for Operating Systems coursework 1. The coursework itself is a simple implementation of a shell written in C. In order to run the program, first open the terminal and type "make", then type "./t" to actually start the shell. The files loop.c, print.c and print2.c are included in order to show that the shell works correctly. In case their compiled versions go missing, see * below. The shell has the following features:
---running "info" will print out a simple information message
---running "pwd" will show the current working directory
---running "cd" followed by a valid directory path will switch the current working directory to the chosen one
---running "ex progA" will execute some program progA
---running "exb progA" will execute some program progA in the background
--- "ex progA | ex progB" will execute some program progB with arguments taken from the output of some other program progA (pipeline progA into progB)
---running "ex progA > file.txt" will redirect the output of some program progA into some file file.txt
---running "ls" will list all files in the current working directory

* - If you run ". ./a.txt" the following 3 commands macros/aliases will become available in the terminal:
mk = execute the makefile and run the shell
cmp = recompile print.c and print2.c (those 2 files are not part of the makefile!)
qwe = will clear the terminal window, remove all object files, clear the terminal window again and run the makefile
