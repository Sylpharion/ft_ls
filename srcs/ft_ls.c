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

char			**ft_nlen(struct dirent *fichierLu, DIR *rep)
{
	size_t	size;

	size = 0;
	rewinddir(rep);
	while ((fichierLu = readdir(rep)) != NULL)
	{
		if (ft_strlen(fichierLu->d_name) > size)
			size = ft_strlen(fichierLu->d_name);
	}
	return ((char **)malloc(sizeof(char*) * size));
}

void			aff_date(struct tm tm)
{
	ft_putnbr(tm.tm_mon);
	ft_putchar(' ');
	ft_putnbr(tm.tm_mday);
	ft_putchar(' ');
	if (((double)tm.tm_hour / 10) < 1)
		ft_putnbr(0);
	ft_putnbr(tm.tm_hour);
	ft_putchar(':');
	if (((double)tm.tm_min / 10) < 1)
		ft_putnbr(0);
	ft_putnbr(tm.tm_min);
	ft_putchar(' ');
}

void			aff_dir(struct dirent *fichierLu)
{
	ft_putstr(fichierLu->d_name);
	ft_putchar('\n');
}

void			aff_id(struct passwd *pwd, struct group *grp, struct stat st)
{
	if ((pwd = getpwuid(st.st_uid)) != NULL)
		ft_putstr(pwd->pw_name);
	ft_putchar(' ');
	if ((grp = getgrgid(st.st_gid)) != NULL)
		ft_putstr(grp->gr_name);
	ft_putchar(' ');
}

int			main(void)
{
	DIR* 		rep = NULL;
	struct 	dirent *fichierLu = NULL; /* Déclaration d'un pointeur vers la structure dirent. */
	time_t 	t;
	struct 	stat st;
	struct 	tm tm;
	struct 	passwd *pwd = NULL;
	struct 	group *grp = NULL;
	//char		**s;

	//s = ft_nlen(fichierLu, rep);
	rep = opendir("./"); /* Ouverture d'un dossier */
	ft_putstr("Le dossier a ete ouvert avec succes\n");
	ft_putstr("**************************************\n\n");
	
	if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */
		exit(1);
	rewinddir(rep);
	while ((fichierLu = readdir(rep)) != NULL)
	{
		stat(fichierLu->d_name, &st);
		t = st.st_ctime;
		tm = *localtime (&t);
		aff_id(pwd, grp, st);
		aff_date(tm);
		aff_dir(fichierLu);
	}
	if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */
	exit(-1);
	ft_putstr("\n**************************************\n");
	puts("Le dossier a ete ferme avec succes");
	return (0);
}