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
        if(strcmp(ptr, "ext")==0){
            binary = 0b00000000000000000000000000000000;
            fwrite(&binary, sizeof(__int32_t), 1, wfile);
            printf("compiled ext %d \n", binary);

        } else if(strcmp(ptr, "mov")==0){
            binary = 0b00000001000000000000000000000000;
            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            int8_t num = (int8_t)atoi(ptr);
            binary |= (int32_t)num << 24;

            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (int8_t)atoi(ptr);
            binary |= (int32_t)num << 16;
            fwrite(&binary, sizeof(__int32_t), 1, wfile);
            printf("compiled mov %d \n", binary);
        } else if (strcmp(ptr, "add")==0){
            binary = 0b00000010000000000000000000000000;
            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            int8_t num = (int8_t)atoi(ptr);
            binary |= (int32_t)num <<24;

            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (int8_t)atoi(ptr);
            binary |= (int32_t)num << 16;

            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (int8_t)atoi(ptr);
            binary |= (int32_t)num << 8;

        
            fwrite(&binary, sizeof(__int32_t), 1, wfile);
            printf("compiled add %d\n", binary);
        }/* else if (strcmp(ptr, "add2")){

        }else if (strcmp(ptr, "load")){

        }else if (strcmp(ptr, "save")){
            
        }*/ else{
            printf("Error|n");
        }
    }
    fclose(file);
    fclose(wfile);
}