/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 09:11:10 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/06 12:19:47 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* defines the data structure. 
In front needs to be typedef to declare the data type */
typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*link;
}					t_node;

/* reading. In folder "tools". */
int					ft_atoi(const char *str);
int					add_at_end(struct s_node **a_liste, struct s_node *current,
						int data);
void				run_sorting_process(struct s_node **a_liste,
						struct s_node **b_liste);
void				del_list(struct s_node **a_liste);
int					stack_receive(int argc, char **argv,
						struct s_node **a_liste, struct s_node **b_liste);
void				print_stack(struct s_node **liste);

/* error manager. Im folder "tools". */
bool				error_manager_int(const char *str);
bool				error_manager_duplicate(struct s_node **a_liste);
bool				error_manager_outta_int(const char *str);
void				ft_more_exit(struct s_node **a_liste, struct s_node *ptr_a);

/* global utils to use throughout program. In folder "tools". */
int					count_of_nodes(struct s_node **liste);
void				set_index(struct s_node **a_liste);
int					smallest_in_a(struct s_node **a_liste);
int					biggest_in_a(struct s_node **a_liste);
void				final_order(struct s_node **a_liste, int smallest_a);

/* longest increasing subsequence (name as folder) */
int					max(int *length, unsigned int len);
void				length_initializer_lis(int *subsequence, int *length,
						int count);
void				longest_increasing_subsequence(struct s_node **a_liste,
						int *subsequence, int *length);
int					correct_subsequence(struct s_node **a_liste,
						int *subsequence, int *length, int *array_lis);
void				only_subsequence_in_a(struct s_node **a_liste,
						struct s_node **b_liste, int *array_lis, int len_lis);
int					lis_process(struct s_node **a_liste,
						struct s_node **b_liste, int count);

/* identifies smallest num of operations in which fills int *values_b with nums.
In folder "tools" */
int					get_smallest_normal(int b_data, int *array_a, int len_a,
						int op);
int					get_smallest_min(int b_data, int *array_a, int len_a,
						int op);
int					get_smallest_max(int b_data, int *array_a, int len_a,
						int op);
void				get_smallest(int *array_a, int len_a,
						struct s_node **b_liste, int *values_b);

/* operations (name as folder) */
void				rotate_array_a(int *array_a, int len_a);
void				reverse_rotate_array_a(int *array_a, int len_a);
void				swap_array_a(int *array_a);
void				swap_elements(struct s_node **liste);
void				swap_a(struct s_node **a_liste);
void				swap_b(struct s_node **a_liste);
void				swap_both(struct s_node **a_liste, struct s_node **b_liste);
void				rotate_elements(struct s_node **liste);
void				rotate_a(struct s_node **a_liste);
void				rotate_b(struct s_node **b_liste);
void				rotate_both(struct s_node **a_liste,
						struct s_node **b_liste);
void				rotate_rev_elements(struct s_node **liste);
void				reverse_rotate_a(struct s_node **a_liste);
void				reverse_rotate_b(struct s_node **b_liste);
void				reverse_rotate_both(struct s_node **a_liste,
						struct s_node **b_liste);
void				push_first_element(struct s_node **src,
						struct s_node **dest);
void				push_to_a(struct s_node **a_liste, struct s_node **b_liste);
void				push_to_b(struct s_node **a_liste, struct s_node **b_liste);

/* moves num in b_stack with smallest amount of operations to the top.
In folder "tools". */
bool				location_value_b(struct s_node **b_liste, int *values_b,
						int smallest);
int					index_value(int *values_b, int smallest);
int					identifies_best_b(struct s_node **b_liste, int index);
void				run_best_b(struct s_node **b_liste, int *values_b,
						int smallest, int index);

/* minimum sorting process to put a number from b to a. In folder "tools" */
int					min(struct s_node **b_liste, int *values_b);
bool				min_limit_checker(int *array_a, unsigned int len_a,
						int b_data);
bool				max_limit_checker(int *array_a, unsigned int len_a,
						int b_data);
int					current_a(struct s_node **a_liste, int *array_a);
int					sorting_position_a(int *ar, int len, int b);
void				sorting_normal_num(struct s_node **a_liste,
						struct s_node **b_liste, int *array_a, int checker_a);
void				sorting_smallest_num(struct s_node **a_liste,
						struct s_node **b_liste, int *array_a, int checker_a);
void				sorting_biggest_num(struct s_node **a_liste,
						struct s_node **b_liste, int *array_a, int checker_a);
void				the_process(struct s_node **a_liste,
						struct s_node **b_liste, int *array_a, int *values_b);
int					minimum_sorting(struct s_node **a_liste,
						struct s_node **b_liste, int smallest_a);

/* few arguments <= 5 (few_args) */
void				two_arguments(struct s_node **a_liste);
void				three_arguments(struct s_node **a_liste, int *array_a,
						int len_a);
void				run_four_arguments(struct s_node **a_liste,
						struct s_node **b_liste, int *array_a, int len_a);
int					four_arguments(struct s_node **a_liste,
						struct s_node **b_liste);
void				best_num_b(struct s_node **b_liste, unsigned int index);
void				run_five_arguments(struct s_node **a_liste,
						struct s_node **b_liste, int *array_a, int *values_b);
int					five_arguments(struct s_node **a_liste,
						struct s_node **b_liste, int smallest_a);
bool				sorted_numbers(struct s_node **a_liste);
void				shorten_stack_a(struct s_node **a_liste,
						struct s_node **b_liste);
int					little_input(struct s_node **a_liste,
						struct s_node **b_liste, int smallest_a);

#endif