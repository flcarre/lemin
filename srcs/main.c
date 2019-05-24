/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:17:54 by lutsiara          #+#    #+#             */
/*   Updated: 2019/05/24 19:02:45 by lutsiara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	char	*line;
	int		ret;

	line = (void *)0;
	while ((ret = gnl(STDIN_FILENO, &line)) == 1)
	{
		ft_printf("%s\n", line);
		ft_memdel((void **)&line);
	}
	return ((ret < 0) ? -ret : ret);
}

/*
__attribute__((destructor)) int end()
{
	while (1);
}
*/
