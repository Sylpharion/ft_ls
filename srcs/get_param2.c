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

char			*get_month(int month)
{
	char		**s;
	int 		i;

	i = 0;
	s = (char **)malloc(sizeof(char *) * 12);
	while (i < 12)
	{
		s[i] = ft_strnew(3);
		i++;
	}
	s[0] = "Jan";
	s[1] = "Feb";
	s[2] = "Mar";
	s[3] = "Apr";
	s[4] = "May";
	s[5] = "Jun";
	s[6] = "Jul";
	s[7] = "Aug";
	s[8] = "Sep";
	s[9] = "Oct";
	s[10] = "Nov";
	s[11] = "Dec";
	return (s[month]);
}

char			*get_date(struct tm tm)
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
	return (s);
	free(s);
}
