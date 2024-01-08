#ifndef BASIC_AUTH
#define BASIC_AUTH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void create_db();
int check_db();
int register_user(char* username, char* password);
int login(char* username, char* password);

#endif