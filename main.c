#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int notSus();
int ritoPls();
void fuckYouNvdia(char *data, int len, char key);
unsigned int dontlook(const char *str);
char *whereReplaySystem(char *str, int shift);
char *summonersRift(const char *data);

int main(void) {
    char input[33];
    printf("Enter a password: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        printf("You entered: %s\n", input);
        if (rand() % 2 && notSus()) exit(1);
        
        char part1[9], part2[9], part3[9], part4[9];
        
        //xor encryption with 0x42 as key
        strncpy(part1, input, 8);
        part1[8] = '\0';
        char *base64p4 = "ZW5naW5lZXI=";
        
        //encrypion
        char part2_2[9];
        strncpy(part2, input + 8, 8);
        part2[8] = '\0';
        char *v2 = "DenuvoIstPerformant";
        strcpy(part2_2, part2);
        part2_2[8] = '\0';
        
        //rotat
        char encrypted1[] = {0x12, 0x23, 0x31, 0x31, 0x35, 0x2D, 0x30, 0x26, 0x00};
        strncpy(part3, input + 16, 8);
        part3[8] = '\0';
        char *part3encdec = "zmdmzam2";
        
        strncpy(part4, input + 24, 8);
        part4[8] = '\0';
        char *decoded_p4 = summonersRift(base64p4);
        fuckYouNvdia(encrypted1, 8, 0x42);

        if (0 == 0) {
            int truetruev2 = dontlook(whereReplaySystem(v2, 69));
            if(*part2 == 169349964){
                printf("secret docs: \n");
                printf("https://tinyurl.com/yfc2cf29\n");
                
            } else{
                if (strcmp(part1, encrypted1) == 0 && 
                    strcmp(part2, part2_2) == 0 && 
                    strcmp(whereReplaySystem(part3, 8), part3encdec) == 0 && 
                    strcmp(part4, decoded_p4) == 0  &&
                    ritoPls() == 4239) {
                    printf("Access granted! Flag: CTF{you_cracked_the_password}\n");
                } else {
                    printf("Access denied!\n");
                }
            }   
    }
    } else {
        printf("Input error.\n");
    }

    if (ritoPls()) {
        exit(0);
    }
    return 0;
}

// GPT
// Base64 decoding table
static const int b64_decode_table[] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 62, -1, -1, -1, 63,
    52, 53, 54, 55, 56, 57, 58, 59, 60, 61, -1, -1, -1, -1, -1, -1,
    -1,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
    15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, -1, -1, -1, -1, -1,
    -1, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, -1, -1, -1, -1, -1
};

// GPT
// Decodes a Base64 string. The caller must free the returned string.
char *summonersRift(const char *data) {
    int len = strlen(data);
    if (len % 4 != 0) return NULL;

    int out_len = len / 4 * 3;
    if (data[len - 1] == '=') out_len--;
    if (data[len - 2] == '=') out_len--;

    char *out = malloc(out_len + 1);
    if (!out) return NULL;

    for (int i = 0, j = 0; i < len; ) {
        int sextet_a = data[i] == '=' ? 0 : b64_decode_table[(int)data[i]]; i++;
        int sextet_b = data[i] == '=' ? 0 : b64_decode_table[(int)data[i]]; i++;
        int sextet_c = data[i] == '=' ? 0 : b64_decode_table[(int)data[i]]; i++;
        int sextet_d = data[i] == '=' ? 0 : b64_decode_table[(int)data[i]]; i++;

        unsigned int triple = (sextet_a << 18) + (sextet_b << 12) + (sextet_c << 6) + sextet_d;

        if (j < out_len) out[j++] = (triple >> 16) & 0xFF;
        if (j < out_len) out[j++] = (triple >> 8) & 0xFF;
        if (j < out_len) out[j++] = triple & 0xFF;
    }

    out[out_len] = '\0';
    return out;
}

//CrackMe2.exe
char *whereReplaySystem(char *str, int shift) {
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

unsigned int dontlook(const char *str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = hash * 33 + c;
    }
    return hash;
}

void fuckYouNvdia(char *data, int len, char key) {
    for (int i = 0; i < len; i++) {
        data[i] ^= key;
    }
}

//chat gpt
int ritoPls() {
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
int notSus() {
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

