/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicoara <mnicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:31:36 by mnicoara          #+#    #+#             */
/*   Updated: 2018/01/24 10:40:46 by mnicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		hpv(char a[5][6], char *s, int aux[2])
{
	if (s[aux[2]] != '\n')
		a[aux[0]][aux[1]] = s[aux[2]];
	if (aux[1] == 4)
	{
		a[aux[0]][aux[1]] = '\0';
		aux[0]++;
		aux[1] = -1;
	}
}

void			init(int aux[3])
{
	aux[0] = 0;
	aux[1] = 0;
	aux[2] = 0;
}

int				check_line(char *s, t_map map_data[], int aux[], char a[5][6])
{
	if (aux[0] == 4)
	{
		aux[0] = 0;
		if (verify_mat(a) == 0 || (s[aux[2] + 1] != '\0' &&
			(s[aux[2] + 1] == '.' || s[aux[2] + 1] == '#')))
			return (0);
		else
			copy_mat(map_data, a);
		aux[2] = aux[2] + 1;
	}
	return (1);
}

int				read_file(int fd, t_map map_data[100])
{
	char	a[5][6];
	char	*s;
	int		aux[3];
	int		l;

	init(aux);
	s = (char*)malloc(sizeof(char*) * 100000);
	read(fd, s, 100000);
	l = ft_strlen(s);
	s[l] = '\0';
	if (ft_check(s) == 0)
		return (0);
	while (s[aux[2]])
	{
		hpv(a, s, aux);
		if (check_line(s, map_data, aux, a) == 0)
			return (0);
		aux[2]++;
		aux[1]++;
	}
	if ((map_data[0].nr * 21 - 1) != l)
		return (0);
	return (1);
}

int				file_valid(char *s, t_map map_data[100])
{
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (0);
	else
	{
		if (read_file(fd, map_data) == 0)
			return (0);
	}
	return (1);
}
