%option noyywrap
%{
	#include<bits/stdc++.h>
	using namespace std;
	set <string> Key, Iden, Int_num, Float_num, Logic_op, Arith_op, Rel_op, Others;
	set <string>::iterator it;
%}

%%

[ \t\n] {}
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {Key.insert(yytext);}

[A-Za-z_][A-Za-z0-9_]* {Iden.insert(yytext);}

[-]?[0-9]*[.][0-9]+ {Float_num.insert(yytext);}

[-]?[0-9]+ {Int_num.insert(yytext);}

&&|(\|\|)|\! {Logic_op.insert(yytext);}

[-+*/%]|(\+\+)|-- {Arith_op.insert(yytext);}

>|<|==|!=|=<|=> {Rel_op.insert(yytext);}
. {Others.insert(yytext);}

%%
int main()
{
	FILE *myfile;
	myfile = fopen("C:\\Users\\asus\\Downloads\\A....Z\\Compiler_Lab\\Lab_6\\input.txt", "r");
	if(myfile == NULL)
		cout << "Error!" << endl;            
	else 
	{
		yyin = myfile;
		yylex();
		cout << "Keywords: ";
		for(it = Key.begin(); it != Key.end(); it++)
		{
			if(it != Key.begin())
				cout << ", ";
			cout << '\"' << *it << '\"';
		}
		cout << endl;
		cout << "Identifiers: ";
		for(it = Iden.begin(); it != Iden.end(); it++)
		{
			if(it != Iden.begin())
				cout << ", ";
			cout << '\"' << *it << '\"';
		}
		cout << endl;
		cout << "Floating point numbers: ";
		for(it = Float_num.begin(); it != Float_num.end(); it++)
		{
			if(it != Float_num.begin())
				cout << ", ";
			cout << '\"' << *it << '\"';
		}
		cout << endl;
		cout << "Integer numbers: ";
		for(it = Int_num.begin(); it != Int_num.end(); it++)
		{
			if(it != Int_num.begin())
				cout << ", ";
			cout << '\"' << *it << '\"';
		}
		cout << endl;
		cout << "Logical Operators: ";
		for(it = Logic_op.begin(); it != Logic_op.end(); it++)
		{
			if(it != Logic_op.begin())
				cout << ", ";
			cout << '\"' << *it << '\"';
		}
		cout << endl;
		cout << "Arithmetic operators: ";
		for(it = Arith_op.begin(); it != Arith_op.end(); it++)
		{
			if(it != Arith_op.begin())
				cout << ", ";
			cout << '\"' << *it << '\"';
		}
		cout << endl;
		cout << "Relational operators: ";
		for(it = Rel_op.begin(); it != Rel_op.end(); it++)
		{
			if(it != Rel_op.begin())
				cout << ", ";
			cout << '\"' << *it << '\"';
		}
		cout << endl;
		cout << "Others: ";
		for(it = Others.begin(); it != Others.end(); it++)
		{
			if(it != Others.begin())
				cout << ", ";
			cout << '\"' << *it << '\"';
		}
		cout << endl;
		getchar();
		fclose(myfile);
	}
	return 0;
}
