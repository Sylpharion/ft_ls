/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:52:07 by smassand          #+#    #+#             */
/*   Updated: 2016/04/12 19:52:55 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void		sort_param(t_param *param, t_dir *dir, t_args args, char *s)
{
	rewinddir(dir->rep);
	get_sort(param, dir, s);
	if (args.f == 0)
		ft_sort_ascii(dir);
	if (args.t == 1)
		ft_sort_time(dir, 0, 0, dir->nb_file_a);
	if (args.r == 1)
		ft_sort_reverse(dir, args);
}

void		get_sort(t_param *param, t_dir *dir, char *s)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while ((dir->file = readdir(dir->rep)) != NULL)
	{
		get_param(dir, param, s);
		dir->tab_tmp[i][0] = ft_strdup(param->mode);
		dir->tab_tmp[i][1] = ft_strdup(ft_itoa(param->link));
		dir->tab_tmp[i][2] = ft_strdup(param->usr);
		dir->tab_tmp[i][3] = ft_strdup(param->grp);
		dir->tab_tmp[i][4] = ft_strdup(ft_itoa(param->size));
		dir->tab_tmp[i][5] = ft_strdup(param->date);
		dir->tab_tmp[i][6] = ft_strcat(dir->tab_tmp[i][6], param->name);
		dir->tab_tmp[i][7] = ft_strdup(ft_itoa(dir->t));
		dir->tab_tmp[i][8] = ft_strdup(ft_itoa(i));
		dir->tab_tmp[i][9] = ft_strdup(ft_itoa(param->block));
		i++;
	}
	i = 0;
	while (i < dir->nb_file_a)
	{
		dir->tab_sort[i] = dir->tab_tmp[i];
		i++;
	}
}

void		ft_init_sort(t_dir *dir, t_args args)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	(void)args;
	while ((dir->file = readdir(dir->rep)) != NULL)
	{
		if (dir->file->d_name[0] != '.')
			j++;
		i++;
	}
	dir->nb_file = j;
	dir->nb_file_a = i;
	rewinddir(dir->rep);
	dir->tab_sort = tab_init(dir);
	dir->tab_tmp = tab_init(dir);
}
