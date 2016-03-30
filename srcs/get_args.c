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

void		init_args(t_args *args, char **argv, int argc, int i)
{
	if (argc > 2)
	{

	}
	else
	{
		
	}


}

void		get_args2(t_args *args, char **argv, int i)
{
	args->l = (argv[1][i] == 'l')? 1 : args->l;
	args->R = (argv[1][i] == 'R')? 1 : args->R;
	args->a = (argv[1][i] == 'a')? 1 : args->a;
	args->r = (argv[1][i] == 'r')? 1 : args->r;
	args->t = (argv[1][i] == 't')? 1 : args->t;
	args->un = (argv[1][i] == '1')? 1 : args->un;
	if ((argv[1][i] != 'l' && argv[1][i] != 'R' && argv[1][i] != 'a' &&
		argv[1][i] != 'r' && argv[1][i] != 't' && argv[1][i] != '1' &&
		argv[1][i] != 'g') && (ft_strcmp(argv[1], "--") != 0))
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(argv[1][i]);
		ft_putstr("\nusage: ft_ls [-lRart1] [file ...]\n");
		exit(1);
	}
	i = 0;
	if (args->l == 1 && args->un == 1)
	{
		while (argv[1][i])
		{
			args->l = (argv[1][i] == 'l')? 1 : 0;
			args->un = (argv[1][i] == '1')? 1 : 0;
			i++;
		}
	}
}

void		get_args(t_args *args, char **argv, int argc, t_dir *dir)
{
	int 	i;

	i = 0;
	while(argv[1][i])
	{
		if ((argv[1][0] == '-') && argv[1][1])
		{
			dir->check_opt = 1;
			if (i == 0)
				i++;
			get_args2(args, argv, i);
		}
		else
		{
			dir->path = ft_strdup(argv[1]);
			break;
		}
		i++;
	}
	if (argc > 2)
		get_args_sup(argv, argc, dir);
}

void			get_args_sup(char **argv, int argc, t_dir *dir)
{
	int			i;

	i = 2;
	dir->travel = (char **)malloc(sizeof(char *) * argc + 5);
	while (dir->check_opt == 1? argv[i]: argv[i - 1])
	{
		if (dir->check_opt == 1)
		{
			dir->travel[i - 2] = (char *)malloc(sizeof(char) *
				ft_strlen(argv[i]) + 1);
			dir->travel[i - 2] = argv[i];
		}
		else
		{
			dir->travel[i - 2] = (char *)malloc(sizeof(char) *
				ft_strlen(argv[i - 1]) + 1);
			dir->travel[i - 2] = argv[i - 1];
		}
		i++;
	}
}

void		verif_ls(t_param param, t_dir dir, t_args args, int argc)
{
	int 	i;

	i = 0;
	while (dir.check_opt == 1? i < (argc - 2): i < (argc - 1))
	{
		if (dir.check_opt == 1? argc > 3: argc > 2)
		{
			ft_putstr(dir.travel[i]);
			ft_putstr(":\n");
		}
		aff_ls(param, args, &dir, dir.travel[i]);
		i++;
	}
}
