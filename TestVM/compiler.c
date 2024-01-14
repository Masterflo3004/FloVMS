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
        uint32_t binary;
        if(strcmp(ptr, "ext")==0){
            binary = 0b00000000000000000000000000000000;
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled ext %d \n", binary);

        } else if(strcmp(ptr, "mov")==0){
            binary = 0b00000001000000000000000000000000;
            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 16;

            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 8;
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled mov %d \n", binary);
        } else if (strcmp(ptr, "add")==0){
            binary = 0b00000010000000000000000000000000;
            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num <<16;

            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 8;

            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num;

        
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled add %d\n", binary);
        }else if (strcmp(ptr, "add2")==0){
            binary = 0b00000011000000000000000000000000;
            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num <<16;

            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 8;

            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num;

        
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled add2 %d\n", binary);

        }else if (strcmp(ptr, "load")==0){
            binary = 0b00000100000000000000000000000000;
            ptr = strtok(NULL, "");
            if(ptr[0]=='r'){ptr+=1;};
            uint16_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num <<16;

            ptr = strtok(NULL, " ");
            if(ptr && ptr[0]=='r'){ptr+=1;}
            uint16_t num16 = (uint16_t)atoi(ptr);
            binary |= (uint32_t)num16;
            
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled load %d\n", binary);

        }else if (strcmp(ptr, "save")==0){
            binary = 0b00000101000000000000000000000000;
            ptr = strtok(NULL, "");
            if(ptr[0]=='r'){ptr+=1;};
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num <<16;
            
            ptr = strtok(NULL, " ");
            if(ptr && ptr[0]=='r'){ptr+=1;}
            uint16_t num16 = (uint16_t)atoi(ptr);
            binary |= (uint32_t)num16;

            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled save %d\n", binary);

        }else{
            printf("Error|n");
        }
    }
    fclose(file);
    fclose(wfile);
}
//ausgabe: 00000001000010100000000000000000
//gewollt: 00000001000000000000101000000000