#include <stdlib.h>
#include <stdio.h>
void host(){
    printf("Starting host...\n");
    //

}

void join(){
    printf("Starting client...\n");
    //

    
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