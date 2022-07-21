/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 19:19:18 by mde-cloe      #+#    #+#                 */
/*   Updated: 2022/07/19 19:19:34 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char *line = get_next_line(fd);
	for (int i = 0; i < 20; i++)
	{
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	}
	close(fd);
	return 0;
}
