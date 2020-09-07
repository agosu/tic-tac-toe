#include <winsock2.h>
#include <stdio.h>

int main(int argc, char **argv) {
     WSADATA wsaData;
     SOCKET SendingSocket;
     SOCKADDR_IN ServerAddr;
     char response[1024];
     char request[1024] = "random";
     WSAStartup(MAKEWORD(2,2), &wsaData);
     SendingSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

     ServerAddr.sin_family = AF_INET;
     ServerAddr.sin_port = htons(7170);
     ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
     int connection_code = connect(SendingSocket, (SOCKADDR *) &ServerAddr, sizeof(ServerAddr));

     int bytes_sent;
     int bytes_recieved;

     while (request[4] != 'w' || request[4] != 'l' || request[8] != 'e') {
        if (request[5] == 'm') {
            bytes_recieved = recv(SendingSocket, request, sizeof(request), 0);
            printf("%s", request);
        } else {
            printf("Choose square:\n");
            scanf("%s", response);
            bytes_sent = send(SendingSocket, response, strlen(response), 0);
            bytes_recieved = recv(SendingSocket, request, sizeof(request), 0);
            printf("%s", request);
        }
     }
      
     closesocket(SendingSocket);
     WSACleanup();

     return 0;
}