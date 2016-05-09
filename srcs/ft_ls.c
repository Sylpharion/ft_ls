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

#include "../includes/ft_ls.h"

int			main(int argc, char **argv)
{
	t_dir	dir;
	t_param	param;
	t_args	args;

	ft_init(&dir, &param, &args);
	if (argc > 1)
		ft_init_args(&args, argv, argc, &dir);
	if (argc > 2)
	{
		if (args.r == 1 || args.t == 1)
			verif_ls_sort(param, dir, args);
		else
			verif_ls(param, dir, args);
	}
	else
		aff_ls(param, args, &dir, dir.path);
	return (0);
}
