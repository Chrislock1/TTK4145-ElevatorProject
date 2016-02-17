//
// Created by student on 17.02.16.
//

#include "TCP_Connect.h"

using namespace std;


TCP_Connect::TCP_Connect(int port_svr) {
    if((sock = socket(AF_INET,SOCK_STREAM,0))<0){
        perror("Socket: ");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons((uint16_t)port_svr);
    server.sin_addr.s_addr = INADDR_ANY;


    if ((bind(sock, (struct sockaddr *)&server,sizeof(server)))<0){
        perror("Bind: ");
    }

    if((listen(sock,5))<0){
        perror("Listen: ");
    }
    len = sizeof(struct sockaddr_in);
    while(true){
        if((cli = accept(sock, (struct sockaddr *)&client,&len))<0) {
            perror("Accept: ");
        }

        unsigned int sent = send(cli, greet, strlen(greet), 0);

        cout << "Sent " << strlen(greet) << " bytes to client : " << inet_ntoa(client.sin_addr) << endl;

        close(cli);
        close(sock);


    }

}
