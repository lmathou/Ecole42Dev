/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:44:56 by jblancha          #+#    #+#             */
/*   Updated: 2016/12/22 23:31:42 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_field		**field;
	t_env		env;
	int			ret;

	if (argc != 2)
	{
		ft_putendl("./fdf <file_name>");
		return (0);
	}
	if ((field = ft_read_file(argv[1])) == NULL)
	{
		ft_freefield(field);
		ft_putendl("error");
		return (0);
	}
	if ((ret = ft_init_field(&env, field)) == -1)
		ft_freememory(&env);
	ft_init_mlx(&env);
	mlx_expose_hook(env.window, ft_expose_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
