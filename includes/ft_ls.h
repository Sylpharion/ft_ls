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
	struct dirent 	*file;
	struct stat		st;
	struct tm 		tm;
	struct passwd 	*pwd;
	struct group 	*grp;
	char			*init_mode;
	char			*path;
	int 			check_opt;
	char			**travel;
	int 			check_err;
	int				check_travel;
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

/*
 rappel :
 -- ok
 *
 l  ok
 R  ok
 a  ok
 r
 t
 1  ok
*/

void			verif_ls(t_param param, t_dir dir, t_args args);
void			aff_ls(t_param param, t_args args, t_dir *dir, char *s);
void			aff_ls_r(t_args args, t_dir dir, char *s);
void			get_param(t_dir *dir, t_param *param, char *s);
void			aff_param(t_param param, t_args args);
void			aff_param2(t_param param, t_args args);
char			*get_mode(struct stat st, t_dir *dir);
char			*get_date(struct tm tm);
char			*get_month(int month);
char			*get_month2(char **s, int month);

void			ls_err(t_dir dir, char *s);

void			get_args(t_args *args, char **argv, int j);
void			get_args2(t_args *args, char **argv, int i, int j);
char			**get_args_sup(char **argv, int argc, int j);

void			ft_init(t_dir *dir, t_param *param, t_args *args);
void			init_args(t_args *args, char **argv, int argc, t_dir *dir);
void			ft_init_recurs(t_param *param, t_dir *dir);
void			ft_init_param(t_param *param);

#endif