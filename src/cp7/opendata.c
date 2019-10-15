#include	<stdio.h>

FILE *
open_data(void)
{
	FILE	*fp;
	char	databuf[BUFSIZ];  /* setvbuf makes this the stdio buffer */

	if ((fp = fopen("datafile", "r")) == NULL)
		return(NULL);
	if (setvbuf(fp, databuf, _IOLBF, BUFSIZ) != 0)
		return(NULL);
	return(fp);		/* error */
}

int
main(void)
{
	FILE * fp;
	if(!(fp = open_data())){
		printf("open_data error.\n");
	}
	return 0;
}
