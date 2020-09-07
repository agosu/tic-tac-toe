hellomake: server.c
	gcc -o server server.c -IC:\src\SDL2_MinGW_32Bit\include -LC:\src\SDL2_MinGW_32Bit\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lws2_32