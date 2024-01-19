
//-------Inports-----------
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//-------defines-----------
#define OPC(i) ((i)>>24)
#define inst1(i) (((i)<<8)>>24)
#define inst2(i) (((i)<<16)>>24)
#define inst3(i) (((i)<<24)>>24)
#define instmem(i) (((i)<<16)>>16)


//--------code--------------
enum registers{r0=0, r1, r2, r3, r4, r5, r6, r7, r8, r9, RPC, RCND, RCNT};
uint32_t reg[RCNT];
uint32_t memory[__UINT16_MAX__];
uint32_t startPC = 0x3000;

int ext(uint32_t i){ //exit 0
    return 0;
}
int mov(uint32_t i){ //mov 1
    reg[inst1(i)] = inst2(i);
    return 1;
}
int add(uint32_t i){ //add 2
    reg[inst1(i)] = reg[inst2(i)] + reg[inst3(i)];
    return 1;
}
int add2(uint32_t i){ //add2 3
    reg[inst1(i)] = reg[inst2(i)] + inst3(i);
    return 1;
}
int load(uint32_t i){ //load 4
    reg[inst1(i)]=memory[instmem(i)];
    return 1;
}
int save(uint32_t i){ //save 5
    memory[instmem(i)]= reg[inst1(i)];
    return 1;
}
int cout(uint32_t i){ //cout 6
    printf("%d",reg[inst1(i)]);
    return 1;
}
int coutl(uint32_t i){ //coutl 7
    printf("%d\n",reg[inst1(i)]);
    return 1;
}
int jmp(uint32_t i){ //jmp 8
    reg[RPC]=startPC-1 + inst1(i);
    return 1;
}
int jmpeq(uint32_t i){ //jmpeq 9
    if(reg[inst1(i)]==reg[inst2(i)]){
        reg[RPC]=startPC-1+inst3(i);
    }
    return 1;
}
int jmpueq(uint32_t i){ //jmpueq 10
    if(reg[inst1(i)]!=reg[inst2(i)]){
        reg[RPC]=startPC-1+inst3(i);
    }
    return 1;
}


typedef int (*opc_f)(uint32_t instruction);
opc_f funcs[__UINT8_MAX__]={ext, mov, add, add2,load, save, cout, coutl, jmp, jmpeq, jmpueq};


void run(){
    int running = 1;
    reg[RPC]=startPC;
    while(running){
        int i = memory[reg[RPC]];
        running = funcs[OPC(i)](i);
        reg[RPC]++;
        
    }
    
}

void loadprogramm(char *filename){
    FILE *file = fopen(filename, "rb");
    
    if(file != NULL){
        fseek(file, 0, SEEK_END);
        long filesize = ftell(file)/4;
        fseek(file,0, SEEK_SET);
        for(int i = 0; i<filesize; i++){
            fread(&memory[startPC + i], sizeof(uint32_t), 1, file);
        }
    } else{
        printf("File not found\b");
    }
}



int main(){
    char file[128]; 
    printf("Enter Filename To load (max 128 characters)\n");
    scanf("%s", file);
    loadprogramm(file);
    run();
    printf("Programm run successfully\n");
    return 1;
    
}