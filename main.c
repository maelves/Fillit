/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicoara <mnicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:29:53 by mnicoara          #+#    #+#             */
/*   Updated: 2018/01/24 10:46:52 by mnicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**alocate(int n)
{
	char	**s;
	int		i;
	int		j;

	s = (char**)malloc(sizeof(char*) * (n + 1));
	i = 0;
	while (i < n)
	{
		j = 0;
		s[i] = (char *)malloc(n + 1);
		while (j < n)
		{
			s[i][j] = '.';
			j++;
		}
		s[i][n] = '\0';
		i++;
	}
	s[n] = 0;
	return (s);
}

int		main(int argc, char **argv)
{
	char	**s;
	int		l;
	t_map	map_data[50];

	if (argc == 2)
	{
		if (file_valid(argv[1], map_data) == 1 && map_data[0].nr <= 26)
		{
			restrain(map_data);
			l = 2;
			s = alocate(26);
			while (1)
			{
				solver(s, 0, l, map_data);
				l++;
			}
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit <input file>\n");
	return (0);
}
