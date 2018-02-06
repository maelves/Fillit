/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restrain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicoara <mnicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:31:19 by mnicoara          #+#    #+#             */
/*   Updated: 2018/01/24 10:41:29 by mnicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del_row(char a[5][6])
{
	int k;

	k = 3;
	while (a[0][k] == '.' && a[1][k] == '.' && a[2][k] == '.' && a[3][k] == '.')
	{
		a[0][k] = '\0';
		a[1][k] = '\0';
		a[2][k] = '\0';
		a[3][k] = '\0';
		k--;
	}
}

void	del_coll(char a[5][6])
{
	int k;
	int l;
	int i;

	k = 3;
	l = ft_strlen(a[0]);
	i = l;
	while (i == l)
	{
		i = 0;
		while (a[k][i] != '\0' && a[k][i] == '.')
			i++;
		if (i == l)
		{
			a[k][0] = '\0';
			a[k][1] = '\0';
			a[k][2] = '\0';
			a[k][3] = '\0';
			l = ft_strlen(a[0]);
			i = l;
		}
		k--;
	}
}

void	restrain(t_map map_data[100])
{
	int i;

	i = 0;
	while (i < map_data[0].nr)
	{
		del_row(map_data[i].a);
		del_coll(map_data[i].a);
		i++;
	}
}
