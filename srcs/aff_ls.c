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
						ft_strlen(param2.name) + 3));
				s2 = ft_strdup(s);
				//if (s2[ft_strlen(s2)] != '/')
			  	s2 = ft_strjoin(s2, "/");
				s2 = ft_strjoin(s2, param2.name);
				//if (s2[ft_strlen(s2)] != '/')
				s2 = ft_strjoin(s2, "/");
				//ft_putname(s, param2.name);
				ft_scotch(ft_putname(s, param2.name));
				// s2 = ft_scotch(s2);
				// ft_putstr("toto + toto = ");
				// ft_putendl(s2);
				// ft_putchar('\n');
				aff_ls(param2, args, &dir, s2);
				free(s2);
			}
	}
}

char		*ft_putname(char *s, char *s2)
{
	char *s3 = (char *)malloc(sizeof(char) * (ft_strlen(s) +
				ft_strlen(s2) + 5));
	s3 = ft_strcat(s3, s);
	if (s[ft_strlen(s) - 1] != '/' && s2[0] != '/')
		s3 = ft_strcat(s3, "/");
	s3 = ft_strcat(s3, s2);
	s3 = ft_strcat(s3, ":");
	return (s3);
}

void		ft_scotch(char *s2)
{
	int i = 0;
	int j = 0;
	char *s = (char *)malloc(sizeof(char) * ft_strlen(s2));

	while (s2[i])
	{
		s[j] = s2[i];
		if (s2[i] == '/' && s2[i + 1] == '/')
			i++;
		i++;
		j++;
	}
	ft_putendl(s);
}