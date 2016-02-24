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
	char			*init_mode;
	char			*path;
}					t_dir;

typedef struct 		s_param
{
	char			*mode;
	int 			link;
	char			*usr;
	char			*grp;
	int 			size;
	char			*date;
	char			*name;
}					t_param;

typedef struct 		s_args
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
	int 			un;
}					t_args;

void			aff_ls(t_param param, t_args args, t_dir dir, char *s);
void			aff_lsd(t_args args, t_dir dir, char *s);
void			get_param(t_dir dir, t_param *param);
void			aff_param(t_param param, t_args args);
void			aff_param2(t_param param, t_args args);
char			*get_mode(struct stat st, t_dir *dir);
char			*get_date(struct tm tm);
char			*get_month(int month);
char			*get_month2(char **s, int month);

void			get_args(t_args *args, char **argv, t_dir *dir);
void			get_args2(t_args *args, char **argv, int i);

void			ft_init(t_dir *dir, t_param *param, t_args *args);
void			ft_init_param(t_param *param);

#endif