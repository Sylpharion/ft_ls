/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 06:25:15 by smassand          #+#    #+#             */
/*   Updated: 2016/04/02 06:25:25 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void		verif_ls_sort(t_param param, t_dir dir, t_args args)
{
	int 	i;
	int 	j;

	i = 0;
	j = dir.check_travel;
	if (dir.check_travel > 1)
	{
		while (i < dir.check_travel)
		{
			if (dir.check_travel > 1)
			{
				if (dir.check_args > 1)
				{
					ft_putstr(dir.travel[j - 1]);
					ft_putstr(":\n");
				}
			}
			aff_ls(param, args, &dir, dir.travel[j - 1]);
			i++;
			j--;
		}
	}
	else
		aff_ls(param, args, &dir, dir.path);
}

void		ft_init_sort(t_dir *dir, t_args args)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	if (args.r == 1 || args.t == 1)
	{
		while ((dir->file = readdir(dir->rep)) != NULL)
		{
			if (dir->file->d_name[0] != '.')
				j++;
			i++;
		}
		dir->nb_file = (i <= 2)? 0 : j;
		dir->nb_file_a = (i <= 2)? 0 : i;
		rewinddir(dir->rep);
		dir->tab_sort = tab_init(dir);
		dir->tab_tmp = tab_init(dir);
	}
	else
		return ;
}

void		sort_param(t_param *param, t_dir *dir, t_args args, char *s)
{
	rewinddir(dir->rep);
	get_sort(param, dir, s, args);
	if (args.t == 1)
	{
		ft_sort_time(dir);
	}
	if (args.r == 1)
		ft_sort_reverse(dir, args);
}

void		get_sort(t_param *param, t_dir *dir, char *s, t_args args)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	(void)args;
	while ((dir->file = readdir(dir->rep)) != NULL)
	{
		get_param(dir, param, s);	
		dir->tab_tmp[i][0] = ft_strdup(param->mode);
		dir->tab_tmp[i][1] = ft_strdup(ft_itoa(param->link));
		dir->tab_tmp[i][2] = ft_strdup(param->usr);
		dir->tab_tmp[i][3] = ft_strdup(param->grp);
		dir->tab_tmp[i][4] = ft_strdup(ft_itoa(param->size));
		dir->tab_tmp[i][5] = ft_strdup(param->date);
		dir->tab_tmp[i][6] = ft_strdup(param->name);
		dir->tab_tmp[i][7] = ft_strdup(ft_itoa(dir->t));
		dir->tab_tmp[i][8] = ft_strdup(ft_itoa(i));
		i++;
	}
}

void 		aff_sort_param(t_dir *dir, int i, int j, t_args args)
{
	j = dir->nb_file_a;
	while (i < j)
	{
		if ((dir->tab_sort[i][6][0] != '.') || args.a == 1)
		{
			if (args.l == 1)
			{
				ft_putchar('\n');
				ft_putstr(dir->tab_sort[i][0]);
				ft_putchar('\t');
				ft_putstr(dir->tab_sort[i][1]);
				ft_putchar('\t');
				ft_putstr(dir->tab_sort[i][2]);
				ft_putchar('\t');
				ft_putstr(dir->tab_sort[i][3]);
				ft_putchar('\t');
				ft_putstr(dir->tab_sort[i][4]);
				ft_putchar('\t');
				ft_putstr(dir->tab_sort[i][5]);
				ft_putchar('\t');
			}
			ft_putstr(dir->tab_sort[i][6]);
			if (args.un == 1 && args.l == 0)
				ft_putchar('\n');
			else
				ft_putchar('\t');
		}
		i++;
	}
}

void 		ft_sort_reverse(t_dir *dir, t_args args)
{
	int 	i;
	int 	j;

	(void)args;
	i = 0;
	j = dir->nb_file_a;
	while (i < j)
	{
		dir->tab_sort[i] = dir->tab_tmp[j - i - 1];
		i++;
	}
}

char 		***tab_init(t_dir *dir)
{
	int 	i;
	int 	j;
	char 	***tab;
	i = 0;
	j = 0;
	tab = (char ***)malloc(sizeof(char **) * dir->nb_file_a);
	while (i < dir->nb_file_a)
	{
		tab[i] = (char **)malloc(sizeof(char *) * 9);
		while (j < 9)
		{
			tab[i][j] = ft_strnew(32);
			j++;
		}
		i++;
	}
	return (tab);
}
