#include <stdio.h>
#include <bl3mod.h>

int main() {
	char* object;
	char* output;
	char* output_c;
	object = "/Game/Path/To/Some/ThisIsATest";
	output = end_object(object);
	output_c = c_end_object(object);
	printf("%s: %s and %s\n", object, output, output_c);
	return 0;
}
