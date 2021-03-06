/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 21:15:34 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/05 22:49:50 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int		k;

	k = 25;
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if ((*s1 > *s2) || (*s2 == '\0' && *s1 != '\0'))
	{
		k = 1;
	}
	if ((*s2 > *s1) || (*s1 == '\0' && *s2 != '\0'))
	{
		k = -1;
	}
	if (*s1 == '\0' && *s2 == '\0')
	{
		k = 0;
	}
	return (k);
}
