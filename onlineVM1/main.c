#include <stdlib.h>
#include <stdio.h>
void host(){
    printf("==========Host==========\n");
    //setup VM
    printf("Starting VM ...\n");
    //start host
    printf("Starting Host ...\n");
    //main loop
    while(1){
        //manage incomming connections

        //manage incomming packets
    }

}

void join(){
    printf("==========Client==========\n");
    //setup VM
    printf("Starting VM ...\n");
    //start client
    printf("Starting Client ...\n");

    while(1){
        
    }

}


int main(){
    int mode = 0;
    printf("======Choose Mode======\n");
    printf("-----1 = host-----\n");
    printf("Hosts your own programm, and allows other persons to join.\n");
    printf("-----2 = join-----\n");
    printf("Joins a hostet programm via IPv6.\n");
    printf("Your Choice:\n");
    scanf("%d",&mode);
    printf("================================================================================\n");
    if(mode == 1){
        host();
    }else if(mode == 2){
        join();
    } else{
        printf("Invalid Choice!\n");
    }
}