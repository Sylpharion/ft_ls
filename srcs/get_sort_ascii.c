/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_ascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 18:27:30 by smassand          #+#    #+#             */
/*   Updated: 2016/05/03 18:27:35 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_sort_ascii(t_dir *dir, int i, int j)
{
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * dir->nb_file_a);
	while (i < dir->nb_file_a)
	{
		tmp[i] = ft_strdup(dir->tab_tmp[i][6]);
		i++;
	}
	ft_sort_ascii2(0, dir, j, tmp);
	ft_sort_ascii3(0, dir, tmp, 0);
}

void		ft_sort_ascii2(int i, t_dir *dir, int j, char **tmp)
{
	char	*t;
	int		k;

	while (i < dir->nb_file_a)
	{
		k = 0;
		while (k < j - 1)
		{
			if (strcmp(tmp[k], tmp[k + 1]) > 0)
			{
				t = tmp[k];
				tmp[k] = tmp[k + 1];
				tmp[k + 1] = t;
			}
			k++;
		}
		j--;
		i++;
	}
}

void		ft_sort_ascii3(int i, t_dir *dir, char **tmp, int j)
{
	while (i < dir->nb_file_a)
	{
		j = 0;
		while (dir->tab_tmp[j] && ft_strcmp(dir->tab_tmp[j][6], tmp[i]) != 0)
			j++;
		dir->tab_sort[i] = dir->tab_tmp[j];
		if (dir->tab_tmp[j] == NULL)
			dir->tab_sort[i] = dir->tab_tmp[j - 1];
		if (dir->tab_sort[i] == NULL)
			return ;
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
