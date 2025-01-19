Hello, this is my own small VM (Version 1.0). It just owns some small commands but the foundation is build.
Here is a small guide how to use it. 
First you need a File to compile. You can find the example count.s file in the examples folder.
Then you need to compie it. Run compiler.c for that and input the files name . For example count.s .
Now you should find a file called name.s.bin for example count.s.bin .
Now you run main.c and input the name of the new created file. for example count.s.bin .
Gratulation! you ran your first programm on my VM.

Now I tell you something about every command.

---------ext:------------
Really simple. Write ext somewhere in your file and it ends the programm.

---------mov:------------
mov needs two options. First the register you save a value to and then the value (unsigned int8).
For example:
mov r0 10
wich moves the value 10 to the register r0

---------add:------------
add adds the values of two register and saves it in a register.
For example:
add r0 r1 r2
wich adds r1 and r2 and stores the result in r0

---------add2:------------
add2 adds the value of a register and a uint8 value and stores the result in another register.
For Example:
add2 r0 r1 10
it adds r1 and 10 and stores it in r0.

----------load:------------
loads a value from the ram and stores it to a register.
It needs a register and a uint16 value as ram index (programms got loaded to 3000).
For Example:
load r0 10000
loads ram at the index 10000 to r0.

-----------save:-----------
the same syntax like load but it saves the register to the given ram adress.
For example:
save r0 10000
saves r0 to 10000.

-----------cout:-----------
writes the given register to the console.
For example:
cout r0
writes r0 to the console

-----------coutl:-----------
writes the given register to the console and adds a linebreak to the end.
For example:
coutl r0
writes r0 with a linebreak ("\n") to the console.

-------------jmp:-------------
jumps to given line of code.
For example:
jmp 0
jumps to the first line of code:

--------------jmpeq:-----------
jumps if the two given registers are equal to the given line of code.
For example:
jmpeq r0 r1 0
jumps if r0 and r are equal to the first line of code.

--------------jmpueq:----------
jumps if the two given registers are unequal to the given line of code.
For example
jmpueq r0 r1 0
jumps to the first line of code if register 0 and register 1 are not equal.



=============Credits:============
made by masterflo3004 (Florian)
special thanks to ChatGPT for bugfixing

=============inspired-by:========

https://www.andreinc.net/2021/12/01/writing-a-simple-vm-in-less-than-125-lines-of-c
https://www.jmeiners.com/lc3-vm/


