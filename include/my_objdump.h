/*
** EPITECH PROJECT, 2018
** my_objdump.h
** File description:
** HA my my_objdump.h
*/

#ifndef OBJDUMP_H_
# define OBJDUMP_H_

#include <elf.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

typedef struct info_s
{
	char *file;
	void *data;
	Elf64_Ehdr *elf;
	Elf64_Shdr *shdr;
	char *strtab;
	int size;
} info_t;

int objdump(info_t *);
int filesize(int);
void print_header(info_t *);
void print_content(info_t *);

#endif
