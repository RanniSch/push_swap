/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:11:10 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/23 19:31:07 by rschlott         ###   ########.fr       */
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
int     add_at_end(struct s_node **a_liste, int data);
void    set_index(struct s_node **a_liste);
int     count_of_nodes(struct s_node **liste);
void    print_stack(struct s_node **liste);
void    stack_receive(int argc, char **argv, struct s_node **a_liste);
int     smallest_in_a(struct s_node **a_liste);
int     biggest_in_a(struct s_node **a_liste);

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
void	reverse_rotate_both(struct s_node **a_liste, struct s_node **b_liste);
void    push_first_element(struct s_node **src, struct s_node **dest);
void	push_to_a(struct s_node **a_liste, struct s_node **b_liste);
void	push_to_b(struct s_node **a_liste, struct s_node **b_liste);
void    rotate_array_a(int *array_a, int len_a);
void    reverse_rotate_array_a(int *array_a, int len_a);

/* longest increasing subsequence */
int		max(int *length, unsigned int len);
void    length_initializer_lis(int *subsequence, int *length, struct s_node **a_liste);
int     lis_process(struct s_node **a_liste, struct s_node **b_liste, int count);
void    longest_increasing_subsequence(struct s_node **a_liste, int *subsequence, int *length);
int     correct_subsequence(struct s_node **a_liste, int *subsequence, int *length, int *array_lis);
int 	anti_subsequence(struct s_node **a_liste, int *array_lis, int *anti_lis, int len_lis);
void    only_subsequence_in_a(struct s_node **a_liste, struct s_node **b_liste, int *array_lis, int len_lis);

/* minimum sorting value to put a number from b to a */
void    final_order(struct s_node **a_liste, int smallest_a, int *array_a, int len_a);
int     minimum_sorting(struct s_node **a_liste, struct s_node **b_liste, int smallest_a);
void    runs_smallest(struct s_node **a_liste, struct s_node **b_liste, int checker_b, unsigned int index, int *array_a, int len_a, int checker_a);
int     sorting_position_a(int *array_a, int len_a, struct s_node **b_liste, int index);
int     index_value(int *values_b, int smallest);
int     location_value(struct s_node **b_liste, int *values_b, int smallest);
int     min_limit_checker(int *array_a, unsigned int len_a, int b_data);
int     max_limit_checker(int *array_a, unsigned int len_a, int b_data);
void    get_smallest(int *array_a, int len_a, struct s_node **b_liste, int *values_b);
int     current_a(struct s_node **a_liste, int *array_a);
int     min(struct s_node **b_liste, int *values_b);

/* little input */
void    little_input(struct s_node **a_liste, struct s_node **b_liste, int smallest_a);
void    four_arguments(struct s_node **a_liste, struct s_node **b_liste, int smallest_a);
void    three_arguments(struct s_node **a_liste);
void    two_arguments(struct s_node **a_liste);

#endif