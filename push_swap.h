/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:11:10 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/10 07:45:42 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* defines the data structure; in front needs to be typedef to declare the data type */
typedef struct s_node
{
    int data;
    int index;
    struct s_node *link;
}               t_node;

/*typedef struct program
{
    int count;
}               t_program;*/

/* reading */
void    add_at_end(struct s_node **a_liste, int data);
void    set_index(struct s_node **a_liste);
int     count_of_nodes(struct s_node **liste);
void    print_stack(struct s_node **liste);
void    ft_stack_receive(int argc, char **argv, struct s_node **a_liste);

/* error manager */
void    error_manager_int(const char *str);
void    error_manager_duplicate(struct s_node **a_liste);
int     ft_atoi(const char *str);

/* operations */
void    swap_elements(struct s_node **liste);
void	swap_a(struct s_node **a_liste);
void	swap_b(struct s_node **a_liste);
void	swap_both(struct s_node **a_liste, struct s_node **b_liste);
void    rotate_elements(struct s_node **liste);
void	rotate_a(struct s_node **a_liste);
void	rotate_b(struct s_node **b_liste);
void	rotate_both(struct s_node **a_liste, struct s_node **b_liste);
void    rotate_rev_elements(struct s_node **liste);
void	reverse_rotate_a(struct s_node **a_liste);
void	reverse_rotate_b(struct s_node **b_liste);
void	ft_reverse_rotate_both(struct s_node **a_liste, struct s_node **b_liste);
void    push_first_element(struct s_node **src, struct s_node **dest);
void	push_to_a(struct s_node **a_liste, struct s_node **b_liste);
void	push_to_b(struct s_node **a_liste, struct s_node **b_liste);

/* longest increasing subsequence */
int		max(int *tab, unsigned int len);
void    length_initializer_lis(int *subsequence, int *length, struct s_node **a_liste);
void    ft_lis_process(struct s_node **a_liste, struct s_node **b_liste, int count);
void    longest_increasing_subsequence(struct s_node **a_liste, int *subsequence, int *length);
int     correct_subsequence(struct s_node **a_liste, int *subsequence, int *length, int *array_lis);
void    only_subsequence_in_a(struct s_node **a_liste, struct s_node **b_liste, int *array_lis, int len_lis);

#endif