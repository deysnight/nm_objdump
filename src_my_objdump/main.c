/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** HA my main.c
*/

#include <stdlib.h>
#include <string.h>
#include "my_objdump.h"

int main(int ac, char **av)
{
	info_t info;
	int i = 1;

	if (ac < 2) {
		info.file = strdup("a.out");
		objdump(&info);
	}
	else {
		while (i < ac) {
			info.file = strdup(av[i]);
			if (objdump(&info) == -84)
				return (-84);
			i++;
		}
	}
	return (0);
}
