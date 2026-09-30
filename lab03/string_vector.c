#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_vector.h"

StringVector* vector_create(size_t initial_capacity)
{
    StringVector *vec = malloc(sizeof(StringVector));     //Allocate the memory

    vec->data = malloc(initial_capacity * sizeof(char *));      // Allocate space for string pointers

    vec->capacity = initial_capacity;     // Set starting capacity and size
    vec->size = 0;

    return vec;
}

int vector_push(StringVector *vec, const char *str)
{
  // If vector is full, double capacity
    if (vec->size == vec->capacity)
    {
        vec->capacity = vec->capacity * 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(char *));

        if (vec->data == NULL)
        {
          return 0;     // Return 0 if failure
        }

    }

  vec->data[vec->size] = malloc(strlen(str) + 1);     // Allocate memory for new string

    if (vec->data[vec->size] == NULL)
    {
      return 0;     // Return 0 if failure
    }


  strcpy(vec->data[vec->size], str);      // Copy the new string into memory

  vec->size++;      // Add one to string and return 1 for success
  return 1;
}

const char* vector_get(const StringVector *vec, size_t index)
{
    if (index >= vec->size)
    { 
      return NULL;      // Return NULL if index is outside the bounds
    }

  return vec->data[index];      // Return string stored in index __
}

void vector_free(StringVector *vec)
{
    for (size_t i = 0; i < vec->size; i++)
      {
        free(vec->data[i]);     // Free each string
      }

    free(vec->data);      // Free the array pointers
  

    free(vec);      // Free StringVector struct itself

}
