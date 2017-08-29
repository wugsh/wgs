/**
 *数独是一个我们都非常熟悉的经典游戏，运用计算机我们可以很快地解开数独难题，现在有一些简单的数独题目，请编写一个程序求解。

 输入描述:

 输入9行，每行为空格隔开的9个数字，为0的地方就是需要填充的。


 输出描述:

 输出九行，每行九个空格隔开的数字，为解出的答案。
 先说下数独的游戏规则：
 在一个9x9的方格中，你需要把数字1-9填写到空格当中，并且使方格的每一行和每一列中都包含1-9这九个数字。同时还要保证，空格中用粗线划分成9个3x3的方格也同时包含1-9这九个数字。比如有这样一个题，大家可以仔细观察一下，在这里面每行、每列，以及每个3x3的方格都包含1-9这九个数字。

 简单的DFS，将所有未填的位置依次保存起来，之后，对每一个未填的位置依次枚举，往下搜即可
 *
 * */

#include<stdio.h>
struct point
{
    int x, y;
} p[81];
int num, flag, map[10][10];
int judge(int n, int k)
{
    int i, j, x, y;
    for(i = 0; i < 9; i++)
    {
        if(i != p[n].y && map[p[n].x][i] == k)
            return 0;
        if(i != p[n].x && map[i][p[n].y] == k)
            return 0;
    }
    x = p[n].x / 3 * 3;
    y = p[n].y / 3 * 3;
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            if(map[x+i][y+j] == k && (i != p[n].x || j != p[n].y))
                return 0;
    return 1;
}
void dfs(int n)
{
    int i;
    if(n == num)
    {
        flag = 1;
        return;
    }
    for(i = 1; i < 10; i++)
    {
        if(judge(n, i))
        {
            map[p[n].x][p[n].y] = i;
            dfs(n + 1);
            if(flag)
                return;
            map[p[n].x][p[n].y] = 0;
        }
    }
    return;
}
int main()
{
    int i, j, t = 0;
    char s[2];
    while(scanf("%s", s) != -1)
    {
        num = flag = 0;
        if(s[0] == '0')
            p[num].x = 0, p[num++].y = 0, map[0][0] = 0;
        else
            map[0][0] = s[0] - '0';
        for(i = 0; i < 9; i++)
            for(j = 0; j < 9; j++)
                if(i || j)
                {
                    scanf("%s", s);
                    if(s[0] == '0')
                        p[num].x = i, p[num++].y = j, map[i][j] = 0;
                    else
                        map[i][j] = s[0] - '0';
                }
        dfs(0);
        if(t++)
            printf("\n");
        for(i = 0; i < 9; i++)
        {
            for(j = 0; j < 8; j++)
                printf("%d ", map[i][j]);
            printf("%d\n", map[i][8]);
        }
    }
    return 0;
}
