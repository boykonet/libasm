/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarina <gkarina@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:19:09 by gkarina           #+#    #+#             */
/*   Updated: 2020/10/30 22:19:09 by gkarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./libasm/libasm.h"
#include <stdio.h>

static int		check_write(void)
{
	char		*buff;
	char		*str;
	int			a;
	int			b;

	buff = "Hello, world!\n";
	errno = 0;
	a = write(1, buff, 14);
	str = strerror(errno);
	write(1, "\n", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	errno = 0;
	b = ft_write(1, buff, 14);
	str = strerror(errno);
	write(1, "\n", 1);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	if (a != b)
		write(1, "Error!\n", 7);
}

static void		check_read(void)
{
	char		buff[30];
	char		*str;
	int			fd;
	int			a;
	int			b;

	if ((fd = open("ex", O_RDONLY)) == -1)
		write(1, "Error! File descriptor not opened!\n", 35);
	errno = 0;
	a = read(fd, buff, 30);
	if (a > 0)
	{
		buff[a] = '\0';
		write(1, buff, ft_strlen(buff));
	}
	str = strerror(errno);
	write(1, str, ft_strlen(str));
	errno = 0;
	b = ft_read(fd, buff, 30);
	if (b > 0)
	{
		buff[b] = '\0';
		write(1, buff, ft_strlen(buff));
	}
	str = strerror(errno);
	write(1, str, ft_strlen(str));
	if (a != b)
		write(1, "Error!\n", 7);
	if (close(fd) == -1)
		write(1, "Error!\n", 7);
}

int		main(void)
{
	int		fd;
	int		a;
	char	buff3[10];
	char	*str;

	a = ft_strlen("aaabbbccc");
	ft_strcpy(buff3, "aaabbbccc");
	write(1, buff3, ft_strlen(buff3));
	write(1, "\n", 1);
	a = ft_strlen(buff3);

   	a = ft_strcmp("aaabbbccc", "aaabbbccc");

	a = ft_strcmp("aaabbbA", "aaabbbccc");

	a = ft_strcmp("aaabbbccc", "aaabbbA");

	check_write();
	check_read();
	
	errno = 0;
	str = ft_strdup("aaabbbccc");
	if (errno == 0)
		write(1, str, ft_strlen(str));
	free(str);
	str = strerror(errno);
	return (0);
}
