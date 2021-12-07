#ifndef SHARE_MEM_H
#define SHARE_MEM_H
#include <stdbool.h>

#define BLOCK_SIZE 1024
#define FILE_NAME "shared_memory"
char  *get_attack(char *filename,int size);
bool get_detech(char *block);
bool destroy(char *filename);
#endif