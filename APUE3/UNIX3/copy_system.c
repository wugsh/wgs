#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    char c = '\0';
    int in = -1, out = -1;

    //以只读方式打开数据文件  
    in = open("kongdong", O_RDONLY);
    //以只写方式创建文件，如果文件不存在就创建一个新的文件  
    //文件属主具有读和写的权限  
    out =
	open("kongdong2", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    while (read(in, &c, 1) == 1)	//读一个字节的数据  
	write(out, &c, 1);	//写一个字节的数据  

    //关闭文件描述符  
    close(in);
    close(out);
    return 0;
}
