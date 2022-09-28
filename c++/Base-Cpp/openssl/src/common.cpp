#include <openssl/err.h>

void handleErrors()
{
	ERR_print_errors_fp(stderr);
	abort();
}

