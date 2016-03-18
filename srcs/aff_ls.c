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
	int 	i;

	i = 0;
	dir->rep = opendir(s);
	if (dir->rep == NULL)
		ls_err(*dir, s);
	while ((dir->file = readdir(dir->rep)) != NULL)
	{
		get_param(dir, &param, s);
		if ((param.name[0] != '.') || args.a == 1)
		{
			aff_param(param, args);
			i++;
		}
	}
	closedir(dir->rep);
	ft_putstr("\n\n");
	dir->rep = opendir(s);
	if (dir->rep == NULL)
		ls_err(*dir, s);
	while ((args.R == 1) && ((dir->file = readdir(dir->rep)) != NULL))
		aff_ls_r(args, *dir, s);
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
				s2 = (char *)malloc(sizeof(char) * (ft_strlen(s) +
						ft_strlen(param2.name) + 2));
				s2 = ft_strjoin(s2, s);
				if (s2[ft_strlen(s2)] != '/' && s[0] != '/' && s[ft_strlen(s)] != '/')
					s2 = ft_strjoin(s2, "/");
				s2 = ft_strjoin(s2, param2.name);
				s2 = ft_strjoin(s2, "/");
				ft_putstr(s);
				ft_putstr(param2.name);
				ft_putstr(":\n");
				aff_ls(param2, args, &dir, s2);
			}
	}
}