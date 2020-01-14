%option noyywrap
%{
	#include<bits/stdc++.h>
	using namespace std;
	set <string> Key, Iden, Num, Logic_op, Math_op, Others;
	set <string>::iterator it;
	void print();
%}

%%

[ \t\n] {}
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {Key.insert(yytext);}

[A-Za-z_][A-Za-z0-9_]* {Iden.insert(yytext);}

[-]?[0-9]*[.]?[0-9]+ {Num.insert(yytext);}

&&|\|\||\!|>|<|==|!=|=<|=> {Logic_op.insert(yytext);}

[-+*/%=]|\+\+|-- {Math_op.insert(yytext);}

. {Others.insert(yytext);}

%%

int main()
{
	FILE *myfile;
	myfile = fopen("C:\\Users\\asus\\Documents\\Compiler_Final\\input.c", "r");
	if(myfile == NULL)
		cout << "Error!" << endl;            
	else 
	{
		yyin = myfile;
		yylex();
		print();
		getchar();
		fclose(myfile);
	}
	return 0;
}

void print()
{
	cout << "Keywords: ";
		for(it = Key.begin(); it != Key.end(); it++)
		{
			if(it != Key.begin())
				cout << ", ";
			cout << *it;
		}
		cout << endl;
		cout << "Identifiers: ";
		for(it = Iden.begin(); it != Iden.end(); it++)
		{
			if(it != Iden.begin())
				cout << ", ";
			cout << *it;
		}
		cout << endl;
		cout << "Numerical Values: ";
		for(it = Num.begin(); it != Num.end(); it++)
		{
			if(it != Num.begin())
				cout << ", ";
			cout << *it;
		}
		cout << endl;
	
		cout << "Logical Operators: ";
		for(it = Logic_op.begin(); it != Logic_op.end(); it++)
		{
			if(it != Logic_op.begin())
				cout << ", ";
			cout << *it;
		}
		cout << endl;
		cout << "Math operators: ";
		for(it = Math_op.begin(); it != Math_op.end(); it++)
		{
			if(it != Math_op.begin())
				cout << ", ";
			cout << *it;
		}
		cout << endl;
		cout << "Others: ";
		for(it = Others.begin(); it != Others.end(); it++)
		{
			cout << *it << ' ';
		}
		cout << endl;
}