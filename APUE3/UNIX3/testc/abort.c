#include  <stdio.h>
#include  <stdlib.h>

void main(void)
{
    FILE *stream;
    if ((stream = fopen("NOSUCHF.ILE", "r")) == NULL)
    {
	perror("Couldn't open file");
	abort();
    }
    else
	fclose(stream);
}
