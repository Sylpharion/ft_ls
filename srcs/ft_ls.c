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
	while ((dir.fichierlu = readdir(dir.rep)) != NULL)
	{
		get_param(dir, &param);
		if ((param.name[0] != '.') || (args.a == 1))
			aff_param(param, args);
	}
	if (args.un == 0)
		ft_putchar('\n');
	if (closedir(dir.rep) == -1)
		exit(-1);
	return (0);
}
