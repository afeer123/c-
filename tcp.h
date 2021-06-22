#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<WinSock2.h>
#define HAVE_STRUCT_TIMESPEC
#include<pthread.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
void* say_hello(void* args);
int wsa();
BOOL SOCKET_Select(SOCKET hSocket, int nTimeOut, BOOL bRead);
void* client(void* client);
void menu();