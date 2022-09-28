#include <string>
#include <iostream>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include "md5.h"

void generateMD5()
{
	std::string msg = "hello world";
	int ret = 0;

	MD5_CTX* ctx = (MD5_CTX*)malloc(sizeof(MD5_CTX));
	// init context
	ret = MD5_Init(ctx);
	if (ret == 0)
	{
		std::cout << "init context failed." << std::endl;
		return;
	}

	ret = MD5_Update(ctx, msg.data(), msg.length());

	unsigned char buf[MD5_DIGEST_LENGTH] = {};
	char buf2[MD5_DIGEST_LENGTH * 2 + 1] = {};

	ret = MD5_Final(buf, ctx);

	for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
	{
		sprintf(&buf2[2 * i], "%02x", buf[i]);
	}

	//std::string res = std::string((char*)buf, MD5_DIGEST_LENGTH);
	std::string res = std::string(buf2, MD5_DIGEST_LENGTH * 2);

	std::cout << res << std::endl;

	free(ctx);
}

void transformData(char* buf2, unsigned char* buf, int len)
{
	for (int i = 0; i < len; i++)
	{
		sprintf(&buf2[i * 2], "%02x", buf[i]);
	}
}

void generateSHA1()
{
	SHA_CTX* ctx = (SHA_CTX*)malloc(sizeof SHA_CTX);
	int ret = 0;
	std::string message = "sha1 message";

	ret = SHA1_Init(ctx);

	ret = SHA1_Update(ctx, message.data(), message.length());

	unsigned char buf[SHA_DIGEST_LENGTH] = {};
	char buf2[SHA_DIGEST_LENGTH * 2 + 1] = {};

	ret = SHA1_Final(buf, ctx);

	transformData(buf2, buf, SHA_DIGEST_LENGTH);

	std::cout << buf2 << std::endl;

	free(ctx);

	// method 2:
	unsigned char buf3[SHA_DIGEST_LENGTH] = {};
	char buf4[SHA_DIGEST_LENGTH * 2 + 1] = {};

	SHA1((unsigned char*)message.data(), message.length(), buf3);

	transformData(buf4, buf3, SHA_DIGEST_LENGTH);

	std::cout << "buf4: " << buf4 << std::endl;
}
