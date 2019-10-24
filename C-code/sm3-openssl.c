//安装openssl和Gmssl。编译：gcc sm3-openssl.c -lssl -lcrypto

#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <stdio.h>

int main() {
        int code;
	FILE *fp = fopen("./wgs.tar","r+");
	//char fp = "fdfdsdfdsafdsafgfgafg2434315etretredsfadsdfdsafadsgfdgadff";
	EVP_MD_CTX *mdctx = NULL;
	unsigned char msgbuf[BUFSIZ];
	size_t len;
	unsigned char dgst[EVP_MAX_MD_SIZE];
	unsigned int dgstlen = (unsigned int)sizeof(dgst);
//	printf("%d\n", EVP_MAX_MD_SIZE);
	if(!(mdctx = EVP_MD_CTX_create())){
		printf("!!!!!!!!!!!!!!!!!!!\n");
		return -1;
	}

	if(!EVP_DigestInit_ex(mdctx, EVP_sm3(), NULL)){
		EVP_MD_CTX_destroy(mdctx);
		printf("@@@@@@@@@@@@@@@@@@@\n");
		return -1;
	}

	while ((len = fread(msgbuf, 1, sizeof(msgbuf), fp)) > 0) {
		//printf("%ld\n",len);
		if(!EVP_DigestUpdate(mdctx, msgbuf, len)){
			//goto end;
			EVP_MD_CTX_destroy(mdctx);
			printf("#####################\n");
			return -1;
		} 
	}

	if (!EVP_DigestFinal_ex(mdctx, dgst, &dgstlen))	{
		printf("**************\n");
		return -1;
	}
	else{
		for(int i=0; i < dgstlen; i++)
		{
			printf("%02x",dgst[i]);
		}
		printf("\n");
	}
	fclose(fp);
//end:
//	EVP_MD_CTX_free(mdctx);

	return 0;
}
