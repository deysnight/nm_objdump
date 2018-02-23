/*
** EPITECH PROJECT, 2018
** print_header.c
** File description:
** HA my print_header.c
*/

#include "my_objdump.h"

void print_header(info_t *info)
{

	printf("%d\n", info->elf->e_flags);
	
	printf("\n%s:\tformat de fichier elf64-x86-64\n", info->file);
	printf("architecture: i386:x86-64, fanions\n");
	printf("ligne ou je sais pas quoi mlettre dedant\n");
	printf("addresse de départ 0x%.16x\n", (unsigned int)info->elf->e_entry);
}
