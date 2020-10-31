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

static void		check_write(void)
{
	char		*buff;
	char		*str;
	int			a;
	int			b;

	buff = "Hello, world!\n";
	ft_write(1, "\n---------- ft_write ----------\n", 32);
	errno = 0;
	a = write(1, buff, 14);
	ft_write(1, "errno = ", 8);
	str = strerror(errno);
	ft_write(1, str, ft_strlen(str));
	ft_write(1, "\n\n", 2);
	errno = 0;
	b = ft_write(1, buff, 14);
	str = strerror(errno);
	ft_write(1, "errno = ", 8);
	ft_write(1, str, ft_strlen(str));
	ft_write(1, "\n\n", 2);
	if (a != b)
		ft_write(1, "ft_write() funclion doesn't work:(\n", 36);
	else
		ft_write(1, "ft_write() funclion is work!\n", 29);
}

static void		check_read(void)
{
	char		buff[30];
	char		*str;
	int			fd;
	int			a;
	int			b;

	if ((fd = open("ex", O_RDONLY)) == -1)
		ft_write(1, "Error! File descriptor not opened!\n", 35);
	ft_write(1, "\n---------- ft_read ----------\n", 31);
	errno = 0;
	a = read(fd, buff, 30);
	if (a > 0)
	{
		buff[a] = '\0';
		ft_write(1, "buff[] = <", 10);
		ft_write(1, buff, ft_strlen(buff));
		ft_write(1, ">\n", 2);
	}
	str = strerror(errno);
	ft_write(1, "errno = ", 8);
	ft_write(1, str, ft_strlen(str));
	ft_write(1, "\n\n", 2);
	errno = 0;
	b = ft_read(fd, buff, 30);
	if (b > 0)
	{
		buff[b] = '\0';
		ft_write(1, "buff[] = <", 10);
		ft_write(1, buff, ft_strlen(buff));
		ft_write(1, ">\n", 2);
	}
	str = strerror(errno);
	ft_write(1, "errno = ", 8);
	ft_write(1, str, ft_strlen(str));
	ft_write(1, "\n\n", 2);
	if (a != b)
		ft_write(1, "ft_read() function doesn't work:(\n", 34);
	else
		ft_write(1, "ft_read() function is work!\n", 28);
	if (close(fd) == -1)
		ft_write(1, "Error! File descriptor not closed\n", 34);
}

int				main(void)
{
	int			a;
	int			b;
	char		buff3[10];
	char		buff4[10];
	char		*str;
	char		*str1;

	str = "aaabbbccc";
	ft_write(1, "\n---------- ft_strlen ----------\n", 33);
	ft_write(1, "str = <", 7);
	ft_write(1, str, ft_strlen(str));
	ft_write(1, ">\n", 2);
	a = ft_strlen(str);
	b = strlen(str);
	if (a == b)
		ft_write(1, "ft_strlen(str) == strlen(str)\n", 30);
	else
		ft_write(1, "ft_strlen(str) != strlen(str)\n", 30);
	ft_write(1, "\n---------- ft_strcpy ----------\n", 33);
	str = "qwerty";
	ft_write(1, "str   = <", 9);
	ft_write(1, str, ft_strlen(str));
	ft_write(1, ">\n", 2);
	ft_strcpy(buff3, str);
	strcpy(buff4, str);
	ft_write(1, "buff3 = <", 9);
	ft_write(1, buff3, ft_strlen(buff3));
	ft_write(1, ">\n", 2);
	ft_write(1, "buff4 = <", 9);
	ft_write(1, buff4, ft_strlen(buff4));
	ft_write(1, ">\n", 2);
	a = ft_strlen(buff3);
	b = strlen(buff4);
	if (a == b)
		ft_write(1, "ft_strcpy(buff3, str) == strcpy(buff4, str)\n", 44);
	else
		ft_write(1, "ft_strcpy(buff3, str) == strcpy(buff4, str)\n", 44);
	ft_write(1, "\n---------- ft_strcmp ----------\n", 33);
	str = "aaabbbccc";
	str1 = str;
	ft_write(1, "str  = <", 8);
	ft_write(1, str, ft_strlen(str));
	ft_write(1, ">\n", 2);
	ft_write(1, "str1 = <", 8);
	ft_write(1, str1, ft_strlen(str1));
	ft_write(1, ">\n", 2);
	a = ft_strcmp(str, str1);
	if (a == 0)
		ft_write(1, "ft_strcmp(str, str1) OK\n\n", 25);
	else
		ft_write(1, "ft_strcmp(str, str1) KO\n\n", 25);
	str = "aaabbbA";
	str1 = "aaabbbccc";
	ft_write(1, "str  = <", 8);
	ft_write(1, str, ft_strlen(str));
	ft_write(1, ">\n", 2);
	ft_write(1, "str1 = <", 8);
	ft_write(1, str1, ft_strlen(str1));
	ft_write(1, ">\n", 2);
	a = ft_strcmp(str, str1);
	if (a < 0)
		ft_write(1, "ft_strcmp(str, str1) OK\n\n", 25);
	else
		ft_write(1, "ft_strcmp(str, str1) KO\n\n", 25);
	str = "aaabbbccc";
	str1 = "aaabbbA";
	ft_write(1, "str  = <", 8);
	ft_write(1, str, ft_strlen(str));
	ft_write(1, ">\n", 2);
	ft_write(1, "str1 = <", 8);
	ft_write(1, str1, ft_strlen(str1));
	ft_write(1, ">\n", 2);
	a = ft_strcmp(str, str1);
	if (a > 0)
		ft_write(1, "ft_strcmp(str, str1) OK\n", 24);
	else
		ft_write(1, "ft_strcmp(str, str1) KO\n", 24);
	check_write();
	check_read();
	ft_write(1, "\n---------- ft_strdup ----------\n", 33);
	errno = 0;
	str = "aaabbbccc";
	ft_write(1, "str                   = <", 25);
	ft_write(1, str, ft_strlen(str));
	ft_write(1, ">\n", 2);
	str1 = ft_strdup(str);
	if (errno == 0)
	{
		ft_write(1, "after ft_strdup: str1 = <", 25);
		ft_write(1, str1, ft_strlen(str1));
		ft_write(1, ">\n", 2);
	}
	free(str1);
	str = strerror(errno);
	ft_write(1, "errno = ", 8);
	ft_write(1, str, ft_strlen(str));
	ft_write(1, "\n", 1);
	return (0);
}
