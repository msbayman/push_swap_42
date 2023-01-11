/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:21:06 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/11 15:27:55 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ins(char *str, t_list **heada, t_list **headb)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sa(heada, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		sb(headb, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		ss(heada, headb, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		pa(heada, headb, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		pb(heada, headb, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		ra(heada, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		rb(headb, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		rr(heada, headb, 0);
	else if (!ft_strncmp(str, "rra\n", 4))
		rra(heada, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		rrb(headb, 0);
	else if (!ft_strncmp(str, "rrr\n", 4))
		rrr(heada, headb, 0);
	else
		return (write(2, "Error\n", 6), exit(1));
}

int	checkk(t_list **head, t_list **headb)
{
	t_list	*temp;

	temp = *head;
	while (1)
	{
		if (temp->data > temp->next->data || *headb)
			return (0);
		temp = temp->next;
		if (temp->next == *head)
			break ;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**tab;
	t_list	*heada;
	t_list	*headb;
	int		i;
	char	*str;

	headb = NULL;
	if (ac == 1)
		return (0);
	i = 0;
	heada = NULL;
	tab = ft_split(ft_strjoin(ac - 1, av + 1, " "), ' ');
	if (!check_nul(tab, ac)
		|| !checkint(tab) || !check_max_min(tab) || !check_duplicates(tab))
		return (write(2, "Error\n", 6));
	while (tab[i])
		ft_lstadd_back(&heada, ft_lstnew(ft_atoi(tab[i++])));
	str = get_next_line(0);
	while (str)
	{
		ins(str, &heada, &headb);
		free(str);
		str = get_next_line(0);
	}
	check_output(&heada, &headb);
}

void	check_output(t_list **heada, t_list **headb)
{
	if(*heada == NULL)
	{
		write(1, "KO\n", 3);
		exit(1);
	}
	if (checkk(heada, headb))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
