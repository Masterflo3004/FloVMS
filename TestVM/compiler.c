#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(){
    char filename[128];
    printf("Input filename to compile (max 128 characters):\n");
    scanf("%s",&filename);
    printf("\n Reading File...\n");
    FILE *file = fopen(filename, "r");
    FILE *wfile = fopen(strcat(filename, ".bin"), "wb");
    char line[128];
    
    while(fgets(line, 128, file)){
        char *ptr= strtok(line, " ");
        uint32_t binary = (uint32_t)0<<24;
        if(strcmp(ptr, "ext")==0){
            binary = (int32_t)0;
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled ext %d \n", binary);

        } else if (strcmp(ptr, "mov")==0){
            binary = (int32_t)1<<24;
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
            binary = (int32_t)2<<24;
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
        } else if (strcmp(ptr, "add2")==0){
            binary = (int32_t)3<<24;
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

        } else if (strcmp(ptr, "load")==0){
            binary = (int32_t)4<<24;
            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;};
            uint16_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num <<16;

            ptr = strtok(NULL, " ");
            if(ptr && ptr[0]=='r'){ptr+=1;}
            uint16_t num16 = (uint16_t)atoi(ptr);
            binary |= (uint32_t)num16;
            
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled load %d\n", binary);

        } else if (strcmp(ptr, "save")==0){
            binary = (int32_t)5<<24;
            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;};
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num <<16;
            
            ptr = strtok(NULL, " ");
            uint16_t num16 = (uint16_t)atoi(ptr);
            binary |= (uint32_t)num16;

            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled save %d\n", binary);

        } else if (strcmp(ptr, "cout")==0){
            binary = (int32_t)6<<24;
            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num <<16;

            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled cout %d\n", binary);

        } else if (strcmp(ptr, "coutl")==0){
            binary = (int32_t)7<<24;
            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 16;

            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled coutl %d\n", binary);
        } else if (strcmp(ptr, "jmp")==0){
            binary = (int32_t)8<<24;
            ptr = strtok(NULL, " ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 16;

            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled jmp %d\n", binary);

        } else if (strcmp(ptr, "jmpeq")==0){
            binary = (int32_t)9<<24;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 16;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 8;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num;
            
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled jmpeq %d\n", binary);

        } else if (strcmp(ptr, "jmpueq")==0){
            binary = (int32_t)10<<24;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 16;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 8;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num;
            
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled jmpueq %d\n", binary);

        } else if (strcmp(ptr, "jmpbig")==0){
            binary = (int32_t)11<<24;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 16;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 8;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num;
            
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled jmpbig %d\n", binary);

        } else if (strcmp(ptr, "jmplow")==0){
            binary = (int32_t)12<<24;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 16;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 8;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num;
            
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled jmplow %d\n", binary);
        } else if (strcmp(ptr, "coutscii")==0){
            binary = (int32_t)13 << 24;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 16;
            
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled coutscii %d\n", binary);
        } else if (strcmp(ptr, "coutlscii")==0){
            binary = (int32_t)13 <<24;

            ptr = strtok(NULL," ");
            if(ptr[0]=='r'){ptr+=1;}
            uint8_t num = (uint8_t)atoi(ptr);
            binary |= (uint32_t)num << 16;
            
            fwrite(&binary, sizeof(uint32_t), 1, wfile);
            printf("compiled coutlscii %d\n", binary);
        } else {
            printf("Error\n");
        }
    }
    fclose(file);
    fclose(wfile);
}