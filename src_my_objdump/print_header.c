/*
** EPITECH PROJECT, 2018
** print_header.c
** File description:
** HA my print_header.c
*/

#include "my_objdump.h"
#include "flags.h"

void print_flag(unsigned int flag)
{
	int flag_use = 0;
	char *tab_flag[] = { "HAS_RELOC", "EXEC_P", "HAS_LINENO",
			     "HAS_DEBUG", "HAS_SYMS", "HAS_LOCALS",
			     "DYNAMIC", "WP_TEXT", "D_PAGED"};
	unsigned int flag_value[] = { HAS_RELOC, EXEC_P, HAS_LINENO,
				      HAS_DEBUG, HAS_SYMS, HAS_LOCALS,
				      DYNAMIC, WP_TEXT, D_PAGED};

	for (int i = 0; i < 9; i++) {
		if (flag & flag_value[i]) {
			if (flag_use == 0)
				printf("%s", tab_flag[i]);
			else
				printf(", %s", tab_flag[i]);
			flag_use++;
		}
	}
	if (flag_use == 0)
		printf("BFD_NO_FLAGS");
}

void print_header(info_t *info)
{
	unsigned int flag = get_flag(info);

	printf("\n%s:\tfile format elf64-x86-64\n", info->file);
	printf("architecture: i386:x86-64, flags 0x%.8x\n", flag);
	print_flag(flag);
	printf("\nstart address 0x%.16x\n\n", (unsigned int)info->elf->e_entry);
}
