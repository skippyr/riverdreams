#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include "lib.c"

void
print_directory_entries()
{
	DIR *directory_stream = opendir(".");
	struct dirent *entry;

	unsigned int hidden_entries_quantity = 0;
	unsigned int symbolic_link_entries_quantity = 0;

	while ((entry = readdir(directory_stream)) != NULL) {
		if (
			!strcmp(entry->d_name, ".") ||
			!strcmp(entry->d_name, "..")
		) { continue; }

		if (entry->d_name[0] == '.') { ++hidden_entries_quantity; }
		if (entry->d_type == 10) { ++symbolic_link_entries_quantity; }
	}

	if (hidden_entries_quantity > 0) {
		printf(
			"%%F{red}%s%%f%u",
			choose_symbol_by_environment(" ", "HIDDEN "),
			hidden_entries_quantity
		);
	}
	if (symbolic_link_entries_quantity > 0) {
		printf(
			"%%F{blue}%s%%f%u\n",
			choose_symbol_by_environment(" ", "SYMLINKS "),
			symbolic_link_entries_quantity
		);
	}

	closedir(directory_stream);
}

int
main(void)
{
	print_directory_entries();

	return 0;
}
