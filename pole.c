/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pole.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedavis <bedavis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:19:57 by bedavis           #+#    #+#             */
/*   Updated: 2019/10/28 14:22:21 by bedavis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Зпалняет поле пустыми ячейками .
*/

void	init_pole(char pole_alpha[16][16], int m)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < m)
	{
		j = 0;
		while (j < m)
			pole_alpha[i][j++] = '.';
	}
}

void	print_pole(char pole_alpha[16][16], int m)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < m)
	{
		j = 0;
		while (j < m)
			ft_putchar(pole_alpha[i][j++]);
		ft_putchar('\n');
	}
}

void	put_pole(int n, __uint128_t *res, char pole_alpha[16][16])
{
	int			k;
	int			i;
	int			j;
	__uint128_t	chislo;
	__uint128_t	del;

	k = 0;
	i = 0;
	j = 0;
	chislo = res[n];
	del = ft_power(2, 120);
	while (k++ < 121)
	{
		if (chislo / del)
		{
			pole_alpha[i][j] = (char)(n + 'A');
			chislo = chislo - del;
		}
		del = del / 2;
		j = (k % 11) ? j + 1 : 0;
		i = (k % 11) ? i : i + 1;
	}
}

void	unput_pole(int n, __uint128_t *res, char pole_alpha[16][16])
{
	int			k;
	int			i;
	int			j;
	__uint128_t	chislo;
	__uint128_t	del;

	k = 0;
	i = 0;
	j = 0;
	chislo = res[n];
	del = ft_power(2, 120);
	while (k++ < 121)
	{
		if (chislo / del)
		{
			pole_alpha[i][j] = '.';
			chislo = chislo - del;
		}
		del = del / 2;
		j = (k % 11) ? j + 1 : 0;
		i = (k % 11) ? i : i + 1;
	}
}

void	ft_putstr(char *s)
{
	int i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i++]);
		}
	}
}
