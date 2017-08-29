#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c = 0;
    FILE *pfin = NULL;
    FILE *pfout = NULL;

    //以只读方式打开数据文件
    pfin = fopen("kongdong", "r");
    //以只写方式打开复制的新文件
    pfout = fopen("kongdong2", "w");

    while (fread(&c, sizeof(char), 1, pfin))	//读数据
	fwrite(&c, sizeof(char), 1, pfout);	//写数据
    //关闭文件流
    fclose(pfin);
    fclose(pfout);
    return 0;
}
