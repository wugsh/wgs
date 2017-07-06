#include <stdio.h>
#include <string.h>
int sort(int b[], int m, int l)
{
	int i, max;
	max  = b[m];
	for (i = m; i <= l; i++){
		if (b[i] > max)
			max = b[i];
	}
	return max;
		
}
int  main()
{
	int N, M, i, A, B, a[300000];	
	char C[1];
	while(scanf("%d %d", &N, &M) != EOF){
		for(i = 1; i <= N; i++){
			if (scanf("%d", a+i) == EOF)
				break;		
		}
		for (i = 0; i < M; i++){
			if (scanf("%c %d %d", C, &A, &B) == EOF)
				break;
			if (C[0] == 'Q')
				printf("%d\n", sort(a, A, B));				
			if (C[0] == 'U')
				a[A] = B;

		}
	}
	return 0;

}
