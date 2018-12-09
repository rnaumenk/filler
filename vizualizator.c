/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualizator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:56:22 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/03/26 19:56:23 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/filler.h"

void	redraw_this_shit(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '.')
			printf("\033[3;34m"".""\033[0m");
		else if (str[i] == 'O' || str[i] == 'o')
			printf("\033[3;32m""*""\033[0m");
		else if (str[i] == 'x' || str[i] == 'X')
			printf("\033[3;31m""*""\033[0m");
	}
	printf("\n");
}

void	result_line(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'O')
			printf("\033[3;32m""*""\033[0m");
		else if (str[i] == 'X')
			printf("\033[3;31m""*""\033[0m");
		else if (i >= 0 && i <= 2)
			printf("");
		else if (str[3] == 'O')
			printf("\033[3;32m""%c""\033[0m", str[i]);
		else if(str[3] == 'X')
			printf("\033[3;31m""%c""\033[0m", str[i]);
	}
	printf("\n");
}

void	calculate_score(char *av1, char *av2, int *a, int *b, int *c, int *d)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("filler.trace", O_RDONLY);
	get_next_line(fd, &line);
	ft_strdel(&line);
	get_next_line(fd, &line);
	if (ft_strstr(line, av1 + 12))
	{
		*a += 1;
		ft_strdel(&line);
		get_next_line(fd, &line);
		ft_strdel(&line);
		get_next_line(fd, &line);
		*c += ft_atoi(line);
		i = -1;
		while(ft_isdigit(line[++i]));
		while(!ft_isdigit(line[++i]));
		*d += ft_atoi(line + i);
	}
	else if (ft_strstr(line, av2 + 12))
	{
		*b += 1;
		ft_strdel(&line);
		get_next_line(fd, &line);
		ft_strdel(&line);
		get_next_line(fd, &line);
		*d += ft_atoi(line);
		i = -1;
		while(ft_isdigit(line[++i]));
		while(!ft_isdigit(line[++i]));
		*c += ft_atoi(line + i);
	}
	ft_strdel(&line);
	close(fd);
}

void	automatic(int argc, char **argv)
{
	char	buf[500];
	int		n;
	int		a;
	int		b;
	int		c;
	int		d;
	int		e;
	int		f;

	if (argc != 9 && argc != 10)
	{
		printf("EXAMPLE: ./vizualizator 10 ./resources/filler_vm -f ./resources/maps/map03 -p1 ./resources/players/carli.filler -p2 ./resources/players/rnaumenk.filler\n");
		return ;
	}
	n = ft_atoi(argv[1]);
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	while (n--)
	{
		if (argc == 10)
			snprintf(buf, sizeof(buf), "%s %s %s %s %s %s %s %s\n", argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
		else
			snprintf(buf, sizeof(buf), "%s %s %s %s %s %s %s\n", argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
		system(buf);
		calculate_score(argv[5][2] == '1' ? argv[6] : argv[8], argv[5][2] == '1' ? argv[8] : argv[6], &a, &b, &c, &d);
	}
	e = (argv[5][2] == '1' ? 6 : 8);
	f = (e == 6 ? 8 : 6);
	if (a > b)
		printf("%s won with the score %d:%d (%d:%d)\n", argv[e] + 20, a, b, c, d);
	if (a < b)
		printf("%s won with the score %d:%d (%d:%d)\n", argv[f] + 20, b, a, c, d);
	if (a == b)
	{
		if (c > d)
			printf("%s won with the score %d:%d (%d:%d)\n", argv[e] + 20, a, b, c, d);
		else if (c < d)
			printf("%s won with the score %d:%d (%d:%d)\n", argv[f] + 20, b, a, c, d);
		else
			printf("DRAW\n");
	}
}

int		main(int argc, char **argv)
{
	char	*line;
	int		i;
	int		gnl;

	if (argc > 1)
	{
		automatic(argc, argv);
		return (0);
	}
	i = 0;
	gnl = get_next_line(0, &line);
	while (gnl)
	{
		usleep(50000);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		while (gnl)
		{
			ft_strdel(&line);
			if (!(gnl  = get_next_line(0, &line)))
				return (0);
			if (line[0] == '0' || line[0] == '1')
				redraw_this_shit(line);
			if (line[1] == '=')
				result_line(line);
			if (line[0] == 32 && i == 1)
				break ;
			if (line[0] == 32)
				i = 1;
		}
	}
	ft_strdel(&line);
	return (0);
}
	