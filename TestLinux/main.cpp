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

	int n;                   //通讯录人数
	std::string sendstr;
	std::string recvstr;
	std::cout << "请输入个数：" << std::endl;
	std::cin >>n;

	for (int i = 0; i < n; i++)
	{
		std::cout << "第 " << i + 1 << "个人的信息" << std::endl;
		std::cin >> sendstr;
		val["name"] = sendstr;
		std::cin >> sendstr;
		val["num"] = sendstr;

		peoples.append(val);
	}
	std::cout << "输入要传输的数据:(示例：zhansan 1927384)" << std::endl;
	
	ret = cs.exec(sendstr, recvstr);

	while (1);

	return 0;
}



