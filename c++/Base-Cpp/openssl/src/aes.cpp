#include <openssl/aes.h>
#include <string>
#include <iostream>

void AESEncrypt()
{
	// 1. 设置加密key
	AES_KEY encryptKey, dencryptKey;
	std::string usrKey = "1234567887654321";
	AES_set_encrypt_key((unsigned char*)usrKey.data(), usrKey.length()*8, &encryptKey);
	AES_set_decrypt_key((unsigned char*)usrKey.data(), usrKey.length() * 8, &dencryptKey);
	const char* encryptData = "指定验证深度。记得CA也是分层次的吧？如果对方的证书的签名CA不是Root CA,那么你可以再去验证给该CA的证书签名的CA， 一直到Root CA. 目前的验证操作即使这条CA链上的某一个证书验证有问题也不会影响对更深层的CA的身份的验证。所以整个CA链上的问题都可以检查出来。当然CA的验证出问题并不会直接造成连接马上断开，好的应用程序可以让你根据验证结果决定下一步怎么走";

	// 2. 加密
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

	// 3. 解密
	memset(ivec, 9, sizeof(ivec));
	unsigned char* data = new unsigned char[length + 1];
	AES_cbc_encrypt(out, data, length, &dencryptKey, ivec, AES_DECRYPT);


	// 4. 打印解密后的数据
	std::cout << "decrypt data: " << data << std::endl;

	delete[] out;
	delete[] data;
}