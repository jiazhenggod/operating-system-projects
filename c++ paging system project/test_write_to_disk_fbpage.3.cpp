#include <iostream>
#include <cstring>
#include <unistd.h>
#include "vm_app.h"

using namespace std;

int main()
{
    /* Allocate swap-backed page from the arena */
    char *filename = (char *) vm_map(nullptr, 0);
    //char *filename2 = (char *) vm_map(nullptr, 0);

    strcpy(filename, "data1.bin");

    char *p = (char *) vm_map(filename, 0);

    p[0] = '\?';

    if (!fork()){ // child
        char *d1 = (char *) vm_map(nullptr, 0);
        d1[0] = '1';
        char *d2 = (char *) vm_map(nullptr, 0);
        d2[0] = '1';

        // evict and write data1.bin to disk
    }

    return 0;
}

