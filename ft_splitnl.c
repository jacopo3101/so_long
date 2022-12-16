/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javellis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:45:07 by javellis          #+#    #+#             */
/*   Updated: 2022/12/14 18:14:15 by javellis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<malloc.h>
#include<stdio.h>
#include<unistd.h>

int	check_separator(char c)
{
	if (c == '\n')
		return (1);
	else
		return (0);
}

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (!check_separator(str[i]))
	{
		i++;
	}
	return (i);
}

int	word_count(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (check_separator(str[i]) && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			count++;
		while (!check_separator(str[i]) && str[i] != '\0')
			i++;
	}
	return (count);
}

char	*word_builder(char *str)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(ft_strlen(str) + 1);
	while (check_separator(str[i]) && str[i] != '\0')
		i++;
	while (!check_separator(str[i]) && str[i] != '\0')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_splitnl(char *str)
{
	char	**result;
	int		count;

	count = 0;
	result = malloc(sizeof(char *) * (word_count(str) + 2));
	while (*str != '\0')
	{
		while (check_separator(*str) && *str != '\0')
			str++;
		if (*str != '\0')
		{
			result[count] = word_builder(str);
			count++;
		}
		while (!check_separator(*str) && *str != '\0')
			str++;
	}
	result[count] = 0;
	return (result);
}
