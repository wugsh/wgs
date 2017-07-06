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
