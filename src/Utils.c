#include <stdlib.h>
#include "../includes/Utils.h"

int stringToPositiveInteger(char* string, int* integer) {
    // TODO: implement strtol
    *integer = atoi(string);
    if(*integer < 1)
        return 0;
    return 1;
}