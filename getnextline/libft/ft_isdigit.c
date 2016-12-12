/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:09:41 by jblancha          #+#    #+#             */
/*   Updated: 2016/11/15 18:34:10 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int ctr)
{
	if (ctr >= '0' && ctr <= '9')
		return (1);
	else
		return (0);
}