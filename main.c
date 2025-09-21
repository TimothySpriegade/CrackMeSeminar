#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int getTracerPidStatus();
int checkForProcesses();
void xor_encrypt_decrypt(char *data, int len, char key);
unsigned int simple_hash(const char *str);
char *rot(char *str, int shift);

int main(void) {
    char input[33];
    printf("Enter a password: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        printf("You entered: %s\n", input);
        //if (rand() % 2 && getTracerPidStatus()) exit(1);
        
        char part1[9], part2[9], part3[9], part4[9];
        
        //xor encryption with 0x42 as key
        strncpy(part1, input, 8);
        part1[8] = '\0';
        char encrypted1[] = {0x12, 0x23, 0x31, 0x31, 0x35, 0x2D, 0x30, 0x26, 0x00};
        xor_encrypt_decrypt(encrypted1, 8, 0x42);
        
        //encrypion
        char part2_2[9];
        strncpy(part2, input + 8, 8);
        part2[8] = '\0';
        strcpy(part2_2, part2);
        part2_2[8] = '\0';
        unsigned int hash2 = 169349964;
        
        //rotat
        strncpy(part3, input + 16, 8);
        part3[8] = '\0';
        char *part3encdec = "zmdmzam2";
        
        strncpy(part4, input + 24, 8);
        part4[8] = '\0';

        if(*part2 == (char)hash2){
            printf("secret docs: \n");
            printf("https://tinyurl.com/yfc2cf29\n");
            
        } else{
            if (strcmp(part1, encrypted1) == 0 && 
                strcmp(part2, part2_2) == 0 && 
                strcmp(rot(part3, 8), part3encdec) == 0 && 
                strcmp(part4, "engineer") == 0 &&
                checkForProcesses() == 4239) {
                printf("Access granted! Flag: CTF{you_cracked_the_password}\n");
            } else {
                printf("Access denied!\n");
            }
        }
        
        
    } else {
        printf("Input error.\n");
    }

    if (checkForProcesses()) {
        exit(0);
    }
    return 0;
}


//CrackMe2.exe
char *rot(char *str, int shift) {
    char *result;
    int length;
    int i;
    
    length = strlen(str);
    result = malloc(length + 1);
    
    for (i = 0; i < length; i++) {
        if (str[i] <= 96 || str[i] > 122) {
            // Not lowercase letter
            if (str[i] <= 64 || str[i] > 90) {
                // Not uppercase letter either - keep as is
                result[i] = str[i];
            } else {
                // Uppercase letter (A-Z)
                result[i] = (str[i] - 65 + shift) % 26 + 65;
            }
        } else {
            // Lowercase letter (a-z)
            result[i] = (str[i] - 97 + shift) % 26 + 97;
        }
    }
    
    result[length] = '\0';
    return result;
}

unsigned int simple_hash(const char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = hash * 33 + c;
    }
    return hash;
}

void xor_encrypt_decrypt(char *data, int len, char key) {
    for (int i = 0; i < len; i++) {
        data[i] ^= key;
    }
}

//chat gpt
int checkForProcesses() {
    FILE *fp;
    char path[1035];
    
    fp = popen("pgrep gdb", "r");
    if (fp == NULL) {
        return -1;
    }
    
    if (fgets(path, sizeof(path), fp) != NULL) {
        pclose(fp);
        return 1;
    }
    
    pclose(fp);
    return 4239;
}

//chat gpt
int getTracerPidStatus() {
    FILE *status_file;
    char line[128];
    
    status_file = fopen("/proc/self/status", "r");
    if (status_file == NULL) {
        return -1;
    }
    
    while (fgets(line, sizeof(line), status_file)) {
        if (strncmp(line, "TracerPid:", 10) == 0) {
            int tracer_pid = atoi(line + 11);
            fclose(status_file);
            return tracer_pid != 0; 
        }
    }
    
    fclose(status_file);
    return 0;
}