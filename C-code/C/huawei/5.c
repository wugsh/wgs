/**
 * 输入一个字符串，求出该字符串包含的字符集合
 *
 * 输入描述:
 * 每组数据输入一个字符串，字符串最大长度为100，且只包含字母，不可能为空串，区分大小写。
 *
 *
 * 输出描述:
 * 每组数据一行，按字符串原有的字符顺序，输出字符集合，即重复出现并靠后的字母不输出。
 * */
#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, l, m, flag;
	char input[100], output[100];

	while(gets(input)){
		l = strlen(input);
		output[0] = input[0];
	
		for (i = 1; i < l; i++) {
			m = strlen(output);
			flag = 1;
	
			for (j = 0; j < m; j++){
				if (output[j] == input[i]){
					flag = 0;
					break;
				}
			}
	
			if (flag == 1)
				output[m] = input[i];
		}

		printf("%s\n", output);
	}
	return 0;
}
