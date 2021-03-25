#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static char *argv0;

void
usage(void)
{
	fprintf(stderr, "Usage: %s <atk> <def> <rol> <dmg>\n", argv0);
	exit(1);
}

void
main(int argc, char *argv[])
{
	double atk, def, rol, dmg, ret, dif;
	char *dc;

	argv0 = argv[0] ;

	if(argc<4)
		usage();

	if(!( atk=strtod(argv[1], &dc) ))
		usage();
	if(!( def=strtod(argv[2], &dc) ))
		usage();
	if( !(rol=1-strtod(argv[3], &dc)) && errno==ERANGE)
		usage();
	if( !(dmg=strtod(argv[4], &dc)) )
		usage();

	dif = atk / (atk+def) ;
	ret = (dif - rol) / dif ;
	ret *= dmg ;

	if(ret<0) ret = 0 ;

	printf("%f\n", ret);

	exit(0);
}
