#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

void drawX(SDL_Renderer *ren, int i) {
	int x, y;
	if (i == 1) {
		x = 75; y = 75;
	} else if (i == 2) {
		x = 125; y = 75;
	} else if (i == 3) {
		x = 175; y = 75;
	} else if (i == 4) {
		x = 75; y = 125;
	} else if (i == 5) {
		x = 125; y = 125;
	} else if (i == 6) {
		x = 175; y = 125;
	} else if (i == 7) {
		x = 75; y = 175;
	} else if (i == 8) {
		x = 125; y = 175;
	} else if (i == 9) {
		x = 175; y = 175;
	}

	SDL_RenderDrawLine(ren, x-15, y-15, x+15, y+15);
	SDL_RenderPresent(ren);
	SDL_RenderDrawLine(ren, x+15, y-15, x-15, y+15);
	SDL_RenderPresent(ren);
}

void drawNet(SDL_Renderer *ren) {
	SDL_RenderDrawLine(ren, 100, 50, 100, 200);
	SDL_RenderPresent(ren);
	SDL_RenderDrawLine(ren, 150, 50, 150, 200);
	SDL_RenderPresent(ren);
	SDL_RenderDrawLine(ren, 50, 100, 200, 100);
	SDL_RenderPresent(ren);
	SDL_RenderDrawLine(ren, 50, 150, 200, 150);
	SDL_RenderPresent(ren);
}

void drawO(SDL_Renderer * ren, int i) {

	int32_t centreX;
	int32_t centreY;
	int32_t radius = 15;
	if (i == 1) {
		centreX = 75; centreY = 75;
	} else if (i == 2) {
		centreX = 125; centreY = 75;
	} else if (i == 3) {
		centreX = 175; centreY = 75;
	} else if (i == 4) {
		centreX = 75; centreY = 125;
	} else if (i == 5) {
		centreX = 125; centreY = 125;
	} else if (i == 6) {
		centreX = 175; centreY = 125;
	} else if (i == 7) {
		centreX = 75; centreY = 175;
	} else if (i == 8) {
		centreX = 125; centreY = 175;
	} else if (i == 9) {
		centreX = 175; centreY = 175;
	}

   const int32_t diameter = (radius * 2);

   int32_t x = (radius - 1);
   int32_t y = 0;
   int32_t tx = 1;
   int32_t ty = 1;
   int32_t error = (tx - diameter);

   while (x >= y)
   {
      SDL_RenderDrawPoint(ren, centreX + x, centreY - y);
      SDL_RenderPresent(ren);
      SDL_RenderDrawPoint(ren, centreX + x, centreY + y);
      SDL_RenderPresent(ren);
      SDL_RenderDrawPoint(ren, centreX - x, centreY - y);
      SDL_RenderPresent(ren);
      SDL_RenderDrawPoint(ren, centreX - x, centreY + y);
      SDL_RenderPresent(ren);
      SDL_RenderDrawPoint(ren, centreX + y, centreY - x);
      SDL_RenderPresent(ren);
      SDL_RenderDrawPoint(ren, centreX + y, centreY + x);
      SDL_RenderPresent(ren);
      SDL_RenderDrawPoint(ren, centreX - y, centreY - x);
      SDL_RenderPresent(ren);
      SDL_RenderDrawPoint(ren, centreX - y, centreY + x);
      SDL_RenderPresent(ren);

      if (error <= 0)
      {
         ++y;
         error += ty;
         ty += 2;
      }

      if (error > 0)
      {
         --x;
         tx += 2;
         error += (tx - diameter);
      }
   }
}

void addMove(int *net, int symbol, int place) {
	net[place] = symbol;
}

