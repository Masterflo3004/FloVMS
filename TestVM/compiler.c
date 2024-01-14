#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(){
    char filename[128];
    printf("Input filename to compile (max 128 characters):\n");
    scanf("%s",&filename);
    printf("Reading File...");
    FILE *file = fopen(filename, "r");
    FILE *wfile = fopen(strcat(filename, ".bin"), "wb");
    char line[128];
    
    while(fgets(line, 128, file)){
        char *ptr= strtok(line, " ");
        __int32_t binary;
        if(ptr == "ext"){
            binary = 0b00000000000000000000000000000000;
            fwrite(&binary, sizeof(__int32_t), 1, wfile);
        } else if(ptr == "mov"){
            binary = 0b00000001000000000000000000000000;
            *ptr = strtok(NULL, " ");
            int8_t num = (int8_t)atoi(ptr+1);
            binary |= (int32_t)num << 24;
            *ptr = strtok(NULL, " ");
            num = (int8_t)atoi(ptr+1);
            binary |= (int32_t)num << 16;
            fwrite(binary, sizeof(__int32_t), 1, wfile);
        } else if (ptr == "add"){
            binary = 0b00000010000000000000000000000000;
            *ptr = strtok(NULL, "r");
            int8_t num = (int8_t)atoi(ptr);
            binary |= (int32_t)num <<24;
            *ptr = strtok(NULL, " ");
            num = (int8_t)atoi(ptr+1);
            binary |= (int32_t)num << 16;
            *ptr = strtok(NULL, " ");
            num = (int8_t)atoi(ptr+1);
            binary |= (int32_t)num << 8;
            *ptr = strtok(NULL, " ");
            num = (int8_t)atoi(ptr+1);
            binary |= (int32_t)num;
        }/* else if (ptr == "add2"){

        }else if (ptr == "load"){

        }else if (ptr == "save"){
            
        }*/ else{
            printf("Error");
        }
    }
    fclose(file);
}