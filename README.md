RPN-Interpreter
===============

Reverse Polish Notation interpreter

run make to build. enter RPN into stdin to interpret.

Example:

cd ...

make

./main.exe < lol.txt (contains 12 34 7 + * NEG)

Output:

-(12 * (34 + 7))

= -492
