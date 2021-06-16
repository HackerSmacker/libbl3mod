#include <stdio.h>
#include "bl3mod.h"

int main() {
	printf("%s", mod_header("Test mod", "J. Random Modder", "mod", "1.0.0"));
	printf("%s", mod_header_contact("Discord", "HackerSmacker#8496"));
	printf("%s", mod_header_contact("Email", "maint@someunixbox.somesite.net"));
	printf("%s", mod_header_contact("BITNET", "MAINT@KILLER"));
	printf("%s", mod_header_contact("DECnet Internet", "HSVAX2::MIKEY"));
	printf("%s", mod_header_tags("demos, fake mods, asdf, xcvjxcvb"));
	return 0;
}
