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
	dir->path = (char *)malloc(sizeof(char) * 1024);
	dir->path = ft_strdup("./");
	dir->travel = NULL;
	dir->check_err = 0;
	/*dir->st = NULL;
	dir->tm = NULL;*/

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
	dir->path = (char *)malloc(sizeof(char) * 1024);
	dir->travel = NULL;
	dir->check_err = 0;
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
