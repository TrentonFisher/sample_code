%{

#include <stdio.h>

int yylval;  // Declare yylval
int installID();
int installNum();
extern FILE* yyin;  // Declare yyin for file input

%}

%%

[ \t\n]   /* no action and no return */
if        {printf("IF\n"); return 256; } // IF
then      {printf("THEN\n"); return 257; } // THEN
else      {printf("ELSE\n"); return 258; } // ELSE
[a-zA-Z][a-zA-Z0-9]* {yylval = installID(); printf("ID: %s\n", yytext); return 259;} // ID
[0-9]+(\.[0-9]+)?(E[+]?[0-9]+)? {yylval = installNum(); printf("NUMBER: %s\n", yytext); return 260;} // NUMBER
"<="      {printf("LE\n"); return 261; } // LE
"<>"      {printf("NE\n"); return 262; } // NE
">="      {printf("GE\n"); return 263; } // GE
"=="      {printf("EQ\n"); return 264; } // EQ
">"       {printf("GT\n"); return 265; } // GT
"<"       {printf("LT\n"); return 266; } // LT
.         {printf("OTHER: %s\n", yytext);} /* ignore any other characters */

%%



int main() {

    /* reading test case file */

    printf("Lexer starting...\n");

    yyin = fopen("test_cases.txt", "r");  // Open the input file

    if (!yyin) {

        fprintf(stderr, "Error opening input file\n");
        return 1;
    }

    while (yylex()) {}

    fclose(yyin);  // Close the input file

    printf("Lexer finished.\n");

    return 0;
}

int installID() {

    printf("Installed ID: %s\n", yytext);

    return 259; // ID
}

int installNum() {

    printf("Installed Number: %s\n", yytext);

    return 260; // NUMBER
}

