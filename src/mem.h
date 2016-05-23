#ifndef _MEM_H_
#define _MEM_H_


#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/mman.h>


#include "myvector.h"


#define DEBUG_FIRST_BYTES 10
struct mem_t;

#pragma pack(push, 1)
struct mem_t {
struct mem_t* next;
size_t capacity;
int is_free;
};
#pragma pack(pop)

#define SIZE_HEAD ((size_t)(sizeof(struct mem_t)))
#define SIZE_FREE (2*SIZE_HEAD)
#define PAGE_LEN  100
#define PAGE_LEN_SYS  0x8000
void* _malloc( size_t query );
void _free( void** mem );
void* heap_init(  );
void memalloc_debug_struct_info( FILE* f, struct mem_t * ptr );
void memalloc_debug_heap( FILE* f, struct mem_t * ptr );
void garbage_collect(struct vector * Vector, void * Heap_start);
void *heap_begin();
#endif 