int checkIfEqual(int *net) {
	int x = 1, o = 0;
	int xCanWin = 0, oCanWin = 0;
	if (((net[1] == 2 || net[1] == x) && (net[2] == 2 || net[2] == x) && (net[3] == 2 || net[3] == x)) ||
		((net[4] == 2 || net[4] == x) && (net[5] == 2 || net[5] == x) && (net[6] == 2 || net[6] == x)) ||
		((net[7] == 2 || net[7] == x) && (net[8] == 2 || net[8] == x) && (net[9] == 2 || net[9] == x)) ||
		((net[1] == 2 || net[1] == x) && (net[4] == 2 || net[4] == x) && (net[7] == 2 || net[7] == x)) ||
		((net[2] == 2 || net[2] == x) && (net[5] == 2 || net[5] == x) && (net[8] == 2 || net[8] == x)) ||
		((net[3] == 2 || net[3] == x) && (net[6] == 2 || net[6] == x) && (net[9] == 2 || net[9] == x)) ||
		((net[1] == 2 || net[1] == x) && (net[5] == 2 || net[5] == x) && (net[9] == 2 || net[9] == x)) ||
		((net[3] == 2 || net[3] == x) && (net[5] == 2 || net[5] == x) && (net[7] == 2 || net[7] == x))) {
		xCanWin = 1;
	}
	if (((net[1] == 2 || net[1] == o) && (net[2] == 2 || net[2] == o) && (net[3] == 2 || net[3] == o)) ||
		((net[4] == 2 || net[4] == o) && (net[5] == 2 || net[5] == o) && (net[6] == 2 || net[6] == o)) ||
		((net[7] == 2 || net[7] == o) && (net[8] == 2 || net[8] == o) && (net[9] == 2 || net[9] == o)) ||
		((net[1] == 2 || net[1] == o) && (net[4] == 2 || net[4] == o) && (net[7] == 2 || net[7] == o)) ||
		((net[2] == 2 || net[2] == o) && (net[5] == 2 || net[5] == o) && (net[8] == 2 || net[8] == o)) ||
		((net[3] == 2 || net[3] == o) && (net[6] == 2 || net[6] == o) && (net[9] == 2 || net[9] == o)) ||
		((net[1] == 2 || net[1] == o) && (net[5] == 2 || net[5] == o) && (net[9] == 2 || net[9] == o)) ||
		((net[3] == 2 || net[3] == o) && (net[5] == 2 || net[5] == o) && (net[7] == 2 || net[7] == o))) {
		oCanWin = 1;
	}
	if (xCanWin == 0 && oCanWin == 0) {
		return 200;
	}
	return 500;
}

int checkIfFull(int *net) {
	for (int i = 1; i <= 9; i++) {
		if (net[i] == 2) {
			return 500;
		}
	}
	return 200;
}

int checkIfWinner(int *net, int symbol) {
	if (net[1] == symbol && net[2] == symbol && net[3] == symbol) {
		return 200;
	}

	if (net[4] == symbol && net[5] == symbol && net[6] == symbol) {
		return 200;
	}

	if (net[7] == symbol && net[8] == symbol && net[9] == symbol) {
		return 200;
	}

	if (net[1] == symbol && net[4] == symbol && net[7] == symbol) {
		return 200;
	}

	if (net[2] == symbol && net[5] == symbol && net[8] == symbol) {
		return 200;
	}

	if (net[3] == symbol && net[6] == symbol && net[9] == symbol) {
		return 200;
	}

	if (net[1] == symbol && net[5] == symbol && net[9] == symbol) {
		return 200;
	}

	if (net[3] == symbol && net[5] == symbol && net[7] == symbol) {
		return 200;
	}

	return 500;
}

