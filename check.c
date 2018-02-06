/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicoara <mnicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:29:25 by mnicoara          #+#    #+#             */
/*   Updated: 2018/01/24 10:31:54 by mnicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	auxi(char *s, int *i, int *k, int *nb)
{
	*nb = *nb + 1;
	if (*nb % 4 == 0 && s[*i + 1] == '\0' && *k == 4)
	{
		s[*i + 1] = '\n';
		s[*i + 2] = '\0';
	}
	if (*nb % 5 == 0)
		*k = 4;
}

int		ft_check(char *s)
{
	int i;
	int k;
	int nb;

	nb = 0;
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			auxi(s, &i, &k, &nb);
			if (k != 4)
				return (0);
			k = 0;
		}
		if (s[i] != '\n')
			k++;
		i++;
	}
	if (nb < 4)
		return (0);
	return (1);
}
