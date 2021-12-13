/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:45:44 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/12/13 17:26:57 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ogstri starts at -1 for line limit reasons
*/
#include "libft.h"
#include <stdlib.h>

static int	ft_scount(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i++])
	{
		while (s[i] == c)
			i++;
		if (s[i] != 0)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_makestr(char *ogstr, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(end - start + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (start < end)
		str[i++] = ogstr[start++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	int		sstart;
	size_t	j;
	size_t	ogstri;
	char	**res;

	if (!s)
		return (NULL);
	ogstri = -1;
	j = 0;
	sstart = -1;
	res = (char **)malloc((ft_scount((char *)s, c) + 1) * sizeof(char *));
	if (!res || !s)
		return (NULL);
	while (++ogstri <= ft_strlen(s))
	{
		if (s[ogstri] != c && sstart < 0 && s[ogstri])
			sstart = ogstri;
		if ((s[ogstri] == c || !s[ogstri]) && sstart >= 0)
		{
			res[j++] = ft_makestr((char *)s, sstart, ogstri);
			sstart = -1;
		}
	}
	res[j] = 0;
	return (res);
}
