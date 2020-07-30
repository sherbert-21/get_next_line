/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 23:25:45 by sherbert          #+#    #+#             */
/*   Updated: 2020/07/26 23:25:55 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char			*ft_strdup(char *s, int *ret)
{
	char	*str;
	char	*ptr;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (!(str = (char*)malloc((i + 1) * sizeof(char))))
	{
		*ret = -1;
		return (NULL);
	}
	ptr = str;
	while (*s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (str);
}

char			*ft_strjoin(char *s1, char *s2, int *ret)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
	{
		*ret = -1;
		return (NULL);
	}
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char			*ft_strcpy(char *dest, char *src)
{
	int			i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void			ft_strclr(char *s)
{
	if (s)
		while (*s)
			*s++ = '\0';
}
