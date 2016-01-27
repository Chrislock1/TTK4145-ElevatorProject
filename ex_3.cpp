#include<iostream>
#include<inttypes.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

using namespace std;

// Assignments
#define BUFFER_SIZE 1024

uint16_t myPort = 20009; // Port for lab place 9
uint16_t listenPort = 30000;


int socket_snd, socket_rec; //UDP sockets


int main()
{
    unsigned char* buffer[BUFFER_SIZE];
    const char* broadcastIP = "129.241.187.255";
    const char* serverIP = "129.241.187.156";

    // RECEIVER SOCKET ADDRESS STRUCT //
    struct sockaddr_in myAddr;
    myAddr.sin_family = AF_INET;
    myAddr.sin_port = htons(listenPort);
    myAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    // SENDER SOCKET ADDRESS STRUCT //
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(myPort);
    serverAddr.sin_addr.s_addr = inet_addr(broadcastIP);

    if((socket_snd = socket(AF_INET, SOCK_DGRAM,0))<0){
        perror("Could not create send socket \n");
        return -1;
    }
    if((socket_rec = socket(AF_INET, SOCK_DGRAM,0))<0){
        perror("Could not create receive socket \n");
        return -1;
    }

    int permitBroadcast = 1;
    if((setsockopt(socket_snd, SOL_SOCKET, SO_BROADCAST, (void*)&permitBroadcast, sizeof(permitBroadcast))) < 0){
        perror("socket_snd broadcast enable failed \n");
        return -1;
    }
    if (bind(socket_snd,(struct sockaddr*)&serverAddr, sizeof(serverAddr))< 0){
        perror("Failed to bind send socket");
        return -1;
    }
    if (bind(socket_rec,(struct sockaddr*)&myAddr, sizeof(myAddr))<0){
        perror("Failed to bind receive socket");
        return -1;
    }
    char* broadcast_msg = "Group 9 checking in!";
    char* receiveIP;

    if(sendto(socket_snd, broadcast_msg, strlen(broadcast_msg), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) <0){
        perror("Failed sending message \n");
        return -1;
    }


    while(1){
        int recvLen = recvfrom(socket_rec, buffer, BUFFER_SIZE, 0, 0, 0);
        if(recvLen > 0){
            cout << "Message received!" << endl;

        }

    }
}
