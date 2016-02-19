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

int			main(void)
{
	t_dir	dir;
	t_param	param;
	t_args	args;

	ft_init(&dir, &param, &args);		
	dir.rep = opendir("./");
	if (dir.rep == NULL)
		exit(1);
	ft_putstr("Le dossier a ete ouvert avec succes\n");
	ft_putstr("**************************************\n");
	
	while ((dir.fichierlu = readdir(dir.rep)) != NULL)
	{
		get_param(dir, &param);
		if (param.name[0] != '.')
			aff_param(param);
	}
	if (closedir(dir.rep) == -1)
		exit(-1);

	ft_putstr("\n**************************************\n");
	ft_putstr("Le dossier a ete ferme avec succes\n");
	return (0);
}
