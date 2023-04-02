#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include "lib.c"

static void
print_directory_entries(void)
{
	DIR *directory_stream = opendir(".");
	struct dirent *entry;

	unsigned short int hidden_entries_quantity = 0;
	unsigned short int executable_entries_quantity = 0;
	unsigned short int symbolic_link_entries_quantity = 0;

	while ((entry = readdir(directory_stream)) != NULL) {
		if (
			!strcmp(entry->d_name, ".") ||
			!strcmp(entry->d_name, "..")
		) { continue; }

		struct stat entry_status;
		stat(entry->d_name, &entry_status);

		if (entry_status.st_mode == 33261) { ++executable_entries_quantity; }
		if (entry->d_name[0] == '.') { ++hidden_entries_quantity; }
		if (entry->d_type == 10) { ++symbolic_link_entries_quantity; }
	}

	if (hidden_entries_quantity > 0) {
		printf(
			" %%F{red}%s%%f%u",
			choose_symbol_by_environment(" ", "HIDDEN "),
			hidden_entries_quantity
		);
	}
	if (executable_entries_quantity > 0) {
		printf(
			" %%F{green}%s%%f%u",
			choose_symbol_by_environment(" ", "EXECUTABLE "),
			executable_entries_quantity
		);
	}
	if (symbolic_link_entries_quantity > 0) {
		printf(
			" %%F{blue}%s%%f%u\n",
			choose_symbol_by_environment(" ", "SYMLINK "),
			symbolic_link_entries_quantity
		);
	}

	closedir(directory_stream);
}

static void
print_jobs(void)
{
	printf(
		" %%(1j.%%F{green}%s%%f%%j.)",
		choose_symbol_by_environment(" ", "JOBS ")
	);
}

int
main(void)
{
	print_jobs();
	print_directory_entries();

	return 0;
}

