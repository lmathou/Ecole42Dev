/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 17:39:20 by jblancha          #+#    #+#             */
/*   Updated: 2016/09/13 21:26:03 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_sort_wordtab(char **tab);
void    ft_advanced_sort_wordtab(char **tab, int(*cmp)(char *, char *));
int     ft_strcmp(char *s1, char *s2);

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char		**create_tableau(char **tab, char *str)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			nb_words++;
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
		}
	}
	if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		nb_words++;
	tab = (char**)malloc(sizeof(*tab) * (nb_words + 1));
	tab[nb_words] = 0;
	return (tab);
}

char		**create_chaque_mot(char **tab, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0')
		{
			tab[j] = (char*)malloc(sizeof(**tab) * (k + 1));
			j++;
			k = 0;
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
		}
		k++;
	}
	return (tab);
}

char		**fill_tableau(char **tab, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		tab[j][k] = str[i];
		i++;
		k++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			tab[j][k] = '\0';
			j++;
			k = 0;
			while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
				i++;
		}
	}
	return (tab);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;

	tab = NULL;
	tab = create_tableau(tab, str);
	tab = create_chaque_mot(tab, str);
	tab = fill_tableau(tab, str);
	return (tab);
}

int		main(void)
{
	char	*phrase = " n  y  un  \tis hello  \nworld";
	char	**table = ft_split_whitespaces(phrase);
	int		j;
	int		k;

	j = 0;
	k = 0;
	printf("%s\n", phrase);
		while (table [j] != 0)
		{
			printf("%s\n", table[j]);
			j++;
		}
	ft_advanced_sort_wordtab(table, &ft_strcmp);
	j = 0;
		while (table [j] != 0)
		{
			printf("%s\n", table[j]);
			j++;
		}
	return (0);
}
