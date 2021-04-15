#include <stdio.h>
#include "bl3mod.h"
#include "bl3modtype.h"

int main() {
       printf("libbl3mod demo 4 - coordinate generator\n");
       char* result = mesh_coord(
		       "1000",
		       "420",
		       "651",
		       "6.5",
		       "9.1",
		       "2.6",
		       "1.0",
		       "1.2",
		       "1.0"
		       );
       printf(result);
       return 0;
}

