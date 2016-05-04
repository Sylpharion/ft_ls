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

void 		aff_sort_param(t_dir *dir, int i, int j, t_args args, char *path)
{
	int		toto;
	
	if (args.l == 1)
	{
		ft_putstr("total ");
		toto = ft_toto(dir->nb_file, dir, args);
		ft_putendl(ft_itoa(toto));
	}
	while (i < j && dir->tab_sort[i][6])
	{
		if ((dir->tab_sort[i][6][0] != '.') || args.a == 1)
		{
			if (args.l == 1)
				aff_sort_param_l(dir, i, args);
			ft_putstr(dir->tab_sort[i][6]);
			if (dir->tab_sort[i][0][0] == 'd' && args.p == 1)
				ft_putchar('/');
			if (args.l == 1 && dir->tab_sort[i][0][0] == 'l')
				aff_sort_param2(dir, path, i);
			if (args.un == 1 && args.l == 0)
				ft_putchar('\n');
			else
				ft_putchar('\t');
		}
		i++;
	}
}

void		aff_sort_param2(t_dir *dir, char *path, int i)
{
	char 	*s;
	char 	*s2;

	s = ft_strnew(64);
	s2 = ft_strnew(64);
	s = ft_strjoin(s, path);
	s = ft_strjoin(s, dir->tab_sort[i][6]);
	readlink(s, s2, 63);
	ft_putstr(" -> ");
	ft_putstr(s2);
}

void 		aff_sort_param_l(t_dir *dir, int i, t_args args)
{
	ft_putchar('\n');
	ft_putstr(dir->tab_sort[i][0]);
	ft_putchar('\t');
	ft_putstr(dir->tab_sort[i][1]);
	ft_putchar('\t');
	if (args.g == 0)
	{
		ft_putstr(dir->tab_sort[i][2]);
		ft_putchar('\t');
	}
	if (args.o == 0)
	{
		ft_putstr(dir->tab_sort[i][3]);
		ft_putchar('\t');
	}
	ft_putstr(dir->tab_sort[i][4]);
	ft_putchar('\t');
	ft_putstr(dir->tab_sort[i][5]);
	ft_putchar('\t');
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
		i--;
	}
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
