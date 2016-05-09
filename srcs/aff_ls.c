/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:56:57 by smassand          #+#    #+#             */
/*   Updated: 2016/02/23 19:57:13 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		aff_ls(t_param param, t_args args, t_dir *dir, char *s)
{
	dir->rep = opendir(s);
	if (dir->rep == NULL)
	{
		if (lstat(s, &dir->st) == -1 || (S_ISDIR(dir->st.st_mode) == 1))
		{
			ls_err(*dir, s);
			return ;
		}
		else
		{
			aff_ls2(dir, param, args, s);
			return ;
		}
	}
	rewinddir(dir->rep);
	ft_init_sort(dir, args);
	if ((dir->file = readdir(dir->rep)) != NULL)
		sort_param(&param, dir, args, s);
	aff_sort_param(dir, dir->nb_file_a, args, s);
	ft_free_tmp(dir);
	rewinddir(dir->rep);
	ft_putstr("\n\n");
	while ((args.recurs == 1) && ((dir->file = readdir(dir->rep)) != NULL))
		aff_ls_r(args, *dir, s);
	closedir(dir->rep);
}

void		aff_ls2(t_dir *dir, t_param param, t_args args, char *s)
{
	dir->pwd = getpwuid(dir->st.st_uid);
	dir->grp = getgrgid(dir->st.st_gid);
	dir->t = dir->st.st_mtime;
	dir->tm = *localtime(&dir->t);
	param.mode = get_mode(dir->st, dir);
	param.link = dir->st.st_nlink;
	param.usr = (dir->pwd != NULL) ? dir->pwd->pw_name : NULL;
	param.grp = (dir->grp != NULL) ? dir->grp->gr_name : NULL;
	param.size = dir->st.st_size;
	param.date = get_date(dir->tm, dir);
	param.name = ft_strdup(s);
	aff_param(param, args, s, 0);
	ft_putchar('\n');
}

void		aff_param(t_param param, t_args args, char *s, int j)
{
	char	*s2;
	int		i;

	s2 = ft_strnew(ft_strlen(s));
	i = ft_strlen(s);
	i = aff_param2(i, s);
	while (i < (int)ft_strlen(s))
	{
		s2[j] = s[i];
		j++;
		i++;
	}
	s2[i] = 0;
	if (args.l == 1)
		aff_param_l(param, args);
	ft_putstr(s2);
	if (param.mode[0] == 'd' && args.p == 1)
		ft_putchar('/');
	ft_putchar('\n');
	if (args.un == 1 && args.l == 0)
		ft_putchar('\n');
	else
		ft_putchar('\t');
}

int			aff_param2(int i, char *s)
{
	while (i > 0)
	{
		if (s[i] == '/')
		{
			i++;
			break ;
		}
		i--;
	}
	return (i);
}

void		aff_param_l(t_param param, t_args args)
{
	ft_putstr("total ");
	ft_putendl(ft_itoa(param.block));
	ft_putchar('\n');
	ft_putstr(param.mode);
	ft_putchar('\t');
	ft_putnbr(param.link);
	ft_putchar('\t');
	if (args.g == 0)
	{
		ft_putstr(param.usr);
		ft_putchar('\t');
	}
	if (args.o == 0)
	{
		ft_putstr(param.grp);
		ft_putchar('\t');
	}
	ft_putnbr(param.size);
	ft_putchar('\t');
	ft_putstr(param.date);
	ft_putchar('\t');
}
