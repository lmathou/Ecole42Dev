/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:13:24 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/07 17:47:14 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	if (argc == 0)
	{
		return(0);
	}
	while (*argv[0] != '\0')
	{
		ft_putchar(*argv[0]);
		argv[0]++;
	}
	ft_putchar('\n');
	return (0);
}
