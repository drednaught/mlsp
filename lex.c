#include "mlsp.h"
#include <stdbool.h>

bool inStr(sds str, char c) {
	int len = (int)sdslen(str);
	for(int i = 0; i < len; ++i) {
		if(str[i] == c) {
			return true;
		}
	}
	return false;
}

bool isDigit(char c) {
	if(c >= '0' && c <= '9') {
		return true;
	} else {
		return false;
	}
}

bool isLetter(char c) {
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c<='Z')) {
		return true;
	} else {
		return false;
	}
}

bool isSymbol(char c) {
	return false;
}

bool isNumberStr(sds str) {
	int len = (int)sdslen(str);
	if(len < 1) {
		return false;
	} 
	for(int i =0; i<len; ++i) {
		if(!isDigit(str[i] || str[i] != '.')) {
			return false;
		}
	}
	return true;
}

bool isIdentStr(sds str) {
	int len = (int)sdslen(str);
	sds charlist = sdsnew("+-*/");
	if(len < 1) {
		return false;
	}
	for(int i=0;i<len;++i) {
		if(!isDigit(str[i]) || !isLetter(str[i]) || inStr(charlist, str[i])) {
			return false;
		}
	}
	return true;
}
/*
bool isOperatorStr(sds str) {
	if(str >='0' && str <= '9') {
		return true;
	} else {
		return false;
	}
}*/

/** reserved
	"()[]''"":<>="
	typedef enum { false, true } bool;
	*/

void pushToken(sds token) {
	//printf("isNumber: %d\n", isNumberStr(token));
	if(isNumberStr(token)) {
		printf("isNumber\n");
	} else if(isIdentStr(token)) {
		printf("isIdent\n");
	}/* else if(isOperatorStr(token)) {
	
	}*/
	sdsclear(token);
}


void lexer(sds ch) {
	static sds token = NULL;
	if(token == NULL) {
		token = sdsempty();
	}
	int len = (int)sdslen(ch);
	for(int i = 0; i<len; ++i) {
		switch(ch[i]) {
			case '(': 
				//start group
				printf("open\n");
				break;
			case ')': 
				//end group
				printf("close %s\n", token);
				//sdsfree(token);
				//token = sdsempty();
				pushToken(token);
				break;
			case ' ': 
				//next token
				printf("space %s\n", token);
				
				//sdsfree(token);
				//token = sdsempty();
				pushToken(token);	
				break;
			case '\n':
			case '\r':
			case '\t':
				//ignore
				break;
			default: 
				//add to token
				sdscatlen(token, ch + i, 1);
				break;
		}
	}
}

int main(){
	lexer(sdsnew("(+ 12 (+ 2 3.4))"));
	return 0;
}
