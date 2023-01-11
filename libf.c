/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:38:09 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/11 12:36:51 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

char	*get_word(const char *s1, int *index, char c)
{
	char	*copy;
	int		word_len;
	int		i;

	word_len = 0;
	while (s1[*index] == c)
		(*index)++;
		i = *index;
	while (s1[i] && s1[i] != c)
	{
		word_len++;
		i++;
	}
	copy = malloc(sizeof(char) * (word_len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[*index] && s1[*index] != c)
		copy[i++] = s1[(*index)++];
	copy[i] = '\0';
	return (copy);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	int		index;
	int		wc;
	int		i;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	wc = word_count(s, c);
	arr = malloc(sizeof(char *) * (wc + 1));
	if (!arr)
		return (NULL);
	while (i < wc)
	{
	arr[i] = get_word(s, &index, c);
		if (!arr[i])
			return (error_malloc(arr));
	i++;
	}
	arr[i] = 0;
	free(s);
	return (arr);
}

int	lst_size(t_list **head)
{
	t_list	*temp;
	int		i;

	i = 0;
	if (*head)
	{
		temp = *head;
		while (*head)
		{
			i++;
			temp = temp->next;
			if (temp == *head)
				break ;
		}
	}
	return (i);
}

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	sup(int k, int b)
{
	if (k > b)
		return (k);
	return (b);
}
