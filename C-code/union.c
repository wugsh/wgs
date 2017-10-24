#include <stdio.h>
#include <string.h>

union uni {
	struct {
		int n3;
	} s1;
	struct {
		int n4;
		int n5;
	} s2;
};

int main()
{
	union uni u;
	int *p = &u.s2.n4;
	memset(&u, 0, sizeof(u));	
	u.s1.n3 = 1;
	u.s2.n4 = 2;
	u.s2.n5 = 3;
	*p = 4;
	printf("%d, %d, %d\n", u.s1.n3, u.s2.n4, u.s2.n5); //4, 4, 3
	return 0;
}
