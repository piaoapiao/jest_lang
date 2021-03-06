/*
	Jest Language

	Toy language that compiles to C.

	by David G. Maziero
	06/03/2016
*/

typedef unsigned char bool8;
typedef unsigned char byte;
typedef unsigned short word;

enum TokenType
{
	TK_UNKNOWN,
	TK_IDENTIFIER,
	TK_EQUALS,
	TK_PLUS,
	TK_MINUS,
	TK_STAR,
	TK_SLASH,
	TK_COLON,
	TK_SEMI_COLON,
	TK_COMMA,
	TK_OPEN_PAREN,
	TK_CLOSE_PAREN,
	TK_OPEN_BRACE,
	TK_CLOSE_BRACE,
	TK_OPEN_BRACKET,
	TK_CLOSE_BRACKET,
	TK_EXCLAMATION,
	TK_STRING,
	TK_NUMERIC_INTEGER,
	TK_NUMERIC_FLOATING,
	TK_KEYWORD,
	TK_BASIC_TYPE,
	TK_END_OF_STREAM
};

static char *Token_Type_Names[TK_END_OF_STREAM] = {
	"",
	"identifier",
	"=",
	"+",
	"-",
	"*",
	"/",
	":",
	";",
	",",
	"(",
	")",
	"{",
	"}",
	"[",
	"]",
	"!",
	"string",
	"integral",
	"floating",
	"keyword",
	"basic type"
};

static char *Token_Type_Desc[TK_END_OF_STREAM] = {
	"unknown",
	"identifier",
	"equal sign",
	"plus sign",
	"minus sign",
	"asterisk",
	"slash",
	"colon",
	"semi-colon",
	"comma",
	"open paren",
	"close paren",
	"open brace",
	"close brace",
	"open bracket",
	"close bracket",
	"exclamation",
	"string",
	"integral number",
	"floating number",
	"keyword",
	"basic type"
};

#define BASIC_TYPE_COUNT 11
static char *BasicTypes[BASIC_TYPE_COUNT] = {
	"void", "s8",  "u8", "s16", "u16", "s32", "u32", "s64", "u64", "f32", "f64",
};

#define KEYWORD_COUNT 11
static char *Keywords[KEYWORD_COUNT] = {
	"import", "alias", "struct", "while", "for", "return", "if", "use", "defer", "true", "false"
};

typedef struct Tokenizer
{
	int line, col;
	char *pos;
	char *file_name;
	//TODO: should I pass a length here?
	//int length;
} Tokenizer;

typedef struct Token
{
	int length;
	char *text;
	int line, col;
	byte type;	
	union
	{
		long long numeric_integer;
		long double numeric_floating;
	};
} Token;

typedef enum NumericType
{
	NT_DECIMAL,
	NT_BINARY,
	NT_HEXADECIMAL,
	NT_OCTAL
} NumericType;

//EOF
