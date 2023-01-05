/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:25:50 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/05 12:11:29 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	x(t_list **heada, t_list **headb, t_list **unq, char **tab)
{
	ps(*heada,*headb, *unq);
	last_free(tab, heada);
}

int	main(int ac, char **av)
{
	char	**tab;
	t_list	*heada;
	t_list	*headb;
	t_list	*unq;
	int		i;

	unq = NULL;
	headb = NULL;
	if (ac == 1)
		return (write(1, "Error", 5));
	else
	{
		i = 0;
		heada = NULL;
		tab = ft_split(ft_strjoin(ac - 1, av + 1, " "), ' ');
		if (!check_nul(tab, ac)
			|| !checkint(tab) || !check_max_min(tab) || !check_duplicates(tab))
			return (write(1, "Error\n", 6));
		while (tab[i])
			ft_lstadd_back(&heada, ft_lstnew(ft_atoi(tab[i++])));
	}
	x(&heada, &headb, &unq, tab);
}
