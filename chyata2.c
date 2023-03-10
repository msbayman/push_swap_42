/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chyata2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:51:29 by amsaoub           #+#    #+#             */
/*   Updated: 2023/02/14 12:39:47 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void	ftt_isempty(char *s)
{
	while (*s)
	{
		if (*s == ' ')
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		s++;
	}
}

void	er(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_spaces(char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (av[i])
	{
		k = 0;
		j = 0;
		while (av[i][j] == ' ')
		{
			j++;
			k++;
		}
		if (ft_strlen(av[i]) == j)
			er();
		i++;
	}	
}
