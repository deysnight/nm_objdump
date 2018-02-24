/*
** EPITECH PROJECT, 2018
** filesize.c
** File description:
** HA my filesize.c
*/

#include "my_objdump.h"

int filesize(int fd)
{
	struct stat file_info;

	if (fstat(fd, &file_info))
	{
		fprintf(stderr, "read file impossible\n");
		return (-84);
	}
	return (file_info.st_size);
}
