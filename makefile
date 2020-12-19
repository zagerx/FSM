
# ./debug/event.o ./debug/fsm.o  ./debug/key_event.o
main:./debug/main.o ./debug/zg_list.o ./debug/zg_heap.o ./debug/event.o ./debug/fsm.o ./debug/key_event.o ./debug/key_fsm.o 
	gcc ./debug/main.o ./debug/zg_list.o ./debug/zg_heap.o ./debug/event.o ./debug/fsm.o ./debug/key_event.o ./debug/key_fsm.o -o ./bin/main 
./debug/main.o:main.c
	gcc -c main.c -I .\src -o ./debug/main.o
./debug/zg_list.o:.\src\zg_list.c	
	gcc -c .\src\zg_list.c -I .\src -o ./debug/zg_list.o
./debug/zg_heap.o:.\src\zg_heap.c
	gcc -c .\src\zg_heap.c -I .\src -o ./debug/zg_heap.o
./debug/event.o:.\src\event.c
	gcc -c .\src\event.c -I .\src -o ./debug/event.o
./debug/fsm.o:.\src\fsm.c
	gcc -c .\src\fsm.c -I .\src -o ./debug/fsm.o
./debug/key_fsm.o:.\src\key_fsm.c
	gcc -c .\src\key_fsm.c -I .\src -o ./debug/key_fsm.o	
./debug/key_event.o:.\src\key_event.c
	gcc -c .\src\key_event.c -I .\src -o ./debug/key_event.o	
.PHONY:
clc:	
	rm ./debug/main.o
	rm ./debug/zg_list.o
	rm ./debug/zg_heap.o
	rm ./debug/event.o
	rm ./debug/fsm.o
	rm ./debug/key_event.o
	rm ./debug/key_fsm.o
	rm ./bin/main.exe
			




