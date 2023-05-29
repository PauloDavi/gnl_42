/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:32:54 by vscode            #+#    #+#             */
/*   Updated: 2023/05/29 07:28:55 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char				*line;
	static t_fd_list	*lst;
	t_fd_list			*current_node;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current_node = find_or_create_node(&lst, fd);
	if (current_node == NULL)
		return (NULL);
	current_node->memory = read_line_break(fd, current_node->memory);
	if (current_node == NULL)
		return (NULL);
	if (current_node->memory == NULL)
		return (NULL);
	line = get_whole_line(current_node->memory);
	if (line == NULL)
		return (NULL);
	current_node->memory = clear_memory(current_node->memory);
	return (line);
}

t_fd_list	*find_or_create_node(t_fd_list **lst, int fd)
{
	t_fd_list	*finded;
	t_fd_list	*frist;

	if (*lst != NULL)
	{
		frist = *lst;
		while (1)
		{
			if ((*lst)->fd == fd)
				return (*lst);
			if ((*lst)->next == NULL)
				break ;
			*lst = (*lst)->next;
		}
	}
	finded = malloc(1 * sizeof(t_fd_list));
	if (finded == NULL)
		return (NULL);
	if (*lst != NULL)
	{
		*lst = frist;
		(*lst)->next = finded;
	}
	else
		*lst = finded;
	(finded)->fd = fd;
	(finded)->memory = NULL;
	(finded)->next = NULL;
	return (finded);
}

char	*read_line_break(int fd, char *memory)
{
	char	*buffer;
	ssize_t	read_bytes;

	if (ft_strchr(memory, '\n') != NULL)
		return (memory);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (ft_strchr(memory, '\n') == NULL && read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		memory = ft_strjoin(memory, buffer);
	}
	free(buffer);
	return (memory);
}

char	*get_whole_line(char *memory)
{
	int		i;
	char	*line;

	i = 0;
	if (memory[i] == '\0')
		return (NULL);
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		line = malloc((i + 2) * sizeof(char));
	else
		line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (memory[i] != '\0' && memory[i] != '\n')
	{
		line[i] = memory[i];
		i++;
	}
	if (memory[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clear_memory(char *memory)
{
	int		i;
	int		j;
	char	*clean_memory;

	i = 0;
	if (memory == NULL)
		return (NULL);
	while (memory[i] != '\0' && memory[i] != '\n')
		i++;
	if (memory[i] == '\0')
	{
		free(memory);
		return (NULL);
	}
	i++;
	clean_memory = malloc((ft_strlen(memory) - i + 1) * sizeof(char));
	if (clean_memory == NULL)
		return (NULL);
	j = 0;
	while (memory[i] != '\0')
		clean_memory[j++] = memory[i++];
	clean_memory[j] = '\0';
	free(memory);
	return (clean_memory);
}
