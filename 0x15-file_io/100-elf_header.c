#include "main.h"


void check_elf(const unsigned char *e_ident);
void print_magic(const unsigned char *e_ident);
void print_class(const unsigned char *e_ident);
void print_data(const unsigned char *e_ident);
void print_version(const unsigned char *e_ident);
void print_abi(const unsigned char *e_ident);
void print_osabi(const unsigned char *e_ident);
void print_type(unsigned int e_type, const unsigned char *e_ident);
void print_entry(unsigned long int e_entry, const unsigned char *e_ident);
void close_elf(int elf);

/*
* check_elf: Checks whether the given file contains an ELF
* header by verifying its magic number.
* If it is not an ELF file, the function prints
* an error message to stderr and exits with code 98.
* @param e_ident - a pointer to an array containing
* the contents of the ELF header
*/
void check_elf(const unsigned char *e_ident)
{
for (int i = 0; i <= 3; i++)
{
switch (e_ident[i])
{
case 127:
case 'E':
case 'L':
case 'F':
continue;
default:
fprintf(stderr, "Error: Not an ELF file\n");
exit(98);
}
}
}

/*
* print_magic - Prints the magic numbers of
* an ELF header.
* @e_ident: A pointer to an array holding the
* ELF magic numbers.
*
* Description: Magic digits are separated by spaces.
*/
void print_magic(unsigned char *e_ident)
{
printf("Magic: ");
for (int i = 0; i < EI_NIDENT; i++)
{
printf("%02x%s", e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
}
}

/*
* print_class - prints the ELF class
* @e_ident: a pointer to an array holding the
* ELF identification bytes
*
* Description: The EI_CLASS byte of the ELF
* identification bytes specifies the ELF class.
*/
void print_class(unsigned char *e_ident)
{
printf(" Class: ");

if (e_ident[EI_CLASS] == ELFCLASSNONE)
{
printf("none\n");
}
else if (e_ident[EI_CLASS] == ELFCLASS32)
{
printf("ELF32\n");
}
else if (e_ident[EI_CLASS] == ELFCLASS64)
{
printf("ELF64\n");
}
else
{
printf("<unknown: 0x%x>\n", e_ident[EI_CLASS]);
}
}

/*
* print_data - prints the ELF data encoding
* @e_ident: returns the ELF identification bytes
* The EI_DATA byte of the ELF identification bytes,
* which is what this function outputs,
* specifies the ELF data encoding.
*/
void print_data(unsigned char *e_ident)
{
printf("Data: ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: 0x%x>\n", e_ident[EI_DATA]);
break;
}
}

/*
* print_version - Prints the version of an ELF header.
* @e_ident: A pointer to an array containing
* the ELF version.
*/
void print_version(unsigned char *e_ident)
{
printf("Version:%d", e_ident[EI_VERSION]);

switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
case EV_NONE:
printf(" invalid version number\n");
break;
default:
printf("\n");
break;
}
}

/*
* print_osabi - Prints the OS/ABI of an ELF header.
* @e_ident: A pointer to an array containing
* the ELF version.
*/
void print_osabi(unsigned char *e_ident)
{
const char *osabi_names[] = {
"UNIX - System V",
"UNIX - HP-UX",
"UNIX - NetBSD",
"UNIX - Linux",
"UNIX - Solaris",
"UNIX - IRIX",
"UNIX - FreeBSD",
"UNIX - TRU64",
"ARM",
"Standalone App"
};
int osabi_index = e_ident[EI_OSABI];
const char *osabi_name = osabi_index >= 0 && osabi_index < 10 ?
osabi_names[osabi_index] : "<unknown>";
printf("  OS/ABI: %s\n", osabi_name);
}

/*
* print_abi - Prints the ABI version of an ELF header.
* @e_ident: A pointer to an array containing
* the ELF ABI version.
*/
void print_abi(unsigned char *e_ident)
{
printf("  ABI Version: %d\n",
(int)e_ident[EI_ABIVERSION]);
}

/*
* print_type - Prints the type of an ELF header.
* @e_type: The ELF type.
* @e_ident: A pointer to an array containing
* the ELF class.
*/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
int is_big_endian = (e_ident[EI_DATA] == ELFDATA2MSB);
if (is_big_endian)
{
e_type = (e_type >> 8) & 0xFF;
}

const char *type_names[] = {
"NONE (None)",
"REL (Relocatable file)",
"EXEC (Executable file)",
"DYN (Shared object file)",
"CORE (Core file)"
};

const char *type_name = "<unknown>";
if (e_type >= ET_NONE && e_type <= ET_CORE)
{
type_name = type_names[e_type];
}
printf("  Type: %s\n", type_name);
}

