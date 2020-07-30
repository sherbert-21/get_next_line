/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sherbert <sherbert@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 23:25:51 by sherbert          #+#    #+#             */
/*   Updated: 2020/07/26 23:25:54 by sherbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char*)str);
		str++;
	}
	if (*str == (unsigned char)c)
		return ((char*)str);
	return (NULL);
}

static void		save_buf(char *s_buf, int *ret, int *if_s, char **line)
{
	char		*n;

	*ret = 1;
	if ((n = ft_strchr(s_buf, '\n')))
		*n++ = '\0';
	*line = ft_strdup(s_buf, ret);
	(n) ? ft_strcpy(s_buf, n) : ft_strclr(s_buf);
	*if_s = (n) ? 1 : 0;
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*s_buf;
	char		*n;
	int			ret;
	static int	if_s;

	ret = (fd < 0 || BUFFER_SIZE < 1 || !line) ? -1 : 0;
	if (if_s == 1)
		save_buf(s_buf, &ret, &if_s, line);
	while (ret != -1 && if_s != 1 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((n = ft_strchr(buf, '\n')))
		{
			*n++ = '\0';
			s_buf = ft_strdup(n, &ret);
		}
		*line = ft_strjoin(*line, buf, &ret);
		if_s = (n) ? 1 : 0;
	}
	ret = (ret >= 1) ? 1 : ret;
	return (ret);
}
