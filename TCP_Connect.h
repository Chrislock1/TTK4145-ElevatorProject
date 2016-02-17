//
// Created by student on 17.02.16.
//

#ifndef TCP_CONNECT_H
#define TCP_CONNECT_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>


class TCP_Connect {
private:
    int sock, cli;
    unsigned int len;
    char *greet = "Welcome from server";

    struct sockaddr_in server, client;

public:
    // TCP_Connect(20009, 30000)
    TCP_Connect(int port_svr);
};


#endif //TCP_CONNECT_H
