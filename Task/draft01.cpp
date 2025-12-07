#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 100

// 定义Token类型
typedef enum {
	// 保留字
	KW_CONST, KW_VAR, KW_PROCEDURE, KW_BEGIN, KW_END, KW_ODD, KW_IF, KW_THEN, KW_CALL, KW_WHILE, KW_DO, KW_READ, KW_WRITE,
	// 运算符
	OP_PLUS, OP_MINUS, OP_MUL, OP_DIV, OP_EQUAL, OP_NOT_EQUAL, OP_LESS, OP_LESS_EQ, OP_GREATER, OP_GREATER_EQ, OP_ASSIGN,
	// 界符
	DELIM_LPAREN, DELIM_RPAREN, DELIM_COMMA, DELIM_SEMICOLON, DELIM_PERIOD,
	// 其他
	IDENT, NUMBER, ILLEGAL,
	END_OF_INPUT
} TokenType;

// 保留字表
typedef struct {
	char *word;
	TokenType token;
} ReservedWord;

ReservedWord reserved_words[] = {
	{"const", KW_CONST},
	{"var", KW_VAR},
	{"procedure", KW_PROCEDURE},
	{"begin", KW_BEGIN},
	{"end", KW_END},
	{"odd", KW_ODD},
	{"if", KW_IF},
	{"then", KW_THEN},
	{"call", KW_CALL},
	{"while", KW_WHILE},
	{"do", KW_DO},
	{"read", KW_READ},
	{"write", KW_WRITE}
};

#define NUM_RESERVED (sizeof(reserved_words)/sizeof(reserved_words[0]))

// 全局变量
TokenType sym;
char id[MAX_ID_LEN];
int num;
char illegal_char;

int current_char;

// 获取下一个Token
void get_next_token() {
	// 跳过空白字符
	while (isspace(current_char)) {
		current_char = getchar();
	}
	
	if (current_char == EOF) {
		sym = END_OF_INPUT;
		return;
	}
	
	if (isalpha(current_char)) {
		// 处理标识符或保留字
		int i = 0;
		id[i++] = current_char;
		current_char = getchar();
		while (isalnum(current_char)) {
			if (i < MAX_ID_LEN - 1) {
				id[i++] = current_char;
			}
			current_char = getchar();
		}
		id[i] = '\0';
		
		sym = IDENT;
		for (int j = 0; j < NUM_RESERVED; j++) {
			if (strcmp(id, reserved_words[j].word) == 0) {
				sym = reserved_words[j].token;
				break;
			}
		}
		// 回退非字母数字字符
		ungetc(current_char, stdin);
		current_char = ' ';
	} else if (isdigit(current_char)) {
		// 处理数字
		num = 0;
		while (isdigit(current_char)) {
			num = num * 10 + (current_char - '0');
			current_char = getchar();
		}
		sym = NUMBER;
		ungetc(current_char, stdin);
		current_char = ' ';
	} else {
		// 处理符号
		switch (current_char) {
			case '+': sym = OP_PLUS; current_char = getchar(); break;
			case '-': sym = OP_MINUS; current_char = getchar(); break;
			case '*': sym = OP_MUL; current_char = getchar(); break;
			case '/': sym = OP_DIV; current_char = getchar(); break;
			case '=': sym = OP_EQUAL; current_char = getchar(); break;
			case '#': sym = OP_NOT_EQUAL; current_char = getchar(); break;
			case '<': {
				current_char = getchar();
				if (current_char == '=') {
					sym = OP_LESS_EQ;
					current_char = getchar();
				} else {
					sym = OP_LESS;
				}
				break;
			}
			case '>': {
				current_char = getchar();
				if (current_char == '=') {
					sym = OP_GREATER_EQ;
					current_char = getchar();
				} else {
					sym = OP_GREATER;
				}
				break;
			}
			case ':': {
				current_char = getchar();
				if (current_char == '=') {
					sym = OP_ASSIGN;
					current_char = getchar();
				} else {
					sym = ILLEGAL;
					illegal_char = ':';
				}
				break;
			}
			case '(': sym = DELIM_LPAREN; current_char = getchar(); break;
			case ')': sym = DELIM_RPAREN; current_char = getchar(); break;
			case ',': sym = DELIM_COMMA; current_char = getchar(); break;
			case ';': sym = DELIM_SEMICOLON; current_char = getchar(); break;
			case '.': sym = DELIM_PERIOD; current_char = getchar(); break;
		default:
			illegal_char = current_char;
			sym = ILLEGAL;
			current_char = getchar();
			break;
		}
	}
}

// 获取Token名称
const char* get_token_name(TokenType t) {
	switch (t) {
		case KW_CONST: return "const";
		case KW_VAR: return "var";
		case KW_PROCEDURE: return "procedure";
		case KW_BEGIN: return "begin";
		case KW_END: return "end";
		case KW_ODD: return "odd";
		case KW_IF: return "if";
		case KW_THEN: return "then";
		case KW_CALL: return "call";
		case KW_WHILE: return "while";
		case KW_DO: return "do";
		case KW_READ: return "read";
		case KW_WRITE: return "write";
		case OP_PLUS: return "+";
		case OP_MINUS: return "-";
		case OP_MUL: return "*";
		case OP_DIV: return "/";
		case OP_EQUAL: return "=";
		case OP_NOT_EQUAL: return "#";
		case OP_LESS: return "<";
		case OP_LESS_EQ: return "<=";
		case OP_GREATER: return ">";
		case OP_GREATER_EQ: return ">=";
		case OP_ASSIGN: return ":=";
		case DELIM_LPAREN: return "(";
		case DELIM_RPAREN: return ")";
		case DELIM_COMMA: return ",";
		case DELIM_SEMICOLON: return ";";
		case DELIM_PERIOD: return ".";
		default: return "unknown";
	}
}

int main() {
	int token_count = 0;
	current_char = getchar();
	
	while (1) {
		get_next_token();
		
		if (sym == END_OF_INPUT) break;
		
		token_count++;
		printf("%d\t", token_count);
		
		switch (sym) {
		case KW_CONST:
		case KW_VAR:
		case KW_PROCEDURE:
		case KW_BEGIN:
		case KW_END:
		case KW_ODD:
		case KW_IF:
		case KW_THEN:
		case KW_CALL:
		case KW_WHILE:
		case KW_DO:
		case KW_READ:
		case KW_WRITE:
			printf("基本字\t%s\n", get_token_name(sym));
			break;
		case IDENT:
			printf("标识符\t%s\n", id);
			break;
		case NUMBER:
			printf("数字\t%d\n", num);
			break;
		case OP_PLUS:
		case OP_MINUS:
		case OP_MUL:
		case OP_DIV:
		case OP_EQUAL:
		case OP_NOT_EQUAL:
		case OP_LESS:
		case OP_LESS_EQ:
		case OP_GREATER:
		case OP_GREATER_EQ:
		case OP_ASSIGN:
			printf("运算符\t%s\n", get_token_name(sym));
			break;
		case DELIM_LPAREN:
		case DELIM_RPAREN:
		case DELIM_COMMA:
		case DELIM_SEMICOLON:
		case DELIM_PERIOD:
			printf("界符\t%s\n", get_token_name(sym));
			break;
		case ILLEGAL:
			printf("非法\t%c\n", illegal_char);
			break;
		default:
			printf("未知符号\n");
			break;
		}
	}
	
	return 0;
}
