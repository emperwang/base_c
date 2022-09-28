#pragma once
int aes_256_encrypt(unsigned char* plaintext, int plaintext_len, unsigned char* key, unsigned char* ivec, unsigned char* ciphertext);
int aes_256_decrypt(unsigned char* ciphertext, int ciphertext_len, unsigned char* key, unsigned char* ivec, unsigned char* plaintext);
void aes_256_test();
