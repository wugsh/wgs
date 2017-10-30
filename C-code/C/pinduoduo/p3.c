#include <stdio.h>

void sort(int s[], int n)
{
	int i, j, d;
	d = n / 2;
	while(d >= 1){
		for(i = d+1; i <=n; i++){
			s[0] = s[i];
			j = i - d;
			while((j > 0) && (s[0] < s[j])){
				s[j+d] = s[j];
				j = j - d;
			}
			s[j+d] = s[0];
		}
		d  = d / 2;
	}

}

int main()
{
	int n, m, i, j, h[1024], w[1024];
	int count;
	while(scanf("%d", &n) != EOF){
		count = 0;
		for(i = 1; i <= n; i++){
			scanf("%d",h+i);
		}
		sort(h, n);

		scanf("%d", &m);
		for(j = 1; j <= m; j++){
			scanf("%d",w+j);
		}
		sort(w, m);
		for (j = m; j > 0; j--){
			for (i = n; i > 0; i--){
				if (w[j] >= h[i]){
					count++;
					h[i] = w[m] + 1;
					break;
				}
			}
		}
		printf("%d\n", count);

	}
	return 0;
}
