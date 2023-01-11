/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:30:43 by amsaoub           #+#    #+#             */
/*   Updated: 2023/01/11 12:11:20 by amsaoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stddef.h>
# include<unistd.h>
# include<limits.h>
# include<stdlib.h>
# include<stdio.h> 
# include<string.h>

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
	int				sin;
	int				push;
	int				bma;
	int				bmb;
	int				sum;
	int				pos;
	int				indix;

}	t_list;

void	sa(t_list **lst, int i);
void	sb(t_list **lst, int i);
void	ss(t_list **lsta, t_list **lstb, int i);
void	pa(t_list **a, t_list **b, int i);
void	pb(t_list **a, t_list **b, int i);
void	ra(t_list **lst, int i);
void	rb(t_list **lst, int i);
void	rr(t_list **lsta, t_list **lstb, int i);
void	rra(t_list **lst, int i);
void	rrb(t_list **lst, int i);
void	rrr(t_list **lsta, t_list **lstb, int i);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int k);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
char	*ft_strjoin(int size, char **strs, char *sep);
int		ft_strlen(char *str);
char	**error_malloc(char **tab);
int		word_count(const char *str, char c);
char	*get_word(const char *s1, int *index, char c);
char	**ft_split(char *s, char c);
int		checkint(char	**tab);
int		abs(int a);
int		sup(int k, int b);
int		lst_size(t_list **head);
int		ft_atoi(char *str);
int		check_max_min(char **tab);
int		check_duplicates(char **tab);
long	ft_atoilong(char *str);
int		check_nul(char **tab, int ac);
void	the_best_head(t_list **heada, t_list **unq);
int		check_min_sin_lis(t_list **heada, t_list **unq);
int		fake_swap(t_list **heada, int *k, t_list **unq);
void	zero_one(t_list **unq);
void	new_head(t_list **heada, t_list **unq);
void	push_a_to_b(t_list **heada, t_list **headb, t_list **unq);
void	best_move(t_list **headb, t_list **heada);
int		best_sum(t_list **headb);
void	final_push(t_list **heada, t_list **headb);
void	final_push2(t_list **heada, t_list **headb, t_list *tempb);
void	final_push3(t_list **heada, t_list **headb, t_list *tempb);
void	end(t_list **heada);
void	indexing(t_list **heada);
void	push_a_to_b_helper(t_list **heada, int *i);
int		best_sum_helper(t_list **headb);
void	the_best_head_helper(t_list *temp);
void	end_rotate(t_list **heada, int k);
void	end_helper(t_list **heada, t_list **best, int *min);
void	ft_lstclear(t_list **lst);
void	ps(t_list *heada, t_list *headb, t_list *unq);
void	last_free(char **tab, t_list **heada);
char	*ft_strjoinn(char *s1, char *s2);
void	*ft_memcpy(void *dst, void *src, size_t n);
size_t	ft_strlenn( const char *c);
char	*ft_strdup(char *s1);
void	ftt_isempty(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		checkk(t_list **head);
void	check_output(t_list **heada);
#endif