#include "myvector.h"
#include<stdlib.h>

struct vector init(unsigned int n, size_t t){
struct vector Vector;
Vector.size = n;
Vector.id = malloc(n*t);
Vector.last=0;
return Vector;
}

void add_new_element(struct vector * Vector, void **addr)
{
    void *new_id;
	if(Vector->last==Vector->size)
	{
		new_id = realloc(Vector->id, 2*8*Vector->size);
		Vector->size = 2*Vector->size;
		Vector->id=new_id;
	}
	*(Vector->id + Vector->last)=(long)addr;
	Vector->last++;
}

void display_vector(struct vector Vector)
{
	unsigned int i;
	for(i = 0; i < Vector.last; i++)
	{
		printf("%d %p\n",i,*(void **)Vector.id[i]);
	}
	puts("");
}

void display_vector_addr(struct vector Vector)
{
	unsigned int i;
	for(i = 0; i < Vector.last; i++)
	{
		printf("%d %p\n",i,(void *)Vector.id[i]);
	}
	puts("");
}


void new_Vector(struct vector * Vector)
{
	long buf;
	unsigned int N = Vector->last;
	unsigned int ret=0,i;
	for(i = 0; i < N; i++)
	{
		while((*(void **)Vector->id[i]) ==NULL)
		{
			buf = Vector->id[i];
			Vector->id[i]=Vector->id[N-1];
			Vector->id[N-1]=buf;
			N--;
			if(i==N)
			{
				ret=1;
				break;
			}
		}
		if(ret==1)
			break;
	}
	Vector->last=N;
}