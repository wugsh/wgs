#include "apue.h"
#include <sys/wait>

#if !defined(LINUX)
#define acct acct_v3
#endif

int main(int argc, char *argv[])
{
    struct acct     acdata;
    FILE            *fd;

}


