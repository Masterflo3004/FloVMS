/*

------main function-------
create memory
starts udp socket,
sets socket to nonblocking
inputs join ip (IPv6)
sends handshake to join ip
while loop:
    


*/
//=========imports==========
//standard
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
//networking
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

//definitions
#define PORT 33698
#define MAXRECVLEN 256

//============variables===========

int len;

struct sockaddr_in dest;
int mastersocket;

char buffer[MAXRECVLEN + 1] ;


//============main===============

int main(){
    mastersocket = socket(AF_INET, SOCK_STREAM, 0);
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    dest.sin_port = PORT;

    connect(mastersocket, (struct sockaddr *) &dest, sizeof(struct sockaddr_in));

    
    
}