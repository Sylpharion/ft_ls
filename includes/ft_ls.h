/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:05:18 by smassand          #+#    #+#             */
/*   Updated: 2016/02/11 15:05:22 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
//# include <attr/xattr.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct 		s_dir
{
	int				curseur;
	DIR 			*rep;
	time_t 			t;
	struct dirent 	*fichierlu;
	struct stat		st;
	struct tm 		tm;
	struct passwd 	*pwd;
	struct group 	*grp;
}					t_dir;

void			aff_ls(t_dir dir);
void			aff_size(struct stat st);
void			aff_name(struct dirent *fichierlu);
void			aff_id(struct passwd *pwd, struct group *grp, struct stat st);
void			aff_mode(struct stat st);
void			aff_mode2(struct stat st, int i);
void			aff_date(struct tm tm);
char			*get_month(int month);
char			*get_month2(char **s, int month);

void			ft_init(t_dir *dir);

#endif