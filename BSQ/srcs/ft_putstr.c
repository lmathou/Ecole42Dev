/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 14:13:24 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/17 16:06:26 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	ft_putstr(char *str)
{
	char		*ctr;

	ctr = str;
	while (*ctr != '\0')
	{
		ft_putchar(*ctr);
		ctr++;
	}
}