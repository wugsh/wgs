#include<stdio.h>
#include<string.h>
 
int main()
{
    int i, len, c[52] = { 0 };
    char s[101];

	while(scanf("%s",s) != EOF){
        for(i = 0, len = strlen(s);i < len; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                if(c[s[i] - 'a'] == 0){
                    printf("%c", s[i]);
                    c[s[i] - 'a'] = 1;
                }
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                if(c[s[i] - 'A' + 26] == 0){
                    printf("%c", s[i]);
                    c[s[i] - 'A' + 26] = 1;
                }
            }
        }
        printf("\n");
        for(i = 0; i < 52; i++)
            c[i] = 0;
    }
    return 0;
}
