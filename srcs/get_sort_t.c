/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_t.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 07:36:13 by smassand          #+#    #+#             */
/*   Updated: 2016/04/08 07:36:18 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void		ft_sort_time(t_dir *dir)
{
	int 	i;
	int 	j;
	int 	k;
	int 	**t;
	int 	tmp;
	
	i = 0;
	tmp = 0;
	j = dir->nb_file_a;
	t = (int **)malloc(sizeof(int *) * dir->nb_file_a);
	while (i < dir->nb_file_a)
	{
		t[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	get_time(dir, t);

	while (i < j)
	{
		k = 0;
		while (k < j - 1)
		{
			if (t[k][0] < t[k + 1][0])
			{
				tmp = t[k][0];
				t[k][0] = t[k + 1][0];
				t[k + 1][0] = tmp;
				tmp = t[k][1];
				t[k][1] = t[k + 1][1];
				t[k + 1][1] = tmp;
			}
			k++;
		}
		j--;
		i++;
	}

	i = 0;
	while (i < dir->nb_file_a)
	{
		j = 0;
		while (ft_strcmp(dir->tab_tmp[j][7], ft_itoa(t[i][0])) != 0
			|| ft_strcmp(dir->tab_tmp[j][8], ft_itoa(t[i][1])) != 0)
			j++;
		dir->tab_sort[i] = dir->tab_tmp[j];
		i++;
	}


	free(dir->tab_tmp);
	dir->tab_tmp = tab_init(dir);
	i = 0;
	while (i < dir->nb_file_a)
	{
		dir->tab_tmp[i] = dir->tab_sort[i];
		i++;
	}
}

void 		get_time(t_dir *dir, int **t)
{
	int 	i;

	i = 0;
	while (i < dir->nb_file_a)
	{
		t[i][0] = ft_atoi(dir->tab_tmp[i][7]);
		t[i][1] = ft_atoi(dir->tab_tmp[i][8]);
		i++;
	}
}
