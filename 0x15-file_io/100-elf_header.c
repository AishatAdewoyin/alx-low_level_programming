#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <elf.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry);

int main(int argc, char **argv)
{
    int fd;
    unsigned char *map_start;
    struct stat st;
    Elf64_Ehdr *elf_header;

    if (argc != 2)
    {
        printf("Usage: %s <ELF File>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    if (fstat(fd, &st) == -1)
    {
        perror("fstat");
        exit(1);
    }

    map_start = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map_start == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    elf_header = (Elf64_Ehdr *)map_start;
    check_elf(elf_header->e_ident);
    print_magic(elf_header->e_ident);
    print_class(elf_header->e_ident);
    print_data(elf_header->e_ident);
    print_version(elf_header->e_ident);
    print_abi(elf_header->e_ident);
    print_osabi(elf_header->e_ident);
    print_type(elf_header->e_type, elf_header->e_ident);
    print_entry(elf_header->e_entry);

    if (munmap(map_start, st.st_size) == -1)
    {
        perror("munmap");
        exit(1);
    }

    if (close(fd) == -1)
    {
        perror("close");
        exit(1);
    }

    return 0;
}

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
    if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
        e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(98);
    }

/**

close_elf - Closes an ELF file.
@elf: The ELF file descriptor.
*/
void close_elf(int elf)
{
if (close(elf) == -1)
{
perror("Error: Cannot close file");
exit(EXIT_FAILURE);
}
}
/*
main - Displays the ELF header of an ELF file.
@argc: The number of arguments supplied to the program.
@argv: An array of pointers to the arguments.
Return: If an error occurs - EXIT_FAILURE.
Otherwise - EXIT_SUCCESS.
*/
  int main(int argc, char argv[])
{
int elf, ret_read;
Elf64_Ehdr elf_header;
unsigned char e_ident[EI_NIDENT];
if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
exit(EXIT_FAILURE);
}
elf = open(argv[1], O_RDONLY);
if (elf == -1)
{
perror("Error: Cannot open file");
exit(EXIT_FAILURE);
}
ret_read = read(elf, &elf_header, sizeof(elf_header));
if (ret_read == -1)
{
perror("Error: Cannot read file");
close_elf(elf);
exit(EXIT_FAILURE);
}
if (ret_read != sizeof(elf_header))
{
dprintf(STDERR_FILENO, "Error: Invalid ELF header size\n");
close_elf(elf);
exit(EXIT_FAILURE);
}
/ Copy e_ident into a separate buffer */
for (int i = 0; i < EI_NIDENT; i++)
e_ident[i] = elf_header.e_ident[i];
check_elf(e_ident);
printf("ELF Header:\n");
print_magic(e_ident);
print_class(e_ident);
print_data(e_ident);
print_version(e_ident);
print_osabi(e_ident);
print_abi(e_ident);
print_type(elf_header.e_type, e_ident);
print_entry(elf_header.e_entry, e_ident);
close_elf(elf);
return (EXIT_SUCCESS);
}
  
  
  
