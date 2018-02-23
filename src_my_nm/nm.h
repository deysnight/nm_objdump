/*
** EPITECH PROJECT, 2018
** nm.h
** File description:
** HA my nm.h
*/

#ifndef NM_H_
# define NM_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>

int get_elf(char *str);
int elf_check_header(Elf64_Ehdr *data);
void elf_print_header(Elf64_Ehdr *data);

#endif
