#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "sds.h"

//readline c
char* rl_gets(void);

//hash.c
#define fn_type(x,y) typedef x (*y)();
//typedef int (*fn_ptr)();
fn_type(int, fn_ptr)
void calls(char* name);
int put(char* name, fn_ptr func);

//list.c
typedef struct node  {
	int data;
	struct node* next;
} node;

typedef void (*callback)(node* data);

//object.?
typedef struct ml_object {
	int32_t type;
	int32_t len;
	void *data;
}ml_object;


