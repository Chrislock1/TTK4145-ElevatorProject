//
// Created by student on 03.02.16.
//

#include "defines.h"
#include "UDP_Connect.h"

#include<iostream>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<cstdio>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>

using namespace std;


UDP::UDP()
{

    send_port = 0;
    recv_port = 0;

    socket_send = 0;
    socket_recv = 0;


    cout << "Invalid parameters for connection!" << endl;
}

/* TO DO:
 *
 * Add destructor to acceptance tests
 *
 * */

UDP::UDP(int snd_port, int rcv_port, const char* snd_ip){

    recv_socket.sin_family = PF_INET;
    recv_socket.sin_port = htons((uint16_t)rcv_port);
    recv_socket.sin_addr.s_addr = htonl(INADDR_ANY); //Assuming "htonl" works with "inet_addr"

    send_socket.sin_family = PF_INET;
    send_socket.sin_port = htons((uint16_t)snd_port);
    send_socket.sin_addr.s_addr = inet_addr(snd_ip);

    //Acceptance tests:
    if((socket_send = socket(PF_INET, SOCK_DGRAM,0))<0){
        perror("Could not create send socket \n");
        //destructor
    }
    if((socket_recv = socket(PF_INET, SOCK_DGRAM,0))<0){
        perror("Could not create receive socket \n");
        //destructor
    }
    int broadcast_permit = (*snd_ip == *BROADCAST_IP);
    if(broadcast_permit){
        if(setsockopt(socket_send, SOL_SOCKET, SO_BROADCAST, (void*)&broadcast_permit, sizeof(broadcast_permit)) < 0){
                perror("socket_snd broadcast enable failed: ");
        }
        cout << "Broadcasting tried" << endl;
    }
    if (bind(socket_recv,(struct sockaddr*)&recv_socket, sizeof(recv_socket))<0){
        perror("Failed to bind receive socket");
    }


    if(sendto(socket_send, "test\0", strlen("test\0"), 0, (struct sockaddr*)&send_socket, sizeof(send_socket)) <0){
        perror("Failed sending message");
    }
    cout << "Constructor called" << endl;
}

int UDP::msg_send(char *msg) {
    if(sendto(socket_send, msg, strlen(msg), 0, (struct sockaddr*)&send_socket, sizeof(send_socket)) < 0){
        perror("Failed sending message \n");
        return -1;
    }
    return 0;
}

void UDP::listen_msg(){
    int recvLen = recv(socket_recv, buffer, BUFFER_SIZE, 0);
    if(recvLen > 0){
        cout << "Message received!" << endl;
        buffer[recvLen] = 0;
        cout << buffer << endl;
    }
}
