#include "aes.h"
#include "rsa.h"
#include "md5.h"

#ifdef  __cplusplus
extern "C" {
#endif
#include <openssl/applink.c>
#ifdef  __cplusplus
}
#endif


int main(int argc, char** argv)
{
	//generateMD5();
	//generateSHA1();
	//generateRSA();
	//generateRSABIO();
	//RSAEncrypt();
	//RSAEncryptWithBio();
	AESEncrypt();

	return 0;
}


