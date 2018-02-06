/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicoara <mnicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:29:34 by mnicoara          #+#    #+#             */
/*   Updated: 2018/01/24 10:38:36 by mnicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		tam(char a[5][6], int i, int j)
{
	int k;

	k = 0;
	while (a[i][j] != '\0' && j < 4)
	{
		if (a[i][j] == '#')
		{
			if (i > 0 && a[i - 1][j] == '#')
				k++;
			if (j > 0 && a[i][j - 1] == '#')
				k++;
			if (i < 4 && a[i + 1][j] == '#')
				k++;
			if (j < 4 && a[i][j + 1] == '#')
				k++;
		}
		j++;
	}
	return (k);
}

int		checking_mat(char a[5][6])
{
	int i;
	int j;
	int k;

	swap_coll(a);
	swap_row(a);
	i = 0;
	k = 0;
	while (i < 4 && a[i] != '\0')
	{
		j = 0;
		k += tam(a, i, j);
		i++;
	}
	if (k == 0 || (k != 6 && k != 8))
		return (0);
	return (1);
}
