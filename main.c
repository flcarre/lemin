/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:48:08 by lutsiara          #+#    #+#             */
/*   Updated: 2019/06/12 00:43:44 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned long	ft_djb2a(char *str, unsigned long range)
{
	unsigned long	hash;

	hash = 5381;
	while (str && *str)
	{
		hash = (hash * 33) ^ *str;
		str++;
	}
	if (range)
		return (hash % range);
	return (hash);
}

unsigned long	ft_hash(unsigned long addr)
{
	unsigned long	hash;
	unsigned int	i;

	hash = 0;
	i = 0;
	while (i < 64)
		hash = (hash * 33) ^ (addr >> i++);
	return (hash);
}

int		main(int ac, char **av)
{
	int				i;
	unsigned long	hash;
	char			**ptr;

	ptr = malloc(sizeof(char *) * (ac - 1));
	i = 0;
	while (av[++i])
		printf("%s - id = %lu\nhash = %lu\n", \
		av[i], ft_hash((unsigned long)av[i]) % (ac - 1), \
		ft_hash((unsigned long)av[i]));
	/*
	i = 0;
	while (av[++i])
	{
		hash = ft_djb2a(av[i], ac - 1);
		ptr[hash] = av[i];
	}
	i = 0;
	while (av[++i])
	{
		hash = ft_djb2a(av[i], ac - 1);
		printf("%s\n", ptr[hash]);
	}
	*/
	free(ptr);
	return (0);
}
