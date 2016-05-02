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
		dir->tab_tmp[i][6] = ft_strcat(dir->tab_tmp[i][6], param->name);
		dir->tab_tmp[i][7] = ft_strdup(ft_itoa(dir->t));
		dir->tab_tmp[i][8] = ft_strdup(ft_itoa(i));
		dir->tab_tmp[i][9] = ft_strdup(ft_itoa(param->block));
		i++;

	}
}

void 		aff_sort_param(t_dir *dir, int i, int j, t_args args, char *path)
{
	j = dir->nb_file_a;
	int		toto;
	char 	*s;
	char 	*s2;
	
	ft_putstr("total ");
	// toto = (args.a == 0)? ft_toto(dir->nb_file, dir, args):
	// 						ft_toto(dir->nb_file_a, dir, args);
	toto = ft_toto(dir->nb_file, dir, args);
	ft_putendl(ft_itoa(toto));
	while (i < j && dir->tab_sort[i][6])
	{
		if ((dir->tab_sort[i][6][0] != '.') || args.a == 1)
		{
			if (args.l == 1)
			{
				ft_putchar('\n');
				//ft_putendl(dir->tab_sort[i][9]);
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
			if (args.l == 1 && dir->tab_sort[i][0][0] == 'l')
			{
				s = ft_strnew(64);
				s2 = ft_strnew(64);
				s = ft_strjoin(s, path);
				s = ft_strjoin(s, dir->tab_sort[i][6]);
				readlink(s, s2, 63);
				ft_putstr(" -> ");
				ft_putstr(s2);
			}
			if (args.un == 1 && args.l == 0)
				ft_putchar('\n');
			else
				ft_putchar('\t');
		}
		i++;
	}
}

int			ft_toto(int nb_file, t_dir *dir, t_args args)
{
	int		toto;
	int		i;

	toto = 0;
	i = dir->nb_file_a;
	while (i > 0)
	{
		if ((args.a == 1) || (args.a == 0 && dir->tab_sort[i - 1][6][0] != '.'))
			toto += ft_atoi(dir->tab_sort[i - 1][9]);
		//ft_putendl(dir->tab_sort[i - 1][9]);
		i--;
	}
	//toto = toto/512;
	return (toto);
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
	tab = (char ***)malloc(sizeof(char **) * (dir->nb_file_a + 1));
	while (i < dir->nb_file_a)
	{
		j = 0;
		tab[i] = (char **)malloc(sizeof(char *) * 11);
		while (j < 10)
		{
			tab[i][j] = ft_strnew(64);
			j++;
		}
		tab[i][j] = 0;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
