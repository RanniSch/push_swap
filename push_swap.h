/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:11:10 by rschlott          #+#    #+#             */
/*   Updated: 2022/09/24 12:13:47 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

/* defines the data structure; in front needs to be typedef to declare the data type */
typedef struct node
{
    int data;
    int index;
    struct node *link;
}               s_node;

/*typedef struct program
{
    int count;
}               t_program;*/

/* reading */
int     ft_atoi(const char *str);
void    add_at_end(struct node **a_liste, int data);
void    set_index(struct node **a_liste);
int     count_of_nodes(struct node **liste);
void    print_stack(struct node **liste);
void    ft_stack_receive(int argc, char **argv, struct node **a_liste);

/* operations */
void    swap_elements(struct node **liste);
void    swap_a_b(struct node **a_liste, struct node **b_liste);
void    rotate_elements(struct node **liste);
void    rotate_a_b(struct node **a_liste, struct node **b_liste);
void    rotate_rev_elements(struct node **liste);
void    rotate_rev_a_b(struct node **a_liste, struct node **b_liste);
void    push_first_element(struct node **src, struct node **dest);

/* longest increasing subsequence */
int		max(int *tab, unsigned int len);
void    length_initializer_lis(int *subsequence, int *length, struct node **a_liste);
void    ft_lis_process(struct node **a_liste, struct node **b_liste, struct node **ptr_lis, int count);
void    longest_increasing_subsequence(struct node **a_liste, int *subsequence, int *length);
void    correct_subsequence(struct node **a_liste, struct node **ptr_lis, int *subsequence, int *length);
void    only_subsequence_in_a(struct node **a_liste, struct node **b_liste, struct node **ptr_lis);

#endif