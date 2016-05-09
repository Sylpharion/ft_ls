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

#include "../includes/ft_ls.h"

void		ft_sort_reverse(t_dir *dir, t_args args)
{
	int		i;
	int		j;

	(void)args;
	i = 0;
	j = dir->nb_file_a;
	while (i < j)
	{
		dir->tab_sort[i] = dir->tab_tmp[j - i - 1];
		i++;
	}
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
			ft_strcat(s2, s);
			if (s[ft_strlen(s) - 1] != '/')
				ft_strcat(s2, "/");
			ft_strcat(s2, param2.name);
			ft_putstr(s2);
			ft_putstr(":\n");
			ft_strcat(s2, "/");
			aff_ls(param2, args, &dir, s2);
			free(s2);
		}
	}
}

void		verif_ls(t_param param, t_dir dir, t_args args)
{
	int		i;

	i = 0;
	if (dir.check_travel > 1)
	{
		while (i < dir.check_travel)
		{
			if (dir.check_travel > 1)
			{
				if (dir.check_args > 1)
				{
					if (lstat(dir.travel[i], &dir.st) != -1 &&
						(S_ISDIR(dir.st.st_mode) == 1))
					{
						ft_putstr(dir.travel[i]);
						ft_putstr(":\n");
					}
				}
			}
			aff_ls(param, args, &dir, dir.travel[i]);
			i++;
		}
	}
	else
		aff_ls(param, args, &dir, dir.path);
}

void		verif_ls_sort(t_param param, t_dir dir, t_args args)
{
	int		i;
	int		j;

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
