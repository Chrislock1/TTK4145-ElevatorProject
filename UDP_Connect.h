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
#include<unistd.h>

using namespace std;


UDP_Connect::UDP_Connect() {
    uint_16 send_port = 0;
    uint_16 recv_port = 0;

    int socket_send = 0;
    int socket_recv = 0;

    struct sockaddr_in recv_socket = nullptr;
    struct sockaddr_in send_socket = nullptr;

    int ip_from_sender_socket = 0;
    struct sockaddr_in ip_from_sender_socket_adress = nullptr;

    std::cout << "Invalid parameters for connection!" << std::endl;
}

/* TO DO:
 *
 * Add destructor to acceptance tests
 *
 * */
UDP_Connect::UDP_Connect(uint16_t snd_port, uint16_t rcv_port, const char* snd_ip, const char* rcv_ip) {

    recv_socket.sin_family = PF_INET;
    recv_socket.sin_port = htons(rcv_port);
    recv_socket.sin_addr.s_addr = htonl(rcv_ip); //Assuming "htonl" works with "inet_addr"

    send_socket.sin_family = PF_INET;
    send_socket.sin_port = htons(snd_port);
    send_socket.sin_addr.s_addr = inet_addr(snd_ip);

    ip_from_sender_socket_size = sizeof(ip_sockAddr);

    //Acceptance tests:
    if((socket_send = socket(PF_INET, SOCK_DGRAM,0))<0){
        perror("Could not create send socket \n");
        //destructor
        return -1;
    }
    if((socket_recv = socket(PF_INET, SOCK_DGRAM,0))<0){
        perror("Could not create receive socket \n");
        //destructor
        return -1;
    }
    int broadcast_permit = (rcv_ip == BROADCAST_IP);

    if(broadcast_permit){
        if(setsockopt(socket_snd, SOL_SOCKET, SO_BROADCAST, (void*)&broadcast_permit, sizeof(broadcast_permit) < 0)){
            perror("socket_snd broadcast enable failed \n");
            return -1;
        }
    }
    if (bind(socket_recv,(struct sockaddr*)&recv_socket, sizeof(recv_socket))<0){
        perror("Failed to bind receive socket");
        return -1;
    }


    if(sendto(socket_send, "test\0", strlen("test\0"), 0, (struct sockaddr*)&send_socket, sizeof(send_socket)) <0){
        perror("Failed sending message \n");
        return -1;
    }

}
