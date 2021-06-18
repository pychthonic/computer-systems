all:
	gcc -c hp3.58.s -o decode2.o
	gcc hp3.58.c decode2.o -o hp3.58 
	gcc -g -c hp3.59.s -o storeprod.o
	gcc -g hp3.59.c storeprod.o -o hp3.59
	gcc -g hp3.61.c -o hp3.61
	gcc -c hp3.73.s -o find_range.o
	gcc hp3.73.c ../chapter-2/chapter2.c find_range.o -o hp3.73
