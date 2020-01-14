%{
	#include <stdio.h>
	#include <stdlib.h>

	void yyerror(char *);
%}
%token number
%right UnaryMinus

%%
Line    : Line Expr '\n'	{printf("OUTPUT: %d\n", $2);}
	| Line '\n' 
	| error '\n'		{YYABORT;}
	|
	;

Expr	: Expr '+' Term		{$$ = $1 + $3;}
	| Expr '-' Term		{$$ = $1 - $3;}
	| Term

Term	: Term '*' Factor	{$$ = $1 * $3;} 
	| Term '/' Factor	{if( $3 == 0 ) {yyerror("Undefined\n");YYABORT;}else $$ = $1 / $3;} 
	| Factor

Factor	: '(' Expr ')'		{$$ = $2;}
	| number		{$$ = $1;}
	| Factor number		{$$ = $1 * 10 + number;}
	| '-' Factor %prec UnaryMinus {$$ = -$2;}

%%
void yyerror(char *s) {
    printf("%s\n", s);
}

int main() {
	while(1)
	{
		yyparse();
	}
	return 0;
}
/*
3*(4+5)
*7+- 4
1+2*5
*/