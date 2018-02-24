/*
** EPITECH PROJECT, 2018
** my_objdump.c
** File description:
** HA my my_objdump.c
*/

#include "my_objdump.h"

int elf_check_header(info_t *info)
{
	if (info->elf->e_ident[EI_MAG0] != ELFMAG0
	    || info->elf->e_ident[EI_MAG1] != ELFMAG1
	    || info->elf->e_ident[EI_MAG2] != ELFMAG2
	    || info->elf->e_ident[EI_MAG3] != ELFMAG3) {
		fprintf(stderr, "%s : Not Elf format\n", info->file);
		return (-1);
	}
	if (info->elf->e_ident[EI_CLASS] != ELFCLASS64)
		return (-1);
	return (0);
}

int fillandprint(info_t *info)
{
	info->elf = (Elf64_Ehdr *)info->data;
	if (elf_check_header(info) == -1)
		return (-84);
	info->shdr = (Elf64_Shdr *)((char *)info->data +
				    info->elf->e_shoff);
	info->strtab = (char *)((char *)info->data
				+ info->shdr[info->elf->e_shstrndx].sh_offset);
	print_header(info);
	print_content(info);
	return (0);
}

int objdump(info_t *info)
{
	int fd;

	if ((fd = open(info->file, O_RDONLY)) > 0) {
		info->size = filesize(fd);
		if (info->size < 0)
			return (-84);
		if ((info->data = mmap(0, (size_t)info->size, PROT_READ,
				       MAP_PRIVATE, fd, 0)) == MAP_FAILED)
			fprintf(stderr, "Load file impossible\n");
		else {
			if (fillandprint(info))
				return (-84);
			close(fd);
		}
	}
	else {
		fprintf(stderr, "objdump: 'a.out': No such file\n");
		return (-84);
	}
	return (0);
}
