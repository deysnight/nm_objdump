/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** HA my main.c
*/

#include "nm.h"

int main(int ac, char **av)
{
	int i = 1;

	if (ac < 2)
		get_elf("a.out");
	else {
		while (i < ac) {
			if (get_elf(av[i]) == 84)
				return (84);
			i++;
		}
	}
	return (0);
}
