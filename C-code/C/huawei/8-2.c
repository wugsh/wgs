/*
开发一个简单错误记录功能小模块，能够记录出错的代码所在的文件名称和行号。 
处理:
1.记录最多8条错误记录，对相同的错误记录(即文件名称和行号完全匹配)只记录一条，错误计数增加；(文件所在的目录不同，文件名和行号相同也要合并)
2.超过16个字符的文件名称，只记录文件的最后有效16个字符；(如果文件名不同，而只是文件名的后16个字符和行号相同，也不要合并)
3.输入的文件可能带路径，记录文件名称不能带路径

输入描述:
一行或多行字符串。每行包括带路径文件名称，行号，以空格隔开。

    文件路径为windows格式

    如：E:\V1R2\product\fpgadrive.c 1325


输出描述:
将所有的记录统计并将结果输出，格式：文件名代码行数数目，一个空格隔开，如: fpgadrive.c 1325 1 

    结果根据数目从多到少排序，数目相同的情况下，按照输入第一次出现顺序排序。

    如果超过8条记录，则只输出前8条记录.

    如果文件名的长度超过16个字符，则只输出后16个字符
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
  
typedef struct{
  char name[500];
  char cut[20];
  int row;
  int count;
  // inital position
  int pos;
}Rec;
  
int cmp(const void *a, const void *b){
  Rec x = *((Rec *)a);
  Rec y = *((Rec *)b);
  int tmp = strcmp(x.name,y.name);
  if ( tmp == 0 )
    return x.row - y.row;
  return tmp;
}
  
int cmp2(const void *a, const void *b){
  Rec x = *((Rec *)a);
  Rec y = *((Rec *)b);
  int tmp = y.count - x.count;
  if ( tmp == 0 )
    return x.pos - y.pos;
  return tmp;
}
  
int get_split(char *data){
  int i,len;
  for ( i = strlen(data) - 1; i >= 0; i -- ){
    if (data[i] == '\\')
      return i;
  }
  return 0;
}
  
int main(){
  char path[1000];
  int row;
  int len;
  int n,i = 0,j  = 0;
  char *name;
  Rec data[1000];
  Rec res[1000];
  while( scanf("%s%d",path,&row) != EOF ){
    name = path + get_split(path) + 1;
    strcpy(data[i].name,name);
    len = strlen(name);
    if ( len > 16 ){
      name = name + (len - 16);
    }
    strcpy(data[i].cut,name);
    data[i].row = row;
    data[i].count = 1;
    data[i].pos = i;
    i ++;
  }
  n = i;
  qsort(data,n,sizeof(Rec),cmp);
  i = j = 0;
  res[j++] = data[i++];
  while( i < n ){
    if ( strcmp(data[i].name,res[j-1].name) == 0 && data[i].row == res[j-1].row ){
      res[j-1].count ++;
    }
    else{
      res[j++] = data[i];
    }
    i ++;
  }
  qsort(res,j,sizeof(Rec),cmp2);
  j = j > 8 ? 8 : j;
  for ( i = 0; i < j; i ++ ){
    printf("%s %d %d\n",res[i].cut,res[i].row,res[i].count);
  }
  return 0;
}