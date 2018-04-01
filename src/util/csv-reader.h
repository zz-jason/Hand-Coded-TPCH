#ifndef HCTH_UTIL_CSV_READER_H
#define HCTH_UTIL_CSV_READER_H

#include "memory-manager.h"

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

namespace hctpch {
namespace util {

template<typename T>
void CutOneField(char** input, T* output, MemoryManager* memManager) {
}

template<>
void CutOneField(char** input, int32_t* output, MemoryManager* memManager) {
    char* begin = *input;
    char* end   = *input;

    while (*end != '|') ++end;
    *end = '\0';

    *output = atoi(begin);
    *input  = end + 1;
}

template<>
void CutOneField(char** input, double* output, MemoryManager* memManager) {
    char* begin = *input;
    char* end   = *input;

    while (*end != '|') ++end;
    *end = '\0';

    *output = atof(begin);
    *input  = end + 1;
}

template<>
void CutOneField(char** input, char** output, MemoryManager* memManager) {
    char* begin = *input;
    char* end   = *input;

    while (*end != '|') ++end;
    *end = '\0';

    int size = end - begin;
    *output = reinterpret_cast<char*>(memManager->Allocate(size));
    memcpy(*output, begin, size);
    *input = end + 1;
}

} // end of namespace util
} // end of namespace hctpch

#endif
