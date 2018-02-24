/*
** EPITECH PROJECT, 2018
** get_flag.c
** File description:
** HA my get_flag.c
*/

#include "my_objdump.h"
#include "flags.h"

int get_flag64(Elf64_Ehdr *elf, int i)
{
	Elf64_Shdr const *sect = (void *)elf +
		(elf->e_shoff + elf->e_shentsize * i++);

	return (HAS_RELOC *
		(elf->e_type == ET_REL &&
		 (sect->sh_type == SHT_RELA || sect->sh_type == SHT_REL)) |
		EXEC_P * (elf->e_type == ET_EXEC) |
		HAS_SYMS * (sect->sh_type == SHT_SYMTAB ||
			    sect->sh_type == SHT_DYNSYM) |
		DYNAMIC * (elf->e_type == ET_DYN) |
		D_PAGED * ((elf->e_type == ET_EXEC || elf->e_type == ET_DYN)));
}

int get_flag32(Elf32_Ehdr *elf, int i)
{
	Elf32_Shdr const *sect = (void *)elf +
		(elf->e_shoff + elf->e_shentsize * i++);

	return (HAS_RELOC *
		(elf->e_type == ET_REL &&
		 (sect->sh_type == SHT_RELA || sect->sh_type == SHT_REL)) |
		EXEC_P * (elf->e_type == ET_EXEC) |
		HAS_SYMS * (sect->sh_type == SHT_SYMTAB ||
			    sect->sh_type == SHT_DYNSYM) |
		DYNAMIC * (elf->e_type == ET_DYN) |
		D_PAGED * ((elf->e_type == ET_EXEC || elf->e_type == ET_DYN)));
}


int get_flag(info_t *info)
{
	int flag = 0;
	int entries = info->elf->e_shnum;

	for (int i = 0; i < entries; i++) {
		if (info->elf->e_ident[EI_CLASS] == ELFCLASS32)
			flag |= get_flag32((Elf32_Ehdr *)info->data, i);
		else
			flag |= get_flag64(info->elf, i);
	}
	return (flag);
}
