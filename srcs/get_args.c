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

void		get_args2(t_args *args, char **argv, int i)
{
	args->l = (argv[1][i] == 'l')? 1 : args->l;
	args->R = (argv[1][i] == 'R')? 1 : args->R;
	args->a = (argv[1][i] == 'a')? 1 : args->a;
	args->r = (argv[1][i] == 'r')? 1 : args->r;
	args->t = (argv[1][i] == 't')? 1 : args->t;
	args->un = (argv[1][i] == '1')? 1 : args->un;
	if (argv[1][i] != 'l' && argv[1][i] != 'R' && argv[1][i] != 'a' &&
		argv[1][i] != 'r' && argv[1][i] != 't' && argv[1][i] != '1' &&
		argv[1][i] != 'g')
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(argv[1][i]);
		ft_putstr("\nusage: ft_ls [-lRartg1] [file ...]\n");
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

void		get_args(t_args *args, char **argv, t_dir *dir)
{
	int 	i;

	i = 0;
	while(argv[1][i])
	{
		if ((argv[1][0] == '-') && argv[1][1])
		{
			if (i == 0)
				i++;
			get_args2(args, argv, i);
		}
		else
		{
			dir->path = ft_strjoin(dir->path, argv[1]);
			dir->path = ft_strjoin(dir->path, "/");
			break;
		}
		i++;
	}
}
