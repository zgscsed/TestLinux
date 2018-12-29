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
	ClientSocket(char* ip, unsigned short port);    //����ip��port
	~ClientSocket();

	int init();                  //��ʼ��,���ӷ�����  ����0 ��ʾʧ�� ��1�ɹ�
	int recv(std::string &s);    //��������           ����-1 ��ʾ���� ��1�ɹ�, 0�Ͽ�����
	int send(std::string &s);    //��������           ����-1 ��ʾʧ�� ��1�ɹ�

	int exec(std::string & sendbuf, std::string & recvbuf);     //��������,��������

private:
	std::string ip;
	unsigned short port;
	int sock_cli;
	struct sockaddr_in servaddr;

	int flag;                     //�������ݵı�־   1���շ��������ص�����, 0û��

};

