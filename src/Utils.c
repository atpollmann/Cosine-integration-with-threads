#include <stdlib.h>
#include "../includes/Utils.h"

int stringToPositiveInteger(char* string, int* integer) {
    char *end;
    int i = (int)strtol(string, &end, 10);

    if(i) {
    	*integer = i;
    	return 1;
    }
    return 0;
}