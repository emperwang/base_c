#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <string>
#include <iostream>
#include "common.h"

// EVP_aes_256_cbc 加密
int aes_256_encrypt(unsigned char* plaintext, int plaintext_len, unsigned char* key, unsigned char* ivec, unsigned char* ciphertext)
{
	EVP_CIPHER_CTX* ctx;
	
	int len, ret;
	int cipherTextLen; // 最后的密文长度
	// 1.创建一个 加密上下文
	ctx = EVP_CIPHER_CTX_new();
	if (!ctx)
	{
		handleErrors();
	}

	// 2. 使用加密key 和初始向量 初始化上下文
	ret = EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, ivec);
	if (ret <= 0)
	{
		handleErrors();
	}
	
	// 3. 加密
	// len: 表示本次加密后输出的密文长度
	ret = EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len);
	if (ret <= 0)
	{
		handleErrors();
	}
	cipherTextLen = len;
	// 4. 最后加密
	ret = EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);

	cipherTextLen += len;

	// 5. clean up
	EVP_CIPHER_CTX_free(ctx);

	return cipherTextLen;



}


// EVP_aes_256_cbc 解密
int aes_256_decrypt(unsigned char* ciphertext, int ciphertext_len, unsigned char* key, unsigned char* ivec, unsigned char* plaintext)
{
	EVP_CIPHER_CTX* ctx;
	int len, ret;
	int decryptLen;

	// 1. 创建上下文
	ctx = EVP_CIPHER_CTX_new();
	if (!ctx)
	{
		handleErrors();
	}
	// 2. 初始化解密上下文
	ret = EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, ivec);
	if (ret <= 0)
	{
		handleErrors();
	}

	// 3. 开始解密
	ret = EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len);
	if (ret <= 0)
	{
		handleErrors();
	}
	decryptLen = len;
	// 4. 最终解密
	ret = EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
	decryptLen += len;

	// 5. clean
	EVP_CIPHER_CTX_free(ctx);
	return decryptLen;
}


void aes_256_test()
{
	int ret;
	// 1. create key 32*8 = 256
	unsigned char key[32];
	ret = RAND_bytes(key, sizeof(key));
	if (ret <= 0)
	{
		std::cout << "creat rand key failed." << std::endl;
		abort();
	}
	// 2. creat ivec
	unsigned char ivec[AES_BLOCK_SIZE];
	ret = RAND_bytes(ivec, AES_BLOCK_SIZE);
	if (ret <= 0)
	{
		std::cout << "create ivec failed." << std::endl;
		abort();
	}

	// 3. 要加密的text
	std::string text = "The quick brown fox jumps over the lazy dog";

	// 4. 创建 存储密文的 buffer. 保证密文的buffer要比 明文长
	unsigned char* encryptData = new unsigned char[text.length()+1];
	int encryptLen;
	// 5. 创建存储解密后的 buffer
	unsigned char* decryptData = new unsigned char[text.length() + 1];
	int dencryptDataLen;
	// 6. 加密
	encryptLen = aes_256_encrypt((unsigned char*)text.data(), text.length(), key, ivec, encryptData);
	// 7. 解密
	dencryptDataLen = aes_256_decrypt(encryptData, encryptLen, key, ivec, decryptData);

	std::string result = std::string((char*)decryptData, dencryptDataLen);
	// 打印解密结果
	std::cout << "decrypt data: " << result << std::endl;

	delete[] encryptData;
	delete[] decryptData;

}