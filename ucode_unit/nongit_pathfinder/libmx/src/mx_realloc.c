#include "../inc/libmx.h"
// #ifdef DEBUG
// #endif


void *mx_realloc(void *ptr, size_t size)
{
   size_t originalLength = malloc_size(ptr);
   if (size == 0)
   {
      free(ptr);
      return NULL;
   }
   else if (!ptr)
   {
      return malloc(size);
   }
   else if (size <= originalLength)
   {
      return ptr;
   }
   else
   {
      void *ptrNew = malloc(size);
      if (ptrNew)
      {
          mx_memcpy(ptrNew, ptr, originalLength);
          free(ptr);
      }
      return ptrNew;
    }
}

