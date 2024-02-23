#define _GNU_SOURCE
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

#define WRITE_ENTRY_TYPE(symbol_a, color_a, value_a) \
    if (value_a) { \
        printf(" %%F{%s}%s%%f%ld", color_a, symbol_a, value_a); \
    }

struct entry_types
{
    size_t regulars;
    size_t directories;
    size_t blocks;
    size_t characters;
    size_t sockets;
    size_t fifos;
    size_t symlinks;
};

struct linux_dirent64
{
    ino64_t d_ino;
    off64_t d_off;
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[];
};

static void count_entry_types(struct entry_types *types);
static void write_entry_types(void);
static void write_jobs(void);

static void count_entry_types(struct entry_types *types)
{
    char buffer[1024];
    int directory = open(".", O_RDONLY);
    long total_of_entries;
    long index;
    struct linux_dirent64 *entry;
    if (directory < 0)
        return;
    while ((total_of_entries =
                syscall(SYS_getdents64, directory, buffer, sizeof(buffer))) > 0) {
        for (index = 0; index < total_of_entries; index += entry->d_reclen) {
            entry = (struct linux_dirent64 *)(buffer + index);
            if (*entry->d_name == '.' &&
                (!entry->d_name[1] || (entry->d_name[1] == '.' && !entry->d_name[2])))
                continue;
            if (entry->d_type == DT_REG)
                types->regulars++;
            else if (entry->d_type == DT_DIR)
                types->directories++;
            else if (entry->d_type == DT_BLK)
                types->blocks++;
            else if (entry->d_type == DT_CHR)
                types->characters++;
            else if (entry->d_type == DT_SOCK)
                types->sockets++;
            else if (entry->d_type == DT_FIFO)
                types->fifos++;
            else if (entry->d_type == DT_LNK)
                types->symlinks++;
        }
    }
    close(directory);
}

static void write_entry_types(void)
{
    struct entry_types types = {0, 0, 0, 0, 0, 0, 0};
    count_entry_types(&types);
    WRITE_ENTRY_TYPE(" ", "blue", types.regulars);
    WRITE_ENTRY_TYPE(" ", "yellow", types.directories);
    WRITE_ENTRY_TYPE("󰇖 ", "magenta", types.blocks);
    WRITE_ENTRY_TYPE("󱣴 ", "green", types.characters);
    WRITE_ENTRY_TYPE("󱄙 ", "cyan", types.sockets);
    WRITE_ENTRY_TYPE("󰟦 ", "blue", types.fifos);
    WRITE_ENTRY_TYPE("󰌷 ", "blue", types.symlinks);
}

static void write_jobs(void)
{
    printf("%%(1j. %%F{magenta} %%f%%j.)");
}

int main(void)
{
    write_entry_types();
    write_jobs();
    printf("\n");
    return (0);
}