/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:37:07 by agraille          #+#    #+#             */
/*   Updated: 2024/11/08 15:25:32 by agraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *s, char c, int i)
{
	if (s[i] == c)
		return (1);
	return (0);
}

static int	ft_count_word(const char *s, char c)
{
	int	count_word;
	int	seek;
	int	i;

	count_word = 0;
	seek = 1;
	i = 0;
	while (s[i])
	{
		if (ft_check(s, c, i) == 1 && seek == 0)
		{
			seek = 1;
		}
		if (ft_check(s, c, i) == 0 && seek == 1)
		{
			count_word += 1;
			seek = 0;
		}
		i++;
	}
	return (count_word);
}

static char	*ft_copy(int i, const char *s, char c)
{
	char	*copy;
	int		j;
	int		len;
	int		end;

	end = i;
	while (!ft_check(s, c, end) && s[end])
		end++;
	j = 0;
	len = end - i;
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	while (i < end)
		copy[j++] = s[i++];
	copy[j] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	int		i;
	int		j;
	char	**split;

	i = 0;
	word = 1;
	j = 0;
	split = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (split == NULL)
		return (NULL);
	while (s[i])
	{
		if (word == 1 && !ft_check(s, c, i))
		{
			split[j] = ft_copy(i, s, c);
			j++;
			word = 0;
		}
		else if (word == 0 && ft_check(s, c, i))
			word = 1;
		i++;
	}
	split[j] = 0;
	return (split);
}

// #include <unistd.h>

// int	main(void)
// {
// 	char	*str = "loremreuismodnon,mi.";
// 	char 	charset = ' ';
// 	int	i = 0;
// 	int	k = 0;
// 	char	**tab;
// 	tab = ft_split(str,charset);
// 	while (tab[i] != 0)
// 	{
// 		k = 0;
// 		while (tab[i][k] != '\0')
// 		{
// 			write(1,&tab[i][k], 1);
// 			k++;
// 		}
// 		write(1, "\n",1);
// 		free(tab[i]);
// 		i++;
// 	}	
// 	free(tab);
// }