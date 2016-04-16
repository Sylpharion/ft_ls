/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smassand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:56:57 by smassand          #+#    #+#             */
/*   Updated: 2016/02/23 19:57:13 by smassand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ls.h"

void		aff_ls(t_param param, t_args args, t_dir *dir, char *s)
{
	dir->rep = opendir(s);
	if (dir->rep == NULL)
	{
		ls_err(*dir, s);
		return ;
	}
	rewinddir(dir->rep);
	ft_init_sort(dir, args);
	if ((dir->file = readdir(dir->rep)) != NULL)
	{
		//get_param(dir, &param, s);
		sort_param(&param, dir, args, s);
		 // aff_param(param, args);
	}
	//if (args.r == 1 || args.t == 1)
	aff_sort_param(dir, 0, 0, args);
	free(dir->tab_sort);
	free(dir->tab_tmp);
	rewinddir(dir->rep);
	ft_putstr("\n\n");
	while ((args.R == 1) && ((dir->file = readdir(dir->rep)) != NULL))
		aff_ls_r(args, *dir, s);
	closedir(dir->rep);
}

void		sort_param(t_param *param, t_dir *dir, t_args args, char *s)
{
	rewinddir(dir->rep);
	get_sort(param, dir, s, args);
	ft_sort_ascii(dir);
	if (args.t == 1)
		ft_sort_time(dir);
	if (args.r == 1)
		ft_sort_reverse(dir, args);
}

void		ft_sort_ascii(t_dir *dir)
{
	int 	i;
	int 	j;
	int 	k;
	char 	*t;
	char	**tmp;
	int 	ordre;
	
	i = 0;
	ordre = 0;
	tmp = (char **)malloc(sizeof(char *) * dir->nb_file_a);
	j = dir->nb_file_a;
	t = ft_strnew(64);


	while (i < dir->nb_file_a)
	{
		tmp[i] = ft_strnew(64);
		i++;
	}

	i = 0;
	while (i < dir->nb_file_a)
	{
		tmp[i] = ft_strdup(dir->tab_tmp[i][6]);
		i++;
	}
	
	i = 0;
	while (i < dir->nb_file_a)//ordre == 0)
	{
		k = 0;
		//ordre = 1;
		while (k < j - 1)
		{
			if (strcmp(tmp[k], tmp[k + 1]) > 0)
			{				
				t = tmp[k];
				tmp[k] = tmp[k + 1];
				tmp[k + 1] = t;
				//ordre = 0;
			}
			k++;
		}
		j--;
		i++;
	}

	i = 0;
	while (i < dir->nb_file_a)
	{
		j = 0;
		while (dir->tab_tmp[j] && ft_strcmp(dir->tab_tmp[j][6], tmp[i]) != 0)
			j++;
		dir->tab_sort[i] = dir->tab_tmp[j];
		if (dir->tab_tmp[j] == NULL)
			dir->tab_sort[i] = dir->tab_tmp[j - 1];
		if (dir->tab_sort[i] == NULL)
			return ;
			//printf("dafuq %d %d\n", i, j);
		i++;
	}
	// i = -1;
	// while (dir->tab_sort[++i])
	// {
	// 	j = -1;
	// 	while (dir->tab_sort[i][++j])
	// 		printf("%s ", dir->tab_sort[i][j]);
	// 	printf("\n");
	// }
	free(dir->tab_tmp);
	dir->tab_tmp = tab_init(dir);
	i = 0;
	while (i < dir->nb_file_a)
	{
		dir->tab_tmp[i] = dir->tab_sort[i];
		i++;
	}
	
}

void		aff_param(t_param param, t_args args)
{
	if (args.l == 1)
	{
		ft_putchar('\n');
		ft_putstr(param.mode);
		ft_putchar('\t');
		ft_putnbr(param.link);
		ft_putchar('\t');
		ft_putstr(param.usr);
		ft_putchar('\t');
		ft_putstr(param.grp);
		ft_putchar('\t');
		ft_putnbr(param.size);
		ft_putchar('\t');
		ft_putstr(param.date);
		ft_putchar('\t');
	}
	ft_putstr(param.name);
	if (args.un == 1 && args.l == 0)
		ft_putchar('\n');
	else
		ft_putchar('\t');
}

void		aff_ls_r(t_args args, t_dir dir, char *s)
{
	char	*s2;
	t_param	param2;

	ft_init_param(&param2);
	get_param(&dir, &param2, s);
	if (param2.mode[0] == 'd')
	{
		if (((param2.name[0] != '.' && param2.name[1] != '.'))
			|| (param2.name[0] == '.' && param2.name[1] != '/'
				&& param2.name[1] && param2.name[1] != '.' && args.a == 1))
			{
				s2 = ft_strnew(ft_strlen(s) + ft_strlen(param2.name) + 3);
				s2 = ft_strcat(s2, s);
				if (s[ft_strlen(s) - 1] != '/')
					s2 = ft_strjoin(s2, "/");
				s2 = ft_strjoin(s2, param2.name);
				ft_putstr(s2);
				ft_putstr(":\n");
				s2 = ft_strjoin(s2, "/");
				aff_ls(param2, args, &dir, s2);
				free(s2);
			}
	}
}
