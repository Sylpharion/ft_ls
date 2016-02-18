/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_ls2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:28:27 by smassand          #+#    #+#             */
/*   Updated: 2016/02/17 18:28:30 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char			*get_month2(char **s, int month)
{
	if (month == 7)
		*s = "Aug";
	else if (month == 8)
		*s = "Sep";
	else if (month == 9)
		*s = "Oct";
	else if (month == 10)
		*s = "Nov";
	else if (month == 11)
		*s = "Dec";
	return (*s);
}

char			*get_month(int month)
{
	char		*s;

	s = ft_strnew(3);
	if (month == 0)
		s = "Jan";
	else if (month == 1)
		s = "Feb";
	else if (month == 2)
		s = "Mar";
	else if (month == 3)
		s = "Apr";
	else if (month == 4)
		s = "May";
	else if (month == 5)
		s = "Jun";
	else if (month == 6)
		s = "Jul";
	else if (month > 6 && month <= 12)
		s = get_month2(&s, month);
	return (s);
}

void			aff_date(struct tm tm)
{
	char		*s;

	s = ft_strnew(13);
	ft_strcat(s, get_month(tm.tm_mon));
	ft_strcat(s, "\t");
	ft_strcat(s, ft_itoa(tm.tm_mday));
	ft_strcat(s, "\t");
	if (((double)tm.tm_hour / 10) < 1)
		ft_strcat(s, ft_itoa(0));
	ft_strcat(s, ft_itoa(tm.tm_hour));
	ft_strcat(s, ":");
	if (((double)tm.tm_min / 10) < 1)
		ft_strcat(s, ft_itoa(0));
	ft_strcat(s, ft_itoa(tm.tm_min));
	ft_strcat(s, "\t");
	ft_putstr(s);
	free(s);
}

void			aff_ls(t_dir dir)
{
		stat(dir.fichierlu->d_name, &dir.st);
		dir.t = dir.st.st_mtime;
		dir.tm = *localtime(&dir.t);
		aff_mode(dir.st);
		aff_id(dir.pwd, dir.grp, dir.st);
		aff_size(dir.st);
		aff_date(dir.tm);
		aff_name(dir.fichierlu);
}