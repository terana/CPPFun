enum token_value {
	NAME,		NUMBER,		END,
	PLUS='+',	MINUS='-',	MUL='*',	DIV='/',
	PRINT=';',	ASSIGN='=',	LP='(',		RP= ')'
};
extern token_value curr_tok;
extern double number_value;
extern char name_string[256];
extern token_value get_token();