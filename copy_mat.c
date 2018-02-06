/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_mat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicoara <mnicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:29:40 by mnicoara          #+#    #+#             */
/*   Updated: 2018/01/24 10:31:54 by mnicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	copy_mat(t_map map_data[100], char a[5][6])
{
	static int	k;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (a[i][j] == '#')
				map_data[k].a[i][j] = (char)(k + 'A');
			else
				map_data[k].a[i][j] = '.';
			j++;
		}
		i++;
	}
	map_data[0].nr = k + 1;
	k++;
}
