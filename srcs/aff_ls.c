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

# include "../includes/ft_ls.h"

void		aff_ls(t_param param, t_args args, t_dir *dir, char *s)
{
	dir->rep = opendir(s);
	if (dir->rep == NULL)
	{
		ls_err(*dir, s);
		return ;
	}
	ft_init_sort(dir, args);
	while ((dir->file = readdir(dir->rep)) != NULL)
	{
		get_param(dir, &param, s);
		 if ((param.name[0] != '.') || args.a == 1)
		 {
			if (args.r == 1 || args.t == 1)
			{
				sort_param(&param, dir, args, s);
				break;
			}
			else
		 		aff_param(param, args);
		}
	}
	if (args.r == 1 || args.t == 1)
		aff_sort_param(dir, 0, 0, args);
	free(dir->tab_sort);
	free(dir->tab_tmp);
	rewinddir(dir->rep);
	ft_putstr("\n\n");
	while ((args.R == 1) && ((dir->file = readdir(dir->rep)) != NULL))
		aff_ls_r(args, *dir, s);
	closedir(dir->rep);
}

void		aff_param(t_param param, t_args args)
{
	if (args.l == 1)
	{
		ft_putchar('\n');
		ft_putstr(param.mode);
		ft_putchar('\t');
		ft_putnbr(param.link);
		ft_putchar('\t');
		ft_putstr(param.usr);
		ft_putchar('\t');
		ft_putstr(param.grp);
		ft_putchar('\t');
		ft_putnbr(param.size);
		ft_putchar('\t');
		ft_putstr(param.date);
		ft_putchar('\t');
	}
	ft_putstr(param.name);
	if (args.un == 1 && args.l == 0)
		ft_putchar('\n');
	else
		ft_putchar('\t');
}

void		aff_ls_r(t_args args, t_dir dir, char *s)
{
	char	*s2;
	t_param	param2;

	ft_init_param(&param2);
	get_param(&dir, &param2, s);
	if (param2.mode[0] == 'd')
	{
		if (((param2.name[0] != '.' && param2.name[1] != '.'))
			|| (param2.name[0] == '.' && param2.name[1] != '/'
				&& param2.name[1] && param2.name[1] != '.' && args.a == 1))
			{
				s2 = ft_strnew(ft_strlen(s) + ft_strlen(param2.name) + 3);
				s2 = ft_strcat(s2, s);
				if (s[ft_strlen(s) - 1] != '/')
					s2 = ft_strjoin(s2, "/");
				s2 = ft_strjoin(s2, param2.name);
				ft_putstr(s2);
				ft_putstr(":\n");
				s2 = ft_strjoin(s2, "/");
				aff_ls(param2, args, &dir, s2);
				free(s2);
			}
	}
}
