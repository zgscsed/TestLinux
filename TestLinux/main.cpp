#include "clientSocket.h"
#include <json\json.h>

int main(void)
{
	ClientSocket cs("192.168.232.131", 6000);

	int ret = cs.init();

	if (ret == 0)
	{
		return 0;
	}

	Json::Value peoples;
	Json::Value val;

	int n;                   //ͨѶ¼����
	std::string sendstr;
	std::string recvstr;
	std::cout << "�����������" << std::endl;
	std::cin >>n;

	for (int i = 0; i < n; i++)
	{
		std::cout << "�� " << i + 1 << "���˵���Ϣ" << std::endl;
		std::cin >> sendstr;
		val["name"] = sendstr;
		std::cin >> sendstr;
		val["num"] = sendstr;

		peoples.append(val);
	}
	std::cout << "����Ҫ���������:(ʾ����zhansan 1927384)" << std::endl;
	
	ret = cs.exec(sendstr, recvstr);

	while (1);

	return 0;
}



