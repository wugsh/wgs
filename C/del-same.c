/*************************************************************************
	> File Name: del-same.c
	> Author: 
	> Mail: 
	> Created Time: 2017年02月28日 星期二 21时53分17秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void delsame(char *string)
{
    char *dest;
    int i = 0;
    
    printf("the string length is %d\n", strlen(string));
    *dest  = *string;
    printf("first char is %s\n", dest);
    while (*string != '\0'){
        while (*dest != '\0'){
            if (*(dest) == *string){
                i = 0;
                break;
            }
            dest++;
            i++;
        }
        if (i){
            *dest = *string;
            i = 0;
         }
        string++;
    }
    /*for (i = 0; i < n; i++){
        dest = string;
        for(j = 0; j < strlen(dest); j++){
            if (*(dest+j) != *(string+i))
                *(dest+j+1) = *(string+i);
        }
    ｝*/

    printf("%s\n", dest);

}

int main()
{
    char *sar;
    printf("input string:\n");
   // scanf("%s\n", sar);
    sar  = "abcdfdabcdfadvf";
    printf ("%s\n", sar);
    delsame(sar); 

    return 0;
}
