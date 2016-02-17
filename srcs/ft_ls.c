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
	struct 	dirent *fichierlu = NULL; /* Déclaration d'un pointeur vers la structure dirent. */
	time_t 	t;
	struct 	stat st;
	struct 	tm tm;
	struct 	passwd *pwd = NULL;
	struct 	group *grp = NULL;

	ft_init(&dir.rep);
	dir.rep = opendir("./"); /* Ouverture d'un dossier */
	ft_putstr("Le dossier a ete ouvert avec succes\n");
	ft_putstr("**************************************\n\n");
	
	if (dir.rep == NULL) /* Si le dossier n'a pas pu être ouvert */
		exit(1);
	rewinddir(dir.rep);
	while ((fichierlu = readdir(dir.rep)) != NULL)
	{
	
		stat(fichierlu->d_name, &st);
		t = st.st_mtime;
		tm = *localtime(&t);
		aff_mode(st);
		aff_id(pwd, grp, st);
		aff_size(st);
		aff_date(tm);
		aff_name(fichierlu);
	}
	if (closedir(dir.rep) == -1) /* S'il y a eu un souci avec la fermeture */
	exit(-1);
	ft_putstr("\n**************************************\n");
	puts("Le dossier a ete ferme avec succes");
	return (0);
}