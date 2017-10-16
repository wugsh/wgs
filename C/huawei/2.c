#include <stdio.h>
/*
void insort(int s[], int n){
	int i, j, tmp, data[1001];
	data[0] = s[0];
 	for(i = 1; i < n; i++){
 		for (j = 0; j < i; j++){
			if(s[i] < data[j]){
				tmp = s[i];
				s[i] = data[j];
				data[j] = tmp;
 			}
			data[i] = s[i];

		}
	}
// 	for(i = 0; i < n; i++){
//		printf("%d\n", data[i]);
//	}
}
*/

int main()
{
	int N, i, j, m, flag = 0,l = 1;
    int a[1001], b[1001];
	while(scanf("%d", &N) != EOF) {
		if (scanf("%d", &b[0]) == EOF)
			return 0;

		for (i = 1; i < N; i++){
			if (scanf("%d", &b[i]) == EOF)
				return 0;
		}
			/*
			for(j = 0; j < l; j++){	
				if (b[j] == m){
					flag = 1;
					break;
				}	
			}
			if (flag == 0)	
				b[l++] = m;
			flag = 0;
		
		}	
*/

//		printf("l = %d\n", l);
		int tmp, data[1001];
		data[0] = b[0];
 	for(i = 1; i < N; i++){
 		for (j = 0; j < i; j++){
			if(b[i] < data[j]){
				tmp = b[i];
				b[i] = data[j];
				data[j] = tmp;
 			}
			data[i] = b[i];

		}
	}

		for (i = 0; i < N; i++){
			if (data[i] != data[i+1])
				printf("%d\n", data[i]);
		}
	}
	return 0;
}
