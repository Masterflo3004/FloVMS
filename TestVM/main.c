/* ========NOTES=========
Bits: 32
Opcode 
00000001000000010000000100001010
*/
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
int32_t memory[__UINT16_MAX__];
uint32_t startPC = 0x3000;

int ext(uint32_t i){
    return 0;
}
int mov(uint32_t i){
    reg[inst1(i)] = inst2(i);
    return 1;
}
int add(uint32_t i){
    reg[inst1(i)] = reg[inst2(i)] + reg[inst3(i)];
    return 1;
}
int add2(uint32_t i){
    reg[inst1(i)] = reg[inst2(i)] + inst3(i);
    return 1;
}
int load(uint32_t i){
    reg[inst1(i)]=memory[instmem(i)];
    return 1;
}
int save(uint32_t i){
    memory[instmem(i)]= reg[inst1(i)];
    return 1;
}


typedef int (*opc_f)(uint32_t instruction);
opc_f funcs[__UINT8_MAX__]={ext, mov, add, add2,load, save};


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
        printf("File not found");
    }
}



int main(){
    char file[128]; 
    printf("Enter Filename To load (max 128 characters)");
    scanf("%s", file);
    loadprogramm(file);
    run();
    printf("Programm run successfully\n");
    printf("%d\n",reg[r0]);
    printf("%d\n",reg[r2]);
    printf("%d\n",reg[r3]);
    return 1;
    
}