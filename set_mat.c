/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicoara <mnicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:31:24 by mnicoara          #+#    #+#             */
/*   Updated: 2018/01/24 10:31:54 by mnicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_mat(char **a, int k)
{
	int i;
	int j;

	i = 0;
	while (i < k)
	{
		j = 0;
		while (j < k)
		{
			a[i][j] = '.';
			j++;
		}
		a[i][j] = '\0';
		i++;
	}
	a[i][0] = '\0';
}