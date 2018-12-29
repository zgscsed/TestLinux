#include "clientSocket.h"



ClientSocket::ClientSocket(char* ip, unsigned short port)
{
	this->ip = ip;
	this->port = port;

	flag = 0;
}


ClientSocket::~ClientSocket()
{
}

int ClientSocket::init()
{
	sock_cli = socket(AF_INET, SOCK_STREAM, 0);
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = inet_addr(ip.data());
	if (connect(sock_cli, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
	{
		std::cout << "socket connect server fail" << std::endl;
		return 0;
	}

	return 1;
}

int ClientSocket::recv(std::string &s)
{
	s = "";
	char recvbuf[BUFSIZE];
	int len = 0;
	int sum = 0;
	memset(recvbuf, 0, sizeof(recvbuf));
	do
	{
		len = ::recv(sock_cli, recvbuf, sizeof(recvbuf), 0);
		if (len < 0)
		{
			std::cout << "socket ���ӳ���" << std::endl;
			return -1;
		}
		else if (len == 0)
		{
			std::cout << "socket�Ͽ�����" << std::endl;
			return 0;
		}

		s = s+std::string(recvbuf);
		sum = sum + len;
		std::cout << "����: " << len << "�ѽ������ݣ� "<<sum<< std::endl;
	}while (len==BUFSIZE);

	flag = 1;
	return 1;
	
}

int ClientSocket::send(std::string &s)
{
	char sendbuf[BUFSIZE];
	int sum = s.size();
	int count = 0;
	int len = s.size();
	int i = 0;          //��¼s�Ѹ��Ƶ�λ��
	memset(sendbuf, 0, sizeof(sendbuf));
	while (len > BUFSIZE)
	{
		s.copy(sendbuf, BUFSIZE, i);
		int ret =::send(sock_cli, sendbuf, BUFSIZE, 0);
		if (ret < 0)
		{
			std::cout << "send fail";
			return -1;
		}
		len = len - BUFSIZE;
		i = i + BUFSIZE;
		count += BUFSIZE;
		std::cout << "�ѷ���: " << count  << "�ܵķ�������:" << sum << std::endl;
	}

	s.copy(sendbuf, len, i);
	*(sendbuf + len) = '/0';
	::send(sock_cli, sendbuf, strlen(sendbuf), 0);
	count += strlen(sendbuf);
	std::cout << "�ѷ���: " << count << "�ܵķ�������:" << sum << std::endl;

	return 1;
}

int ClientSocket::exec(std::string & sendstr, std::string & recvstr)
{
	std::cout << "��������:" << sendstr << sendstr<<std::endl;
	send(sendstr);

	std::cout << "�ȴ���������Ӧ:... " << std::endl;
	recv(recvstr);
	std::cout << "��������" << recvstr << std::endl;
	return 1;


}

