#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char);
int close(int);


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
#endif
