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

void		aff_ls(t_param param, t_args args, t_dir dir, char *s)
{
	int 	i;

	i = 2;
	dir.rep = opendir(s);
	while ((dir.fichierlu = readdir(dir.rep)) != NULL)
	{
		get_param(dir, &param);
		if ((param.name[0] != '.') || args.a == 1)
		{
			aff_param(param, args);
			if ((i % 10 == 1 && args.R == 1))
				ft_putchar('\n');
			i++;
		}
	}
	rewinddir(dir.rep);
	ft_putstr("\n\n");
	if (args.R == 1)
		aff_lsd(param, args, dir, s);
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

void		aff_lsd(t_param param, t_args args, t_dir dir, char *s)
{
	char	*s2;

	while ((dir.fichierlu = readdir(dir.rep)) != NULL)
	{
		get_param(dir, &param);
		if (param.mode[0] == 'd' && param.name[0] != '.' && param.name[1] != '.')
			{
				s2 = (char *)malloc(sizeof(char) * (ft_strlen(s) +
						ft_strlen(param.name) + 5));
				s2 = ft_strjoin(s2, s);
				s2 = ft_strjoin(s2, param.name);
				s2 = ft_strjoin(s2, "/");
				ft_putstr("./");
				ft_putstr(param.name);
				ft_putstr(":\n");
				aff_ls(param, args, dir, s2);
			}
	}
}