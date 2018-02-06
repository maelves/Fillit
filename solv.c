/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicoara <mnicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:31:29 by mnicoara          #+#    #+#             */
/*   Updated: 2018/01/24 10:46:31 by mnicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	afficher(char **a, int l)
{
	int i;
	int j;

	i = 0;
	while (i < l)
	{
		j = 0;
		while (j < l)
		{
			ft_putchar(a[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		wannabe(char **a, int aux[2], char tup[5][6], int l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tup[i][0] != '\0')
	{
		while (tup[i][j] != '\0')
		{
			if ((tup[i][j] != '.' && a[aux[0] + i][aux[1] + j] != '.')
					|| (aux[0] + i >= l || aux[1] + j >= l))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	pute(char **a, int aux[2], char tup[5][6], int l)
{
	int	i;
	int	j;

	i = 0;
	while (tup[i][0] != '\0' && i < l)
	{
		j = 0;
		while (tup[i][j] != '\0' && j < l)
		{
			if (tup[i][j] != '.')
				a[aux[0] + i][aux[1] + j] = tup[i][j];
			j++;
		}
		i++;
	}
}

void	clean(char ***a, int k, int l)
{
	int		i;
	int		j;
	char	**c;

	c = *a;
	i = 0;
	j = 0;
	while (i < l)
	{
		while (j < l)
		{
			if (c[i][j] == 'A' + k)
				c[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	*a = c;
}

void	solver(char **a, int k, int l, t_map map_data[100])
{
	int aux[2];

	aux[0] = 0;
	aux[1] = 0;
	while (aux[0] < l && k <= map_data[0].nr)
	{
		while (aux[1] < l && k <= map_data[0].nr)
		{
			clean(&a, k, l);
			if (wannabe(a, aux, map_data[k].a, l) == 1)
			{
				pute(a, aux, map_data[k].a, l);
				if (k == map_data[0].nr)
				{
					afficher(a, l);
					exit(0);
				}
				solver(a, k + 1, l, map_data);
			}
			aux[1]++;
		}
		aux[0]++;
		aux[1] = 0;
	}
}
