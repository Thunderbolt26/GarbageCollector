#include<stdio.h>
#include<malloc.h>

struct vector{
	long *id;
	unsigned int size;
	unsigned int last;
};


struct vector init(unsigned int n, size_t t);
void add_new_element(struct vector * Vector, void **addr);
void display_vector(struct vector Vector); 
void new_Vector(struct vector * Vector);
void display_vector_addr(struct vector Vector);