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

	if (argc > 2)
		exit(1);
	ft_init(&dir);		
	dir.rep = opendir("./"); /* Ouverture d'un dossier */

	ft_putstr("Le dossier a ete ouvert avec succes\n");
	ft_putstr("**************************************\n\n");
	
	if (dir.rep == NULL) /* Si le dossier n'a pas pu être ouvert */
		exit(1);
	//gere_param(argv[1]);
	while ((dir.fichierlu = readdir(dir.rep)) != NULL)
	{
		if (argv[1])
			aff_ls(dir);
		//else if (argv[2] == "-R")
		else
		{
			ft_putstr(dir.fichierlu->d_name);
			ft_putchar('\t');
		}	
	}
	if (closedir(dir.rep) == -1) /* S'il y a eu un souci avec la fermeture */
		exit(-1);
	ft_putstr("\n**************************************\n");
	ft_putstr("Le dossier a ete ferme avec succes\n");
	return (0);
}