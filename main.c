#include "mlsp.h"
/*
static char* read() {
	char* expr = malloc(256);
	fgets(expr, 256, stdin);
	return expr;
}*/

void compute_add() {
	printf("add\n");
}
void compute_mult() {
	printf("mult\n");
}
void compute_div() {
	printf("div\n");
}

void putHash() {
	put("+", &compute_add);
	put("*", &compute_mult);
	put("/", &compute_div);
}

void callHash() {
	calls("+");
	calls("*");
	calls("/");
}

void eval(sds strData) {
	int len = (int)sdslen(strData);
	for(int i = 0; i<len; ++i) {
		printf("%c\n", strData[i]);
	}
	//printf("string: %s len: %i\n", strData, (int)sdslen(strData));
	sdsfree(strData);
}

int main(int argc, char* argv[]) {
	if(argc > 1) {
		printf("Not yet supported.\n");
	} else {
		char *buffer;
		putHash();
		callHash();
		while(1) {
			buffer = readline("> ");
			eval(sdsnew(buffer));
			free(buffer);
		}
	}
	return 0;
}