int main(int argc, char *argv[]) {

	WSADATA wsa;
    SOCKET x_socket, o_socket, listening_socket;
    char request[1024];
    char response[1024];
    WSAStartup(MAKEWORD(2,2),&wsa);
    x_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    o_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    listening_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    int bytes_sent;

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(7170);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(listening_socket, (SOCKADDR *) &server_address, sizeof(server_address));
    listen(listening_socket, 5);

    x_socket = accept(listening_socket, NULL, NULL);
    o_socket = accept(listening_socket, NULL, NULL);

    start:
    SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *win = SDL_CreateWindow("Tic Tac Toe", 100, 100, 250, 250, SDL_WINDOW_SHOWN);
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, 0);
	SDL_SetRenderDrawColor(ren, 255, 255, 255, SDL_ALPHA_OPAQUE);

    int net[10];
    for (int i = 0; i < 10; i++) {
    	net[i] = 2;
    }
	int x = 1, o = 0;
	drawNet(ren);

    strncpy(response, "Connected as X. You start!", 1024);
    bytes_sent = send(x_socket, response, strlen(response), 0);
    
    strncpy(response, "Connected as O. Your opponent starts!", 1024);
    bytes_sent = send(o_socket, response, strlen(response), 0);

    int won = checkIfWinner(net, x);
    int full = checkIfFull(net);
    int it = -1;
    int player;
    int bytes_recieved;
    while (won != 200 && full != 200) {
    	it++;
    	if (it % 2 == 0) {
    		player = 1;
    	} else player = 0;
    	strncpy(response, "Your move was successful. Waiting for your opponent's move...", 1024);
    	if (player == 1) {
    		bytes_recieved = recv(x_socket, request, sizeof(request), 0);
    	} else {
    		bytes_recieved = recv(o_socket, request, sizeof(request), 0);
    	}
		if (request[0] == '1' && net[1] == 2) {
			addMove(net, player, 1);
			if (player == 1) drawX(ren, 1);
			else drawO(ren, 1);
		} else if (request[0] == '2' && net[2] == 2) {
			addMove(net, player, 2);
			if (player == 1) drawX(ren, 2);
			else drawO(ren, 2);
		} else if (request[0] == '3' && net[3] == 2) {
			addMove(net, player, 3);
			if (player == 1) drawX(ren, 3);
			else drawO(ren, 3);
		} else if (request[0] == '4' && net[4] == 2) {
			addMove(net, player, 4);
			if (player == 1) drawX(ren, 4);
			else drawO(ren, 4);
		} else if (request[0] == '5' && net[5] == 2) {
			addMove(net, player, 5);
			if (player == 1) drawX(ren, 5);
			else drawO(ren, 5);
		} else if (request[0] == '6' && net[6] == 2) {
			addMove(net, player, 6);
			if (player == 1) drawX(ren, 6);
			else drawO(ren, 6);
		} else if (request[0] == '7' && net[7] == 2) {
			addMove(net, player, 7);
			if (player == 1) drawX(ren, 7);
			else drawO(ren, 7);
		} else if (request[0] == '8' && net[8] == 2) {
			addMove(net, player, 8);
			if (player == 1) drawX(ren, 8);
			else drawO(ren, 8);
		} else if (request[0] == '9' && net[9] == 2) {
			addMove(net, player, 9);
			if (player == 1) drawX(ren, 9);
			else drawO(ren, 9);
		} else {
			it--;
			strncpy(response, "Invaalid input. Try again!                                                \n", 1024);
		}

		won = checkIfWinner(net, player);
		full = checkIfFull(net);
		if (won == 200) {
			strncpy(response, "You won.                                                                   \n", 1024);
			if (player == 1) {
				bytes_sent = send(x_socket, response, strlen(response), 0);
				strncpy(response, "You lost.                                                              \n", 1024);
				bytes_sent = send(o_socket, response, strlen(response), 0);
			} else {
				bytes_sent = send(o_socket, response, strlen(response), 0);
				strncpy(response, "You lost.                                                               \n", 1024);
				bytes_sent = send(x_socket, response, strlen(response), 0);
			}
			bytes_recieved = recv(x_socket, request, sizeof(request), 0);
			bytes_recieved = recv(o_socket, request, sizeof(request), 0);
			if (request[0] == 'Y') {
				goto start;
			}
		} else if (full == 200) {
			strncpy(response, "You are equal!                                                                \n", 1024);
			bytes_sent = send(x_socket, response, strlen(response), 0);
			bytes_sent = send(o_socket, response, strlen(response), 0);
			bytes_recieved = recv(x_socket, request, sizeof(request), 0);
			bytes_recieved = recv(o_socket, request, sizeof(request), 0);
			if (request[0] == 'Y') {
				goto start;
			}
		} else {
			if (response[0] == 'I' && player == 1) {
				bytes_sent = send(x_socket, response, strlen(response), 0);
			} else if (response[0] == 'I' && player == 0) {
				bytes_sent = send(o_socket, response, strlen(response), 0);
			} else if (player == 1) {
				bytes_sent = send(x_socket, response, strlen(response), 0);
				strncpy(response, "Your turn.                                                               \n", 1024);
				bytes_sent = send(o_socket, response, strlen(response), 0);
			} else {
				bytes_sent = send(o_socket, response, strlen(response), 0);
				strncpy(response, "Your turn.                                                                \n", 1024);
				bytes_sent = send(x_socket, response, strlen(response), 0);
			}
		}
    }

    closesocket(x_socket);
    closesocket(o_socket);
    closesocket(listening_socket);
    WSACleanup();
    
	SDL_Delay(10000);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;
}