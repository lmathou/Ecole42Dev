/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:01:47 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/23 21:25:48 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_printlists(t_lists *lst)
{
	if (lst)
	{
		while (lst)
		{
			ft_putendl(lst->src);
			lst = lst->next;
		}
	}
}
