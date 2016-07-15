Stack:Stack.c
	gcc -c Stack.c -o Stack.o -w;

InfixToPost:Stack
	gcc -c InfixToPostFix.c -o InfixToPostFix.o;

final:Stack InfixToPost
	gcc Stack.o InfixToPostFix.o -o a.out;
