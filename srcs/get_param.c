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

char			*get_mode(struct stat st, t_dir *dir)
{
	if (S_ISBLK(st.st_mode))
		dir->init_mode[0] = 'b';
	else if (S_ISCHR(st.st_mode))
		dir->init_mode[0] = 'c';
	else if (S_ISDIR(st.st_mode) == 1)
		dir->init_mode[0] = 'd';
	else if (S_ISFIFO(st.st_mode))
		dir->init_mode[0] = 'p';
	else if (S_ISLNK(st.st_mode))
		dir->init_mode[0] = 's';
	else if (S_ISSOCK(st.st_mode))
		dir->init_mode[0] = 'l';
	else
		dir->init_mode[0] = '-';
	dir->init_mode[1] = (st.st_mode & S_IRUSR)? 'r' : '-';
	dir->init_mode[2] = (st.st_mode & S_IWUSR)? 'w' : '-';
	dir->init_mode[3] = (st.st_mode & S_IXUSR)? 'x' : '-';
	dir->init_mode[4] = (st.st_mode & S_IRGRP)? 'r' : '-';
  	dir->init_mode[5] = (st.st_mode & S_IWGRP)? 'w' : '-';
    dir->init_mode[6] = (st.st_mode & S_IXGRP)? 'x' : '-';
    dir->init_mode[7] = (st.st_mode & S_IROTH)? 'r' : '-';
    dir->init_mode[8] = (st.st_mode & S_IWOTH)? 'w' : '-';
    dir->init_mode[9] = (st.st_mode & S_IXOTH)? 'x' : '-';
    return (dir->init_mode);
}

void		get_param(t_dir dir, t_param *param)
{
	stat(dir.fichierlu->d_name, &dir.st);
	dir.t = dir.st.st_mtime;
	dir.tm = *localtime(&dir.t);
	param->mode = get_mode(dir.st, &dir);
	param->link = dir.st.st_nlink;
	param->usr = ((dir.pwd = getpwuid(dir.st.st_uid)) != NULL)?
					dir.pwd->pw_name : NULL;
	param->grp = ((dir.grp = getgrgid(dir.st.st_gid)) != NULL)?
					dir.grp->gr_name : NULL;
	param->size = dir.st.st_size;
	param->date = get_date(dir.tm);
	param->name = dir.fichierlu->d_name;
}

void		aff_param(t_param param)
{
	ft_putchar('\n');
	ft_putstr(param.mode);
	ft_putchar('\t');
	ft_putnbr(param.link);
	ft_putchar('\t');
	ft_putstr(param.usr);
	ft_putchar('\t');
	ft_putstr(param.grp);
	ft_putchar('\t');
	ft_putnbr(param.size);
	ft_putchar('\t');
	ft_putstr(param.date);
	ft_putchar('\t');
	ft_putstr(param.name);
}