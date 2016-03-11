/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 15:05:32 by smassand          #+#    #+#             */
/*   Updated: 2016/02/11 15:05:37 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

int			main(int argc, char **argv)
{
	t_dir	dir;
	t_param	param;
	t_args	args;

	ft_init(&dir, &param, &args);
	if (argc > 1)
		get_args(&args, argv, argc, &dir);	
	dir.rep = opendir(dir.path);
	if (dir.rep == NULL)
		ls_err(dir, dir.path);
	aff_ls(param, args, &dir, dir.path);
	return (0);
}

void		ls_err(t_dir dir, char *s)
{
	dir.check_err = errno;
	ft_putstr("ft_ls: ");
	ft_putstr(s);
	if (dir.check_err == EACCES)
		ft_putstr(": Permission denied\n");
	else if (dir.check_err == EBADF)
		ft_putstr(": is not a valid file descriptor opened for reading\n");
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
	else if (dir.rep == NULL && ((s && (s[0] != '-')) ||
		(ft_strcmp(s, "-") == 0)))
		ft_putstr(": No such file or directory\n");
	exit(1);
}
