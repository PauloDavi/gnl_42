/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 03:32:58 by vscode            #+#    #+#             */
/*   Updated: 2023/05/21 14:42:09 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
char	*clear_memory(char *memory);
char	*get_whole_line(char *memory);
char	*read_line_break(int fd, char *memory);

// Utils
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, char c);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
