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
		get_args(&args, argv, argc, &dir);
	dir.rep = opendir(dir.path);
	if (dir.rep == NULL)
		ls_err(dir, dir.path);
	if (argc > 2)
		verif_ls(param, dir, args, argc);
	else
		aff_ls(param, args, &dir, dir.path);
	return (0);
}