/*
* print_entry - Prints the entry point address
* of an ELF header.
* @e_entry: The entry point address.
* @e_ident: A pointer to an array containing
* the ELF class.
*/

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf("  Entry point address:%#lx\n",
(e_ident[EI_CLASS] == ELFCLASS32) ? (unsigned int)e_entry : e_entry);
}

/*
* close_elf - Closes an ELF file descriptor.
* @fd: The file descriptor of the ELF file to close.
* Description: If the file cannot be closed, prints
* an error message and exits with code 98.
*/
void close_elf(int fd)
{
if (close(fd) == -1)
{
fprintf(stderr, "Error: Failed to close file descriptor %d\n", fd);
exit(98);
}
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

#define USAGE "Usage: %s <file>\n"

/* fail: Print an error message and exit with failure */
void fail(char *msg)
{
perror(msg);
exit(EXIT_FAILURE);
}

/* open_elf: Open the ELF file and return the file descriptor */
int open_elf(char *filename)
{
int fd = open(filename, O_RDONLY);
if (fd == -1)
fail("open");
return (fd);
}

/* read_elf: Read the ELF header from the file */
void read_elf_header(int fd, Elf64_Ehdr *header)
{
if (read(fd, header, sizeof(*header)) != sizeof(*header))
fail("read");
}

/* check_elf_header: Check if the file is a valid ELF file */
void check_elf_header(Elf64_Ehdr *header)
{
if (header->e_ident[EI_MAG0] != ELFMAG0 ||
header->e_ident[EI_MAG1] != ELFMAG1 ||
header->e_ident[EI_MAG2] != ELFMAG2 ||
header->e_ident[EI_MAG3] != ELFMAG3)
{
fprintf(stderr, "Error: %s is not an ELF file\n", program_invocation_name);
exit(EXIT_FAILURE);
}
}

/* print_magic_number: Print the magic number of the ELF header */
void print_magic_number(unsigned char *ident)
{
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
printf("%02x ", ident[i]);
printf("\n");
}

/* print_clas: Print the class of the ELF header */
void print_class(unsigned char *ident)
{
printf("Class: ");
switch (ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", ident[EI_CLASS]);
}
}

/* print_data: Print the data encoding of the ELF header */
void print_data(unsigned char *ident)
{
printf("Data: ");
switch (ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", ident[EI_DATA]);
}
}

/* print_version: Print the version of the ELF header */
void print_version(unsigned char *ident)
{
printf("Version: ");
switch (ident[EI_VERSION])
{
case EV_NONE:
printf("none\n");
break;
case EV_CURRENT:
printf("1 (current)\n");
break;
default:
printf("<unknown: %d>\n", ident[EI_VERSION]);
}
}

/*
* print_osabi: Print the operating system and
* ABI of the ELF header
*/
void print_osabi(unsigned char *ident)
{
printf("  OS/ABI: ");

switch (ident[EI_OSABI])
{
case ELFOSABI_SYSV:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", ident[EI_OSABI]);
}
}

/*
* print_flags - Prints the flags of an ELF header.
* @e_flags: The ELF flags.
* @e_ident: A pointer to an array
* containing the ELF class.
*/

void print_flags(unsigned int e_flags, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
e_flags >>= 24;
printf(" Flags:");
if (e_flags & EF_MIPS_ARCH_ASE_MDMX)
printf(" mdmx");
if (e_flags & EF_MIPS_ARCH_ASE_MIPS3D)
printf(" mips3d");
if (e_flags & EF_MIPS_ARCH_ASE_MT)
printf(" mt");
if (e_flags & EF_MIPS_ARCH_ASE_MIPS16)
printf(" mips16");
if (e_flags & EF_MIPS_ARCH_ASE_MICROMIPS)
printf(" micromips");
if (e_flags & EF_MIPS_ARCH_ASE_MIPS32R2)
printf(" mips32r2");
if (e_flags & EF_MIPS_ARCH_ASE_MIPS64R2)
printf(" mips64r2");
printf("\n");
  
  #include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "main.h"

int main(int argc, char **argv) {
    int fd;
    struct stat st;
    unsigned char *map_start, *map_end, *e_ident;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
        exit(1);
    }

    if ((fd = open(argv[1], O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    if (fstat(fd, &st) == -1) {
        perror("fstat");
        exit(1);
    }

    map_start = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map_start == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    map_end = map_start + st.st_size;

    e_ident = (unsigned char *) map_start;
    check_elf(e_ident);

    print_magic(e_ident);
    print_class(e_ident);
    print_data(e_ident);
    print_version(e_ident);
    print_osabi(e_ident);
    print_abi(e_ident);
    print_type(*(unsigned int *)(e_ident + 16), e_ident);
    print_entry(*(unsigned long int *)(e_ident + 24), e_ident);

    close_elf(fd);
    munmap(map_start, st.st_size);

    return 0;
}

}
