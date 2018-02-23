/*
** EPITECH PROJECT, 2018
** get_elf.c
** File description:
** HA my get_elf.c
*/

#include "nm.h"

void test_print_info(void *data)
{
	Elf64_Ehdr *tmp = (Elf64_Ehdr*)data;
	Elf64_Sym *test = (Elf64_Sym*)(data + tmp->e_shoff);
	
	printf("segment size in file: %lu\n", test->st_value);
	printf("\n");
}

int elf_check_header(Elf64_Ehdr *data)
{
	if (data->e_ident[EI_MAG0] != ELFMAG0
	    || data->e_ident[EI_MAG1] != ELFMAG1
	    || data->e_ident[EI_MAG2] != ELFMAG2
	    || data->e_ident[EI_MAG3] != ELFMAG3)
		return (-1);
	if (data->e_ident[EI_CLASS] != ELFCLASS64)
		return (-1);
	return (0);
}


void elf_print_header(Elf64_Ehdr *data)
{
	printf("Point d'entree                               : %p\n", (void*)data->e_entry);
	printf("Adresse de la table des segments (relative)  : + %4lu bytes\n", data->e_phoff);
	printf("Nombre d'elements dans la table des segments : %d\n", data->e_phnum);
	printf("Adresse de la table des sections (relative)  : + %4lu bytes\n", data->e_shoff);
	printf("Nombre d'elements dans la table des sections : %d\n", data->e_shnum);
	
	printf("e_shstrndx : %4d\n", data->e_shstrndx);
}

int get_elf(char *str)
{
	int fd;
	void *data;
	struct stat file_infos;
	
	if ((fd = open(str, O_RDONLY)) > 0)
	{
		if (fstat(fd, &file_infos))
		{
			fprintf(stderr, "Recuperation des informations du fichier impossible\n");
			return (84);
		}
		else if ((data = mmap(0, file_infos.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
			fprintf(stderr, "Chargement du fichier en memoire impossible\n");
		else
		{	
			if (!elf_check_header((Elf64_Ehdr *)data)) {
				test_print_info(data);
				elf_print_header((Elf64_Ehdr *)data);
			}
			munmap(data, file_infos.st_size);
		}
		close(fd);
	}
	else {
		fprintf(stderr, "Ouverture du fichier impossible\n");
		return (84);
	}
	return (0);
}
