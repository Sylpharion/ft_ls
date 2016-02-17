/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:10:42 by smassand          #+#    #+#             */
/*   Updated: 2016/02/17 18:28:22 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			aff_mode2(struct stat st, int i)
{
	char 		*s;

	s = ft_strnew(11);
	while(i-- > 0)
    	s[i] = '-';
	if (st.st_mode & S_IRUSR)
		s[0] = 'r';
	if (st.st_mode & S_IWUSR)
		s[1] = 'w';
	if (st.st_mode & S_IXUSR)
		s[2] = 'x';
	if (st.st_mode & S_IRGRP)
		s[3] = 'r';
	if (st.st_mode & S_IWGRP)
    	s[4] = 'w';
	if (st.st_mode & S_IXGRP)
    	s[5] = 'x';
	if (st.st_mode & S_IROTH)
    	s[6] = 'r';
	if (st.st_mode & S_IWOTH)
    	s[7] = 'w';
	if (st.st_mode & S_IXOTH)
    	s[8] = 'x';
	ft_putstr(s);
	free(s);
}

void			aff_mode(struct stat st)
{
	char		c;

	c = '-';
	if (S_ISBLK(st.st_mode))
		c = 'b';
	else if (S_ISCHR(st.st_mode))
		c = 'c';
	else if ((S_ISDIR(st.st_mode) == 1))
		c = 'd';
	else if (S_ISFIFO(st.st_mode))
		c = 'p';
	else if (S_ISLNK(st.st_mode))
		c = 's';
	else if (S_ISSOCK(st.st_mode))
		c = 'l';
	ft_putchar(c);
	aff_mode2(st, 9);
	ft_putchar('\t');
	ft_putnbr(st.st_nlink);
	ft_putchar('\t');
}

void			aff_name(struct dirent *fichierlu)
{
	ft_putstr(fichierlu->d_name);
	ft_putchar('\n');
}

void			aff_id(struct passwd *pwd, struct group *grp, struct stat st)
{
	if ((pwd = getpwuid(st.st_uid)) != NULL)
		ft_putstr(pwd->pw_name);
	ft_putchar('\t');
	if ((grp = getgrgid(st.st_gid)) != NULL)
		ft_putstr(grp->gr_name);
	ft_putchar('\t');
}

void			aff_size(struct stat st)
{
	ft_putnbr(st.st_size);
	ft_putchar('\t');
}
