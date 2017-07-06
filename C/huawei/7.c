/*
 *

 输入包括多组测试数据。
 每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
 学生ID编号从1编到N。
 第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
 接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
 当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。
 *
 *
 * 输出描述:
 * 对于每一次询问操作，在一行里面输出最高成绩.
 * */


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
