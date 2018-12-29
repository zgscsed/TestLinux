#pragma once

#include <string>
#include <iostream>
#include <thread>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <string.h>

# define BUFSIZE 1024
class ClientSocket
{
public:
	ClientSocket(char* ip, unsigned short port);    //传入ip和port
	~ClientSocket();

	int init();                  //初始化,连接服务器  返回0 表示失败 ，1成功
	int recv(std::string &s);    //接收数据           返回-1 表示出错 ，1成功, 0断开连接
	int send(std::string &s);    //发送数据           返回-1 表示失败 ，1成功

	int exec(std::string & sendbuf, std::string & recvbuf);     //发送数据,接收数据

private:
	std::string ip;
	unsigned short port;
	int sock_cli;
	struct sockaddr_in servaddr;

	int flag;                     //接收数据的标志   1接收服务器返回的数据, 0没有

};

