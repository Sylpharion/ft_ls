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
	//ft_verif(&dir, &param, args, argc, argv);
	if (argc > 1)
		ft_init_args(&args, argv, argc, &dir);
	if (argc > 2)
	{
		if (args.r == 1 || args.t == 1)
			verif_ls_sort(param, dir, args);
		else
			verif_ls(param, dir, args);
	}
	else
		aff_ls(param, args, &dir, dir.path);
	return (0);
}

// void		ft_verif(t_dir *dir, t_param *param, t_args args, int argc, char **argv)
// {
// 	int		i;

// 	i = 0;
// 	while (i < argc - 1)
// 	{
// 		if (argv[i][0] != '-')
// 		{
// 			lstat(argv[i], &dir->st);
// 			dir->t = dir->st.st_mtime;
// 			dir->tm = *localtime(&dir->t);
// 			param->mode = get_mode(dir->st, dir);
// 			param->link = dir->st.st_nlink;
// 			param->usr = ((dir->pwd = getpwuid(dir->st.st_uid)) != NULL)?
// 						dir->pwd->pw_name : NULL;
// 			param->grp = ((dir->grp = getgrgid(dir->st.st_gid)) != NULL)?
// 						dir->grp->gr_name : NULL;
// 			param->size = dir->st.st_size;
// 			param->date = get_date(dir->tm, dir);
// 			param->name = dir->file->d_name;
// 			if (param->mode[0] != 'd')
// 				aff_param(*param, args);
// 		}
// 		i++;
// 	}
// }
