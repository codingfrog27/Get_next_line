/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/31 19:19:25 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/07/22 22:13:09 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*buff_to_line(char *buff, char *line)
{
	size_t	line_len;
	size_t	buff_end;
	char	*line2;

	line_len = nl_strlen(line, false);
	buff_end = nl_strlen(buff, true);
	if (!buff_end)
		buff_end = nl_strlen(buff, false) + 1;
	line2 = stralloc(buff_end + line_len + 1);
	if (!line2)
		return (NULL);
	strcopycat(line2, line, buff, buff_end);
	free(line);
	return (line2);
}

void	buff_update(char *buff)
{
	size_t	i;
	size_t	nl_len;
	size_t	bufflen;

	i = 0;
	nl_len = nl_strlen(buff, true);
	bufflen = nl_strlen(buff, false);
	if (buff[nl_len] == '\0')
	{
		while (i < BUFFER_SIZE)
		{
			buff[i] = '\0';
			i++;
		}
		return ;
	}
	while (i <= bufflen - nl_len)
	{
		buff[i] = buff[nl_len + i];
		i++;
	}
	buff[i] = '\0';
}

//wish functions could take 5 args, then i wouldnt need to strlen again

void	strcopycat(char *dst, char *cpysrc, char *catsrc, \
size_t catlen)
{
	size_t	cpylen;
	size_t	i;
	size_t	j;

	cpylen = nl_strlen(cpysrc, false);
	i = 0;
	j = 0;
	while (i < cpylen)
	{
		dst[i] = cpysrc[i];
		i++;
	}
	while (j < catlen)
	{
		dst[i + j] = catsrc[j];
		j++;
	}
}

//returns the index AFTER \n when used for newline
size_t	nl_strlen(char *str, bool stop_at_nl)
{
	size_t	len;

	len = 0;
	if (stop_at_nl == true)
	{
		while (str[len])
		{
			if (str[len] == '\n')
				return (len + 1);
			len++;
		}
		return (0);
	}
	while (str[len])
		len++;
	return (len);
}

char	*stralloc(size_t space)
{
	char	*str;
	size_t	i;

	if (!space)
		space = 1;
	str = malloc(space * sizeof(char));
	i = 0;
	if (!str)
		return (NULL);
	while (i < space)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}