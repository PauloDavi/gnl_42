/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:41:05 by vscode            #+#    #+#             */
/*   Updated: 2023/05/29 06:58:42 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;
	char	*line;

	fd = open("./test/test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erro ao abrir o arquivo.\n");
		return (1);
	}
	fd2 = open("./test/test2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erro ao abrir o arquivo 2.\n");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd2);
	printf("%s", line);
	close(fd);
	return (0);
}
