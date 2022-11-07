//
// Created by hjz on 22-11-7.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; //IPV4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//地址
    serv_addr.sin_port = htons(1234);//端口
    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    char buf[40];
    read(sock, buf, sizeof(buf)-1);

    printf("buffer: %s\n", buf);
    printf("%d\n", sock);

    close(sock);
}
