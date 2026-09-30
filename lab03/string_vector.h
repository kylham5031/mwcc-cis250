#ifndef __STRING_VECTOR_H__
#define __STRING_VECTOR_H__

#include <stddef.h>

typedef struct {
    char **data;
    size_t capacity;
    size_t size;
}StringVector;

// Function Prototypes
StringVector* vector_create(size_t initial_capacity);
int vector_push(StringVector *vec, const char *str);
const char* vector_get(const StringVector *vec, size_t index);
void vector_free(StringVector *vec);

#endif 
