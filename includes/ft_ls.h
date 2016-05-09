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
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

typedef struct		s_dir
{
	int				nb_file;
	int				nb_file_a;
	DIR				*rep;
	time_t			t;
	int				t_init;
	struct dirent	*file;
	struct stat		st;
	struct tm		tm;
	struct passwd	*pwd;
	struct group	*grp;
	char			*init_mode;
	char			*path;
	int				check_opt;
	char			**travel;
	int				check_err;
	int				check_travel;
	int				check_args;
	char			***tab_sort;
	char			***tab_tmp;
}					t_dir;

typedef struct		s_param
{
	char			*mode;
	int				link;
	char			*usr;
	char			*grp;
	int				size;
	char			*date;
	char			*name;
	int				block;
}					t_param;

typedef struct		s_args
{
	int				l;
	int				recurs;
	int				a;
	int				r;
	int				t;
	int				f;
	int				o;
	int				g;
	int				p;
	int				un;
}					t_args;

void				verif_ls(t_param param, t_dir dir, t_args args);
void				verif_ls_sort(t_param param, t_dir dir, t_args args);

void				aff_ls(t_param param, t_args args, t_dir *dir, char *s);
void				aff_ls2(t_dir *dir, t_param param, t_args args, char *s);
void				aff_ls_r(t_args args, t_dir dir, char *s);
void				aff_param(t_param param, t_args args, char *s, int j);
int					aff_param2(int i, char *s);
void				aff_param_l(t_param param, t_args args);

void				aff_sort_param(t_dir *dir, int j, t_args args, char *path);
void				aff_sort_param2(t_dir *dir, char *path, int i);
void				aff_toto(t_dir *dir, t_args args);
void				aff_sort_param_l(t_dir *dir, int i, t_args args);

void				sort_param(t_param *param, t_dir *dir, t_args args,
								char *s);
int					ft_toto(t_dir *dir, t_args args);
void				ft_sort_ascii(t_dir *dir, int i, int j);
void				ft_sort_ascii2(int i, t_dir *dir, int j, char **tmp);
void				ft_sort_ascii3(int i, t_dir *dir, char **tmp, int j);
void				ft_sort_time(t_dir *dir, int i, int tmp, int j);
int					**ft_sort_time2(t_dir *dir);
void				ft_sort_time3(t_dir *dir, int **t, int i, int j);
void				ft_sort_reverse(t_dir *dir, t_args args);

void				ls_err(t_dir dir, char *s);
void				ft_free_tmp(t_dir *dir);

void				get_args(t_args *args, char **argv, int j);
void				get_args2(t_args *args, char **argv, int i, int j);
void				get_args3(t_args *args, char **argv, int i, int j);
char				**get_args_sup(char **argv, int argc, int j, t_dir *dir);
void				get_param(t_dir *dir, t_param *param, char *s);
char				*get_mode(struct stat st, t_dir *dir);
char				*get_date(struct tm tm, t_dir *dir);
char				*get_month(int month);
char				*get_month2(char **s, int month);
void				get_sort(t_param *param, t_dir *dir, char *s, int i);
void				get_time(t_dir *dir, int **t);

void				ft_init(t_dir *dir, t_param *param, t_args *args);
void				ft_init_sort(t_dir *dir, t_args args);
void				ft_init_args(t_args *args, char **argv, int argc,
									t_dir *dir);
void				ft_init_recurs(t_param *param, t_dir *dir);
void				ft_init_param(t_param *param);
char				***tab_init(t_dir *dir);

#endif
