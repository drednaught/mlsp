#include "mlsp.h"

#define TABLE_SIZE 255

//#define fn_type(x,y) typedef (x) (*(y))();


struct HashEntry{
	fn_ptr func;
} hashTable[TABLE_SIZE];


uint32_t murmurHash( const void * key, int len, uint32_t seed ) {
	const uint32_t m = 0x5bd1e995;
  const int r = 24;
	uint32_t h = seed ^ len;
  const unsigned char * data = (const unsigned char *)key;
	while(len >= 4) {
		uint32_t k = *(uint32_t*)data;
		k *= m;
		k ^= k >> r;
		k *= m;
		h *= m;
		h ^= k;
		data += 4;
		len -= 4;
	}
	switch(len) {
		case 3: h ^= data[2] << 16;
		case 2: h ^= data[1] << 8;
		case 1: h ^= data[0];
		h *= m;
	}
	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;
	return h;
}

uint32_t hash(char* name) {
	uint32_t key = murmurHash(name, strlen(name), 1);
	return key % TABLE_SIZE;
}

int put(char* name, fn_ptr func) {
	uint32_t key = hash(name);
	hashTable[key].func = func;
	return (int)key;
}

void calls(char *name) {
	uint32_t key = hash(name);
	hashTable[key].func();
}

void call(int key) {
	hashTable[key].func();
}

/*
void test() {
	printf("success!\n");
}


int main() {
	int key;
	key = put("test", &test);
	call(key);
}*/
