/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 17:44:22 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/22 21:08:48 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUF_SIZE 4096 
#include <stdlib.h>
#include <string.h>
#include "header.h"

int			gc(char *str)
{
	char	*str1;
	int		i;

	i = 0;
	str1 = str;
	while (*str1 != '\0' && *str1 != '\n')
	{
		i++;
		str1++;
	}
	return (i);
}

int			gl(char *str)
{
	char	*str1;
	int		i;

	i = 0;
	str1 = str;
	while (*str1 != '\0')
	{
		if (*str1 == '\n')
		{
			i++;
		}
		str1++;
	}
	return (i);
}

char		*ft_get_stdin(void)
{
	int		ret;
	int		total_size;
	char	buf[BUF_SIZE + 1];
	char	*final;
	char	*tmp;

	total_size = 0;
	final = (char *)malloc(sizeof(char) * 1);
	if (!final)
	{
		printf("Error Allocating Memory for final\n");
		return (NULL);
	}
	*final ='\0';
	while ((ret = read(0, buf, BUF_SIZE)) > 0)
	{
		tmp = (char *)malloc(sizeof(char) * ft_strlen(final));
		if (!tmp)
		{
			printf("Error Allocating Memory for tmp\n");
			return (NULL);
		}
		ft_strcpy(tmp, final);
		//if (final)
		//{
		//	ft_putstr("Avant final\n");
		//	free(final);
		//}
		buf[ret] = '\0';
		total_size = total_size + ret;
		//final = (char *)malloc(sizeof(char) * total_size);
		//if (!final)
		//{
		//	printf("Error Allocating Memory for final\n");
		//	return (NULL);
		//}
		final = ft_strcat(tmp, buf);
		if (tmp)
		{
			ft_putstr("Avant tmp\n");
			free(tmp);
		}
	}
	return (final);
}

void		printoutput(char *str, int nblignes, int nbcol, int p)
{
	if (p > 1)
		write(1, " || ", 4);
	ft_putstr(str);
	ft_putstr(" [");
	ft_putnbr(nblignes);
	ft_putstr("] [");
	ft_putnbr(nbcol);
	ft_putstr("]");
}

int			main(void)
{
	char	*input;
	char	*str;
	int		p;

	input = ft_get_stdin();
	if (!input)
		ft_putstr("erreur memoire\n");
	p = 0;
	str = colle00(gc(input), gl(input));
	if (ft_strcmp(input, str) == 0)
		printoutput("[colle-00]", gc(input), gl(input), ++p);
	str = colle01(gc(input), gl(input));
	if (ft_strcmp(input, str) == 0)
		printoutput("[colle-01]", gc(input), gl(input), ++p);
	str = colle02(gc(input), gl(input));
	if (ft_strcmp(input, str) == 0)
		printoutput("[colle-02]", gc(input), gl(input), ++p);
	str = colle03(gc(input), gl(input));
	if (ft_strcmp(input, str) == 0)
		printoutput("[colle-03]", gc(input), gl(input), ++p);
	str = colle04(gc(input), gl(input));
	if (ft_strcmp(input, str) == 0)
		printoutput("[colle-04]", gc(input), gl(input), ++p);
	if (p == 0)
		ft_putstr("aucune");
	ft_putstr("\n");
	return (0);
}
