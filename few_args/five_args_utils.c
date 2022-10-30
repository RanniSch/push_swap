/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_args_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:20:48 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/30 17:38:50 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_num_b(struct s_node **b_liste, unsigned int index)
{
	if (index > 0)
	{
		while (index--)
			rotate_b(b_liste);
	}
}

void	sorting_normal_num(struct s_node **a_liste, struct s_node **b_liste,
		int *array_a, int checker_a)
{
	int				len_a;
	struct s_node	*ptr_b;

	len_a = count_of_nodes(a_liste);
	ptr_b = *b_liste;
	if (checker_a == 1)
	{
		while (!(ptr_b->data < array_a[0] && ptr_b->data > array_a[len_a - 1]))
		{
			rotate_a(a_liste);
			rotate_array_a(array_a, len_a);
		}
	}
	if (checker_a == 2)
	{
		while (!(ptr_b->data < array_a[0] && ptr_b->data > array_a[len_a - 1]))
		{
			reverse_rotate_a(a_liste);
			reverse_rotate_array_a(array_a, len_a);
		}
	}
}

void	sorting_smallest_num(struct s_node **a_liste, struct s_node **b_liste,
		int *array_a, int checker_a)
{
	int				len_a;
	struct s_node	*ptr_b;

	len_a = count_of_nodes(a_liste);
	ptr_b = *b_liste;
	if (checker_a == 3)
	{
		while (!(ptr_b->data < array_a[0] && array_a[len_a - 1] > array_a[0]))
		{
			rotate_a(a_liste);
			rotate_array_a(array_a, len_a);
		}
	}
	if (checker_a == 4)
	{
		while (!(ptr_b->data < array_a[0] && array_a[len_a - 1] > array_a[0]))
		{
			reverse_rotate_a(a_liste);
			reverse_rotate_array_a(array_a, len_a);
		}
	}
}

void	sorting_biggest_num(struct s_node **a_liste, struct s_node **b_liste,
		int *array_a, int checker_a)
{
	int				len_a;
	struct s_node	*ptr_b;

	len_a = count_of_nodes(a_liste);
	ptr_b = *b_liste;
	if (checker_a == 5)
	{
		while (!(ptr_b->data > array_a[len_a - 1] && array_a[0] < array_a[len_a
				- 1]))
		{
			rotate_a(a_liste);
			rotate_array_a(array_a, len_a);
		}
	}
	if (checker_a == 6)
	{
		while (!(ptr_b->data > array_a[len_a - 1] && array_a[0] < array_a[len_a
				- 1]))
		{
			reverse_rotate_a(a_liste);
			reverse_rotate_array_a(array_a, len_a);
		}
	}
}

void	run_five_arguments(struct s_node **a_liste, struct s_node **b_liste,
		int *array_a, int *values_b)
{
	int	len_a;
	int	index;
	int	smallest;
	int	checker_a;

	len_a = current_a(a_liste, array_a);
	get_smallest(array_a, len_a, b_liste, values_b);
	smallest = min(b_liste, values_b);
	index = index_value(values_b, smallest);
	checker_a = sorting_position_a(array_a, len_a, b_liste, index);
	best_num_b(b_liste, index);
	sorting_normal_num(a_liste, b_liste, array_a, checker_a);
	sorting_smallest_num(a_liste, b_liste, array_a, checker_a);
	sorting_biggest_num(a_liste, b_liste, array_a, checker_a);
	push_to_a(a_liste, b_liste);
}
