/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sorting_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 06:33:00 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/06 12:21:15 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* pushes the num from stack b with the smallest amount of operations
to stack a. If num is normal. */
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

/* pushes the num from stack b with the smallest amount of operations
to stack a. If num is min. */
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

/* pushes the num from stack b with the smallest amount of operations
to stack a. If num is max. */
void	sorting_biggest_num(struct s_node **a_liste, struct s_node **b_liste,
		int *array_a, int checker_a)
{
	int				len_a;
	struct s_node	*ptr_b;

	len_a = count_of_nodes(a_liste);
	ptr_b = *b_liste;
	if (checker_a == 5)
	{
		while (!(ptr_b->data > array_a[len_a - 1]
				&& array_a[0] < array_a[len_a - 1]))
		{
			rotate_a(a_liste);
			rotate_array_a(array_a, len_a);
		}
	}
	if (checker_a == 6)
	{
		while (!(ptr_b->data > array_a[len_a - 1]
				&& array_a[0] < array_a[len_a - 1]))
		{
			reverse_rotate_a(a_liste);
			reverse_rotate_array_a(array_a, len_a);
		}
	}
}

/* runs the functions in the correct order. */
void	the_process(struct s_node **a_liste, struct s_node **b_liste,
		int *array_a, int *values_b)
{
	int	len_a;
	int	smallest;
	int	index;
	int	checker_a;
	int	b_data;

	len_a = current_a(a_liste, array_a);
	get_smallest(array_a, len_a, b_liste, values_b);
	smallest = min(b_liste, values_b);
	index = index_value(values_b, smallest);
	b_data = identifies_best_b(b_liste, index);
	checker_a = sorting_position_a(array_a, len_a, b_data);
	run_best_b(b_liste, values_b, smallest, index);
	sorting_normal_num(a_liste, b_liste, array_a, checker_a);
	sorting_smallest_num(a_liste, b_liste, array_a, checker_a);
	sorting_biggest_num(a_liste, b_liste, array_a, checker_a);
	push_to_a(a_liste, b_liste);
}

/* allocates memory and calls "the_process" and after "final_order" */
int	minimum_sorting(struct s_node **a_liste, struct s_node **b_liste,
		int smallest_a)
{
	int				*array_a;
	int				*values_b;
	struct s_node	*ptr_b;

	ptr_b = *b_liste;
	while (ptr_b != NULL)
	{
		array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
		values_b = (int *)malloc((count_of_nodes(b_liste)) * sizeof(int));
		if (!values_b || !array_a)
			return (0);
		the_process(a_liste, b_liste, array_a, values_b);
		free(array_a);
		free(values_b);
		ptr_b = *b_liste;
	}
	final_order(a_liste, smallest_a);
	return (0);
}
