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
	aff_sort_param(dir, 0, dir->nb_file_a, args, s);
	free(dir->tab_sort);
	free(dir->tab_tmp);
	rewinddir(dir->rep);
	ft_putstr("\n\n");
	while ((args.R == 1) && ((dir->file = readdir(dir->rep)) != NULL))
		aff_ls_r(args, *dir, s);
	closedir(dir->rep);
}

void			aff_ls2(t_dir *dir, t_param param, t_args args, char *s)
{
	dir->t = dir->st.st_mtime;
	dir->tm = *localtime(&dir->t);
	param.mode = get_mode(dir->st, dir);
	param.link = dir->st.st_nlink;
	param.usr = ((dir->pwd = getpwuid(dir->st.st_uid)) != NULL)?
					dir->pwd->pw_name : NULL;
	param.grp = ((dir->grp = getgrgid(dir->st.st_gid)) != NULL)?
					dir->grp->gr_name : NULL;
	param.size = dir->st.st_size;
	param.date = get_date(dir->tm, dir);
	param.name = ft_strdup(s);
	aff_param(param, args, s);
	ft_putchar('\n');
}

void		aff_param(t_param param, t_args args, char *s)
{
	char	*s2;
	int		i;
	int 	j;

	s2 = ft_strnew(ft_strlen(s));
	i = ft_strlen(s);
	j = 0;
	while(i > 0)
	{
		if (s[i] == '/')
		{
			i++;
			break;
		}
		i--;
	}
	while (i < ft_strlen(s))
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
