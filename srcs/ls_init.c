/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 00:29:18 by smassand          #+#    #+#             */
/*   Updated: 2016/02/13 00:31:14 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void		ft_init(t_dir *dir, t_param *param, t_args *args)
{
	dir->rep = NULL;
	dir->file = NULL;
	dir->pwd = NULL;
	dir->grp = NULL;
	dir->init_mode = ft_strnew(11);
	dir->path = (char *)malloc(sizeof(char) * 5);
	dir->path = ft_strdup("./");
	dir->travel = NULL;
	dir->check_opt = 0;
	dir->check_err = 0;

	param->mode = NULL;
	param->link = 0;
	param->usr = NULL;
	param->grp = NULL;
	param->size = 0;
	param->date = NULL;
	param->name = NULL;

	args->l = 0;
	args->R = 0;
	args->a = 0;
	args->r = 0;
	args->t = 0;
	args->un = 0;
	args->argcpy = 0;
	args->argvpy = NULL;
}

void		ft_init_recurs(t_param *param, t_dir *dir)
{
	param->mode = NULL;
	param->link = 0;
	param->usr = NULL;
	param->grp = NULL;
	param->size = 0;
	param->date = NULL;
	param->name = NULL;

	dir->rep = NULL;
	dir->file = NULL;
	dir->pwd = NULL;
	dir->grp = NULL;
	dir->init_mode = ft_strnew(11);
	dir->path = NULL;
	dir->travel = NULL;
	dir->check_err = 0;
	dir->check_opt = 0;
}

void		ft_init_param(t_param *param)
{
	param->mode = NULL;
	param->link = 0;
	param->usr = NULL;
	param->grp = NULL;
	param->size = 0;
	param->date = NULL;
	param->name = NULL;
}

void		ls_err(t_dir dir, char *s)
{
	if (errno)
		dir.check_err = errno;
	ft_putstr("ft_ls: ");
	ft_putstr(s);
	if (dir.check_err == EACCES)
		ft_putstr(": Permission denied\n");
	else if (dir.check_err == EBADF)
		ft_putstr(": Bad file descriptor\n");
	else if (dir.check_err == EMFILE)
		ft_putstr(": Too many file descriptors in use by process\n");
	else if (dir.check_err == ENFILE)
		ft_putstr(": Too many files are currently open in the system\n");
	else if (dir.check_err == ENOENT)
		ft_putstr(": No such file or directory\n");
	else if (dir.check_err == ENOMEM)
		ft_putstr(": Insufficient memory to complete the operation\n");
	else if (dir.check_err == ENOTDIR)
		ft_putstr(": is not a directory\n");
	else
		exit(1);
	exit(1);
}
