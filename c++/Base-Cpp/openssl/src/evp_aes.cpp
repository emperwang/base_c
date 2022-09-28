#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <string>
#include <iostream>
#include "common.h"

// EVP_aes_256_cbc ����
int aes_256_encrypt(unsigned char* plaintext, int plaintext_len, unsigned char* key, unsigned char* ivec, unsigned char* ciphertext)
{
	EVP_CIPHER_CTX* ctx;
	
	int len, ret;
	int cipherTextLen; // �������ĳ���
	// 1.����һ�� ����������
	ctx = EVP_CIPHER_CTX_new();
	if (!ctx)
	{
		handleErrors();
	}

	// 2. ʹ�ü���key �ͳ�ʼ���� ��ʼ��������
	ret = EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, ivec);
	if (ret <= 0)
	{
		handleErrors();
	}
	
	// 3. ����
	// len: ��ʾ���μ��ܺ���������ĳ���
	ret = EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len);
	if (ret <= 0)
	{
		handleErrors();
	}
	cipherTextLen = len;
	// 4. ������
	ret = EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);

	cipherTextLen += len;

	// 5. clean up
	EVP_CIPHER_CTX_free(ctx);

	return cipherTextLen;



}


// EVP_aes_256_cbc ����
int aes_256_decrypt(unsigned char* ciphertext, int ciphertext_len, unsigned char* key, unsigned char* ivec, unsigned char* plaintext)
{
	EVP_CIPHER_CTX* ctx;
	int len, ret;
	int decryptLen;

	// 1. ����������
	ctx = EVP_CIPHER_CTX_new();
	if (!ctx)
	{
		handleErrors();
	}
	// 2. ��ʼ������������
	ret = EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, ivec);
	if (ret <= 0)
	{
		handleErrors();
	}

	// 3. ��ʼ����
	ret = EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len);
	if (ret <= 0)
	{
		handleErrors();
	}
	decryptLen = len;
	// 4. ���ս���
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

	// 3. Ҫ���ܵ�text
	std::string text = "The quick brown fox jumps over the lazy dog";

	// 4. ���� �洢���ĵ� buffer. ��֤���ĵ�bufferҪ�� ���ĳ�
	unsigned char* encryptData = new unsigned char[text.length()+1];
	int encryptLen;
	// 5. �����洢���ܺ�� buffer
	unsigned char* decryptData = new unsigned char[text.length() + 1];
	int dencryptDataLen;
	// 6. ����
	encryptLen = aes_256_encrypt((unsigned char*)text.data(), text.length(), key, ivec, encryptData);
	// 7. ����
	dencryptDataLen = aes_256_decrypt(encryptData, encryptLen, key, ivec, decryptData);

	std::string result = std::string((char*)decryptData, dencryptDataLen);
	// ��ӡ���ܽ��
	std::cout << "decrypt data: " << result << std::endl;

	delete[] encryptData;
	delete[] decryptData;

}