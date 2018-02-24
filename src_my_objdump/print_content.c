/*
** EPITECH PROJECT, 2018
** print_content.c
** File description:
** HA my print_content.c
*/

#include "my_objdump.h"

void print_hexa_content(unsigned char *buff, int size)
{
	int i = 0;

	while (i < size) {
		printf("%02x", buff[i]);
		i++;
		if (i % 4 == 0)
			printf(" ");
	}
	while (i < 16) {
		printf("  ");
		i++;
		if (i % 4 == 0)
			printf(" ");
	}
}

void print_ascii_content(unsigned char *buff, int size)
{
	char tmp[17];
	int i = 0;

	while (i < 16) {
		if (i < size && (buff[i] >= 32 && buff[i] <= 126))
			tmp[i] = buff[i];
		else if (i >= size)
			tmp[i] = ' ';
		else
			tmp[i] = '.';
		i++;
	}
	printf(" %s\n", tmp);
}

void print_address(info_t *info, int x, int i, int u)
{
	char useless[17];
	int len = 0;
	unsigned int section_end = info->shdr[x].sh_addr
		+ info->shdr[x].sh_size;
	unsigned int address = info->shdr[x].sh_addr + i - u;

	len = sprintf(useless, "%x", section_end);
	if (len < 4)
		len = 4;
	printf(" %0*x ", len, address);
}

void print_section_content(info_t *info, int x)
{
	size_t i = 0;
	int u = 0;
	unsigned char buff[17];

	while (i < info->shdr[x].sh_size) {
		buff[u] = *(((unsigned char *)info->data)
			    + info->shdr[x].sh_offset + i);

		u++;
		if (u == 16) {
			print_address(info, x, i, u - 1);
			print_hexa_content(buff, 16);
			print_ascii_content(buff, 16);
			memset(buff, '\0', 17);
			u = 0;
		}
		i++;
	}
	if (u > 0) {
		print_address(info, x, i, u);
		print_hexa_content(buff, u);
		print_ascii_content(buff, u);
	}
}

void print_content(info_t *info)
{
	int i = 0;

	while (i < info->elf->e_shnum)
	{
		if (info->shdr[i].sh_type != SHT_NULL &&
		    info->shdr[i].sh_type != SHT_NOBITS &&
		    info->shdr[i].sh_type != SHT_SYMTAB &&
		    info->shdr[i].sh_type != SHT_STRTAB) {
			printf("Contents of section %s :\n",
			       info->strtab + info->shdr[i].sh_name);
			print_section_content(info, i);
		}
		i++;
	}
}
