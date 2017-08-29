//给定一个字符串，把字符串内的字母转换成该字母的下一个字母，a换成b，
//z换成a，Z换成A，如aBf转换成bCg，字符串内的其他字符不改变，给定函数，编写函数


#include <stdio.h>
#include <string.h>

int main()
{
	char input[100];
	int n, i;
	gets(input);
	n = strlen(input);
	for (i = 0; i < n; i++){
		if ('A' <= input[i] && input[i] <= 'Z'){
			if (input[i] == 'Z')
				input[i] = 'A';
			else input[i]++;
		}
		if ('a' <= input[i] && input[i] <= 'z'){
			if (input[i] == 'z')
				input[i] = 'a';
			else
				input[i]++;
		}	
	}

	puts(input);
	
	return 0;

}
