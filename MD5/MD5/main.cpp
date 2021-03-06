#include <iostream>
#include "MD5.h"
#include<sstream>
#include <iterator>
#include<ctype.h>
#include<string.h>

using namespace std;

string hexto2(string b)
{
	string finala ;
	for (int i = 0; i < 32; i++)
	{
		//cout << i << endl;
		if (b[i] == '0')
		{
			finala += "0000";
		}
		if (b[i] == '1')
		{
			finala += "0001";
		}
		if (b[i] == '2')
		{
			finala += "0010";
		}
		if (b[i] == '3')
		{
			finala += "0011";
		}
		if (b[i] == '4')
		{
			finala+= "0100";
		}
		if (b[i] == '5')
		{
			finala+= "0101";
		}
		if (b[i] == '6')
		{
			finala+= "0110";
		}
		if (b[i] == '7')
		{
			finala += "0111";
		}
		if (b[i] == '8')
		{
			finala+= "1000";
		}
		if (b[i] == '9')
		{
			finala+= "1001";
		}
		if (b[i] == 'a')
		{
			finala+= "1010";
		}
		if (b[i] == 'b')
		{
			finala+= "1011";
		}
		if (b[i] == 'c')
		{
			finala+= "1100";
		}
		if (b[i] == 'd')
		{
			finala += "1101";
		}
		if (b[i] == 'e')
		{
			finala += "1110";
		}
		if (b[i] == 'f')
		{
			finala +=  "1111";
		}//cout << finala[i] ;
	}
	//for (int i = 0; i < 32;i++)
	//cout << endl;
	return finala;

}

int main(int argc, char *argv[]) {
	static  struct {
		char *msg;
		unsigned char hash[16];
	}tests[] = {
		{ "",
		{ 0xd4, 0x1d, 0x8c, 0xd9, 0x8f, 0x00, 0xb2, 0x04,
		0xe9, 0x80, 0x09, 0x98, 0xec, 0xf8, 0x42, 0x7e } },
		{ "a",
		{ 0x0c, 0xc1, 0x75, 0xb9, 0xc0, 0xf1, 0xb6, 0xa8,
		0x31, 0xc3, 0x99, 0xe2, 0x69, 0x77, 0x26, 0x61 } },
		{ "abc",
		{ 0x90, 0x01, 0x50, 0x98, 0x3c, 0xd2, 0x4f, 0xb0,
		0xd6, 0x96, 0x3f, 0x7d, 0x28, 0xe1, 0x7f, 0x72 } },
		{ "message digest",
		{ 0xf9, 0x6b, 0x69, 0x7d, 0x7c, 0xb7, 0x93, 0x8d,
		0x52, 0x5a, 0x2f, 0x31, 0xaa, 0xf1, 0x61, 0xd0 } },
		{ "abcdefghijklmnopqrstuvwxyz",
		{ 0xc3, 0xfc, 0xd3, 0xd7, 0x61, 0x92, 0xe4, 0x00,
		0x7d, 0xfb, 0x49, 0x6c, 0xca, 0x67, 0xe1, 0x3b } },
		{ "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
		{ 0xd1, 0x74, 0xab, 0x98, 0xd2, 0x77, 0xd9, 0xf5,
		0xa5, 0x61, 0x1c, 0x2c, 0x9f, 0x41, 0x9d, 0x9f } },
		{ "12345678901234567890123456789012345678901234567890123456789012345678901234567890",
		{ 0x57, 0xed, 0xf4, 0xa2, 0x2b, 0xe3, 0xc9, 0x55,
		0xac, 0x49, 0xda, 0x2e, 0x21, 0x07, 0xb6, 0x7a } },
		
		{ "ibc",
		{ 0x90, 0x01, 0x50, 0x98, 0x3c, 0xd2, 0x4f, 0xb0,
		0xd6, 0x96, 0x3f, 0x7d, 0x28, 0xe1, 0x7f, 0x72 } },
		{ "aba",
		{ 0x90, 0x01, 0x50, 0x98, 0x3c, 0xd2, 0x4f, 0xb0,
		0xd6, 0x96, 0x3f, 0x7d, 0x28, 0xe1, 0x7f, 0x72 } },
		{ "abg",
		{ 0x90, 0x01, 0x50, 0x98, 0x3c, 0xd2, 0x4f, 0xb0,
		0xd6, 0x96, 0x3f, 0x7d, 0x28, 0xe1, 0x7f, 0x72 } },
		{ "abk",
		{ 0x90, 0x01, 0x50, 0x98, 0x3c, 0xd2, 0x4f, 0xb0,
		0xd6, 0x96, 0x3f, 0x7d, 0x28, 0xe1, 0x7f, 0x72 } },
		{ "ebc",
		{ 0x90, 0x01, 0x50, 0x98, 0x3c, 0xd2, 0x4f, 0xb0,
		0xd6, 0x96, 0x3f, 0x7d, 0x28, 0xe1, 0x7f, 0x72 } },
		{ "abC",
		{ 0x90, 0x01, 0x50, 0x98, 0x3c, 0xd2, 0x4f, 0xb0,
		0xd6, 0x96, 0x3f, 0x7d, 0x28, 0xe1, 0x7f, 0x72 } },
		{ "aBc",
		{ 0x90, 0x01, 0x50, 0x98, 0x3c, 0xd2, 0x4f, 0xb0,
		0xd6, 0x96, 0x3f, 0x7d, 0x28, 0xe1, 0x7f, 0x72 } },
		{ "Abc",
		{ 0x90, 0x01, 0x50, 0x98, 0x3c, 0xd2, 0x4f, 0xb0,
		0xd6, 0x96, 0x3f, 0x7d, 0x28, 0xe1, 0x7f, 0x72 } },


	};
	

	for (int i = 0; i < 15; i++)
	{
		if (i == 7)
		{
			cout << "-----------------雪崩效应---------------------" << endl;
		}
		cout << "第" << i + 1 << "组测试数据" << endl;
		char * message = tests[i].msg;
		cout << "明文消息为：         " << message << endl;
		char buffer[100];
		memset(buffer, 0, sizeof(buffer));
		sprintf(buffer, "%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
			tests[i].hash[0], tests[i].hash[1], tests[i].hash[2], tests[i].hash[3],
			tests[i].hash[4], tests[i].hash[5], tests[i].hash[6], tests[i].hash[7],
			tests[i].hash[8], tests[i].hash[9], tests[i].hash[10], tests[i].hash[11],
			tests[i].hash[12], tests[i].hash[13], tests[i].hash[14], tests[i].hash[15]);
		for (int i = 0; i < strlen(buffer); i++)
		{
			buffer[i] = tolower(buffer[i]);
		}
		cout << "期待的hash值为：     " << buffer << endl;
		MD5 md;
		string result;
		result = md.pad(message);
		cout << "MD5计算出的哈希值为：" << result << endl;
		string b;
		b = buffer;
		
		if (b == result)
		{
			cout << "true";
		}
		else

		{
			cout << "flase" << endl;
			string finala= hexto2(b);
			string finalb = hexto2(result);
			cout << "期待哈希值的二进制:"<<finala << endl;
			cout << "计算哈希值的二进制:" << finalb << endl;
			int count=0;
			for (int i = 0; i < 128; i++)
			{
				if (finala[i] != finalb[i])
					count++;
			}
			cout << "改变的位数为："<<count << endl;
		}
		
		cout << endl;
	}

	
	
	system("pause");
	return 0;
}

