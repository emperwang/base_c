#include <string>
#include <iostream>
#include <openssl/rsa.h>
#include <openssl/bn.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include "rsa.h"
// 生成秘钥
void generateRSA()
{
	RSA* rsa = RSA_new();
	BIGNUM* num = BN_new();
	BN_set_word(num, 12345);

	int ret = 0;
	ret = RSA_generate_key_ex(rsa, 1024, num, NULL);
	std::cout << "generate rsa return val: " << ret << std::endl;

	// 把秘钥写入到文件中
	FILE* file = fopen("private.pem", "w+");

	ret = PEM_write_RSAPrivateKey(file, rsa, NULL, NULL, 0, NULL, NULL);
	std::cout << "pem write Private key: " << ret << std::endl;

	fclose(file);

	file = fopen("public.pem", "w+");
	ret = PEM_write_RSAPublicKey(file, rsa);
	std::cout << "pem write public key: " << ret << std::endl;
	fclose(file);

	RSA_free(rsa);
	BN_free(num);
}
void generateRSABIO()
{
	RSA* rsa = RSA_new();
	BIGNUM* bn = BN_new();
	BN_set_word(bn, 2345);

	int ret = 0;
	ret = RSA_generate_key_ex(rsa, 1024, bn, NULL);
	if (ret <= 0)
	{
		std::cout << "RSA generate failed. return val: " << ret << "error: " << ERR_get_error() << std::endl;
		goto err;
	}
	// 开始把秘钥写入文件
	BIO* bio = BIO_new_file("private1.pem", "w+");
	if (!bio)
	{
		std::cout << "create BIO failed." << std::endl;
		goto err;
	}
	ret = PEM_write_bio_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL);

	if (ret <= 0)
	{
		std::cout << "write private key with bio failed." << std::endl;
		goto err;
	}

	BIO_free(bio);
	bio = BIO_new_file("public1.pem", "w+");
	if (!bio)
	{
		std::cout << "create public key BIO failed." << std::endl;
		goto err;
	}

	ret = PEM_write_bio_RSAPublicKey(bio, rsa);
	if (ret <= 0)
	{
		std::cout << "write public key with bio failed." << std::endl;
		goto err;
	}
	BIO_free(bio);
err:
	RSA_free(rsa);
	BN_free(bn);

}

// 读取秘钥加解密
void RSAEncrypt()
{
	// 1.读取公钥
	RSA* pubKey = RSA_new();
	FILE* fp = fopen("public.pem", "r");
	int ret = 0;
	const char* message = "helloworld";
	std::string result;
	std::string encryptData;
	RSA* tmp = PEM_read_RSAPublicKey(fp, &pubKey, NULL, NULL);
	if (!tmp)
	{
		std::cout << "read Public key failed." << std::endl;
		goto err;
	}
	fclose(fp);

	int pubKeyLen = RSA_size(pubKey);
	// 2. 公钥加密
	char* buf = new char[pubKeyLen];
	ret = RSA_public_encrypt(strlen(message), (unsigned char*)message, (unsigned char*)buf, pubKey, RSA_PKCS1_PADDING);
	if (ret <= 0)
	{
		std::cout << "RSA public key encrypt failed." << std::endl;
		goto err;
	}
	encryptData = std::string(buf, ret);
	std::cout << "encrypt data: " << encryptData << std::endl;
	delete[] buf;
	// 3. 读取私钥
	RSA* priKey = RSA_new();
	fp = fopen("private.pem", "r");
	tmp = PEM_read_RSAPrivateKey(fp, &priKey, NULL, NULL);
	if (!tmp)
	{
		std::cout << "read private key failed." << std::endl;
		goto err;
	}
	fclose(fp);
	int priKeyLen = RSA_size(priKey);
	// 4. 私钥解密
	/*unsigned char buf2[1024];
	memset(buf2, 0, sizeof buf2);*/
	char* buf2 = new char[priKeyLen];
	ret = RSA_private_decrypt(encryptData.length(), (unsigned char*)encryptData.data(), (unsigned char*)buf2,
		priKey, RSA_PKCS1_PADDING);
	result = std::string(buf2, ret);
	std::cout << "decrypt data: " << result << std::endl;
	delete[] buf2;

err:
	RSA_free(pubKey);
	RSA_free(priKey);

}


void RSAEncryptWithBio()
{
	// 1.创建需要的变量
	RSA* pubKey = RSA_new();
	RSA* priKey = RSA_new();
	BIO* bio = BIO_new_file("public1.pem", "r");
	int ret = 0;
	std::string message = "openssl的世界";
	std::string encryptData;
	std::string decryptData;
	// 2. 读取公钥
	PEM_read_bio_RSAPublicKey(bio, &pubKey, NULL, NULL);
	if (pubKey == NULL)
	{
		std::cout << "read public key failed." << ERR_get_error() << std::endl;
		BIO_free(bio);
		goto err;
	}
	BIO_free(bio);
	// 3. 进行加密
	int publicKeyLen = RSA_size(pubKey);
	char* buf = new char[publicKeyLen];
	ret = RSA_public_encrypt(message.length(), (unsigned char*)message.data(), (unsigned char*)buf, pubKey, RSA_PKCS1_PADDING);
	if (ret <= 0)
	{
		std::cout << "RSA encrypt failed." << ERR_get_error() << std::endl;
		goto err1;
	}
	encryptData = std::string(buf, ret);
	// 4. 读取私钥
	bio = BIO_new_file("private1.pem", "r");
	PEM_read_bio_RSAPrivateKey(bio, &priKey, NULL, NULL);
	if (!priKey)
	{
		std::cout << "read private key failed." << ERR_get_error() << std::endl;
		BIO_free(bio);
		goto err1;
	}
	BIO_free(bio);
	// 5. 使用私钥解密
	int priKeyLen = RSA_size(priKey);
	char* buf2 = new char[priKeyLen];
	ret = RSA_private_decrypt(encryptData.length(), (unsigned char*)encryptData.data(), (unsigned char*)buf2, priKey, RSA_PKCS1_PADDING);
	if (ret <= 0)
	{
		std::cout << "RSA decrypt data failed." << ERR_get_error() << std::endl;
		goto err2;
	}
	decryptData = std::string(buf2, ret);
	// 6. 打印解密的内容
	std::cout << "decrypt data: " << decryptData << std::endl;

err2:
	delete[] buf2;
err1:
	delete[] buf;
err:
	RSA_free(pubKey);
	RSA_free(priKey);

}