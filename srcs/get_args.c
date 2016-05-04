/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 01:53:46 by smassand          #+#    #+#             */
/*   Updated: 2016/02/20 01:53:51 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void		ft_init_args(t_args *args, char **argv, int argc, t_dir *dir)
{
	int 	j;

	j = 1;
	while (argv[j])
	{
		if (argv[j][0] == '-' && argv[j][1] && dir->check_opt == 0)
			get_args(args, argv, j);
		else
		{
			dir->path = ft_strdup(argv[j]);
			dir->travel = (char **)malloc(sizeof(char *) * argc - j);
			dir->check_travel = argc - j;
			dir->travel = get_args_sup(argv, argc, j, dir);
			return ;
		}
		j++;
	}
}

void		get_args(t_args *args, char **argv, int j)
{
	int 	i;

	i = 1;
	while(argv[j][i])
	{
		get_args2(args, argv, i, j);
		i++;
	}
}

void		get_args2(t_args *args, char **argv, int i, int j)
{
	args->l = (argv[j][i] == 'l')? 1 : args->l;
	args->R = (argv[j][i] == 'R')? 1 : args->R;
	args->a = (argv[j][i] == 'a')? 1 : args->a;
	args->r = (argv[j][i] == 'r')? 1 : args->r;
	args->t = (argv[j][i] == 't')? 1 : args->t;
	args->f = (argv[j][i] == 'f')? 1 : args->f;
	args->o = (argv[j][i] == 'o')? 1 : args->o;
	args->g = (argv[j][i] == 'g')? 1 : args->g;
	args->p = (argv[j][i] == 'p')? 1 : args->p;
	args->un = (argv[j][i] == '1')? 1 : args->un;
	if ((argv[j][i] != 'l' && argv[j][i] != 'R' && argv[j][i] != 'a' &&
		argv[j][i] != 'r' && argv[j][i] != 't' && argv[j][i] != '1' &&
		argv[j][i] != 'f' && argv[j][i] != 'o' && argv[j][i] != 'g' &&
		argv[j][i] != 'p') && (ft_strcmp(argv[j], "--") != 0))
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(argv[j][i]);
		ft_putstr("\nusage: ft_ls [-lRart1fogp] [file ...]\n");
		exit(1);
	}
	if (args->f == 1)
		args->a = 1;
	if (args->o == 1 || args->g == 1)
		args->l = 1;
	if (args->l == 1 && args->un == 1)
	{
		i = 0;
		while (argv[j][i])
		{
			args->l = (argv[j][i] == 'l')? 1 : 0;
			args->un = (argv[j][i] == '1')? 1 : 0;
			i++;
		}
	}
}

char		**get_args_sup(char **argv, int argc, int j, t_dir *dir)
{
	char	**s2;
	int 	i;
	int 	k;

	k = 0;
	i = 0;
	s2 = (char **)malloc(sizeof(char *) * argc);
	dir->check_args = argc - j;
	while (j < argc)
	{
		s2[k] = ft_strnew(ft_strlen(argv[j]));
		i = 0;
		while (argv[j][i])
		{
			s2[k][i] = argv[j][i];
			i++;
		}
		j++;
		k++;
	}
	return (s2);
}

void		verif_ls(t_param param, t_dir dir, t_args args)
{
	int 	i;

	i = 0;
	if (dir.check_travel > 1)
	{
		while (i < dir.check_travel)
		{
			if (dir.check_travel > 1)
			{
				if (dir.check_args > 1)
				{
					if (lstat(dir.travel[i], &dir.st) != -1 && (S_ISDIR(dir.st.st_mode) == 1))
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
