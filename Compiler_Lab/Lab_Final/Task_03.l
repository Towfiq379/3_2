%{
#include <stdlib.h>
#include "y.tab.h"
%}

%%
[0-9]+      { yylval = atoi(yytext); return number; }
[ \t]       ; 
.|\n        {return yytext[0];}

%%
int yywrap( void )
{
	return 1;
}