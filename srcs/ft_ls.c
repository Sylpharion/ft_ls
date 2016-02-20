/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:05:32 by smassand          #+#    #+#             */
/*   Updated: 2016/02/11 15:05:37 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

int			main(int argc, char **argv)
{
	t_dir	dir;
	t_param	param;
	t_args	args;

	ft_init(&dir, &param, &args);
	if (argc > 1)
		get_args(&args, argv, &dir);	
	dir.rep = opendir(dir.path);
	if (dir.rep == NULL)
	{
		if ((argv[1] && (argv[1][0] != '-')) || (*argv[1] == '-'))
		{
			ft_putstr("ft_ls: ");
			ft_putstr(argv[1]);
			ft_putstr(": No such file or directory\n");
		}
		exit(1);
	}
	ft_putstr("Le dossier a ete ouvert avec succes\n");
	ft_putstr("**************************************\n");
	
	while ((dir.fichierlu = readdir(dir.rep)) != NULL)
	{
		get_param(dir, &param);
		if ((param.name[0] != '.') || (args.a == 1))
			aff_param(param);
	}
	if (closedir(dir.rep) == -1)
		exit(-1);

	ft_putstr("\n**************************************\n");
	ft_putstr("Le dossier a ete ferme avec succes\n");
	return (0);
}

void		get_args2(t_args *args, char **argv, int i)
{
	args->l = (argv[1][i] == 'l')? 1 : 0;
	args->R = (argv[1][i] == 'R')? 1 : 0;
	args->a = (argv[1][i] == 'a')? 1 : 0;
	args->r = (argv[1][i] == 'r')? 1 : 0;
	args->t = (argv[1][i] == 't')? 1 : 0;
	if (argv[1][i] != 'l' && argv[1][i] != 'R' && argv[1][i] != 'a' &&
		argv[1][i] != 'r' && argv[1][i] != 't')
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(argv[1][i]);
		ft_putstr("\nusage: ft_ls [-lRart] [file ...]\n");
		exit(1);
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