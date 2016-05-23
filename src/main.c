#include <stdio.h>
#include "mem.h"  

int main()
{
	int *b,*c, *e;
	FILE* output_file, * output_file2;
	const char* path = "data";
	const char* path2 = "data2";
	struct vector Vector=init(5,8);

	if ((output_file = fopen(path, "wb")) == NULL)
    {
	   puts("Wrong_path");
	   return 0;
    }
	if ((output_file2 = fopen(path2, "wb")) == NULL)
    {
	   puts("Wrong_path");
	   return 0;
    }
	(struct mem_t *)heap_init();
	b = (int *)_malloc(80);
	b[0]=1;
	b[1]=2;
	b[3]=3;
	add_new_element(&Vector,(void*)&b);
	c = (int *)_malloc(80);
	c[0]=4;
	c[1]=3;
	c[3]=1;
	add_new_element(&Vector,(void*)&c);
	e = (int *)_malloc(20);
	e[0]=4;
	e[1]=3;
	e[3]=1;
	add_new_element(&Vector,(void*)&e);


	_free((void*)&c);
    memalloc_debug_heap(output_file, (struct mem_t *)0x04040000);
	puts("Before collection");
	puts("Number of elements address in memory/(nil)");
	display_vector(Vector);
	new_Vector(&Vector);
	garbage_collect(&Vector, ((void*)0x04241000));
	puts("After collection");
	display_vector(Vector);
	memalloc_debug_heap(output_file2, (struct mem_t *)heap_begin());
	fclose(output_file);
	fclose(output_file2);
	return 0;
}

