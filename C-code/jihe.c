/*************************************************************************
	> File Name: jihe.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Tue 22 Aug 2017 07:16:41 PM CST
 ************************************************************************/

#include<stdio.h>

struct node{
	int x;
	int y;
	int flag;
};

int main()
{
	int i, j, n;
	struct node point[1024];
	while(scanf("%d", &n) != EOF){
		for (i = 0; i < n; i++){
			scanf("%d %d", &point[i].x, &point[i].y);
			point[i].flag = 0;
		}
/*		for (i = 0; i < n; i++){
			printf("point[%d].x = %d, point[%d].y = %d\n", i, point[i].x, i, point[i].y);
		}*/

		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if(i != j){
					if(point[i].x <= point[j].x && point[i].y <= point[j].y)
						point[i].flag = 1;
				}
			}
		}

		for(i = 0; i < n; i++){
			if(point[i].flag == 0)
				printf("%d %d\n", point[i].x, point[i].y);
		}
	}
	return 0;
}
