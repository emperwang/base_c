#include <openssl/aes.h>
#include <string>
#include <iostream>

void AESEncrypt()
{
	// 1. ���ü���key
	AES_KEY encryptKey, dencryptKey;
	std::string usrKey = "1234567887654321";
	AES_set_encrypt_key((unsigned char*)usrKey.data(), usrKey.length()*8, &encryptKey);
	AES_set_decrypt_key((unsigned char*)usrKey.data(), usrKey.length() * 8, &dencryptKey);
	const char* encryptData = "ָ����֤��ȡ��ǵ�CAҲ�Ƿֲ�εİɣ�����Է���֤���ǩ��CA����Root CA,��ô�������ȥ��֤����CA��֤��ǩ����CA�� һֱ��Root CA. Ŀǰ����֤������ʹ����CA���ϵ�ĳһ��֤����֤������Ҳ����Ӱ��Ը�����CA����ݵ���֤����������CA���ϵ����ⶼ���Լ���������ȻCA����֤�����Ⲣ����ֱ������������϶Ͽ����õ�Ӧ�ó���������������֤���������һ����ô��";

	// 2. ����
	unsigned char ivec[AES_BLOCK_SIZE];
	memset(ivec, 9, sizeof(ivec));
	int length = 0;
	int len = strlen(encryptData);
	if ((len % 16) == 0)
	{
		length = len;
	}
	else
	{
		length = (len / 16 + 1)*16;
	}
	unsigned char* out = new unsigned char[length + 1];
	AES_cbc_encrypt((unsigned char*)encryptData, out, length, &encryptKey, ivec, AES_ENCRYPT);

	// 3. ����
	memset(ivec, 9, sizeof(ivec));
	unsigned char* data = new unsigned char[length + 1];
	AES_cbc_encrypt(out, data, length, &dencryptKey, ivec, AES_DECRYPT);


	// 4. ��ӡ���ܺ������
	std::cout << "decrypt data: " << data << std::endl;

	delete[] out;
	delete[] data;
}