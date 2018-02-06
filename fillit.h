/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnicoara <mnicoara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 10:29:47 by mnicoara          #+#    #+#             */
/*   Updated: 2018/01/24 10:31:54 by mnicoara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct	s_map
{
	char		a[5][6];
	int			nr;
}				t_map;

void			set_mat(char **a, int k);
void			solver(char **a, int k, int l, t_map map_data[100]);
void			restrain(t_map map_data[100]);
void			copy_mat(t_map map_data[100], char a[5][6]);
int				verify_mat(char a[5][6]);
int				ft_check(char *s);
void			swap_row(char a[5][6]);
void			swap_coll(char a[5][6]);
int				file_valid(char *s, t_map map_data[100]);
int				checking_mat(char a[5][6]);

#endif
