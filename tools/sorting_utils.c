/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:18:48 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/06 11:47:32 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* identifies the smallest number in an array. */
int	min(struct s_node **b_liste, int *values_b)
{
	int	min;
	int	len;

	len = count_of_nodes(b_liste);
	if (!len)
		return (0);
	min = values_b[--len];
	while (len--)
	{
		if (values_b[len] < min)
			min = values_b[len];
	}
	return (min);
}

/* checks if current b_data is smaller than the smallest entry in Stack a */
bool	min_limit_checker(int *array_a, unsigned int len_a, int b_data)
{
	int	min;

	if (!len_a)
		return (0);
	min = array_a[--len_a];
	while (len_a--)
	{
		if (array_a[len_a] < min)
			min = array_a[len_a];
	}
	if (b_data < min)
	{
		return (true);
	}
	return (false);
}

/* checks if current b_data is bigger than the biggest entry in Stack a */
bool	max_limit_checker(int *array_a, unsigned int len_a, int b_data)
{
	int	max;

	if (!len_a)
		return (0);
	max = array_a[--len_a];
	while (len_a--)
	{
		if (array_a[len_a] > max)
			max = array_a[len_a];
	}
	if (b_data > max)
	{
		return (true);
	}
	return (false);
}

/* puts the current Stack a in an array */
int	current_a(struct s_node **a_liste, int *array_a)
{
	struct s_node	*ptr_a;
	int				len_a;

	len_a = 0;
	ptr_a = *a_liste;
	while (ptr_a != NULL)
	{
		array_a[len_a] = ptr_a->data;
		ptr_a = ptr_a->link;
		len_a++;
	}
	return (len_a);
}

/* identifies the position where to sort in number from b in stack a.
Here: int *array_a = ar, b_data = b, len_a = len to save space. */
int	sorting_position_a(int *ar, int len, int b)
{
	int	i;

	i = -1;
	while (++i < (len - 1))
	{
		if (((b > ar[i] && b < ar[i + 1]) && i < ((len - 1) / 2)) || len == 2)
			return (1);
		if ((b > ar[i] && b < ar[i + 1]) && i >= ((len - 1) / 2))
			return (2);
		if (min_limit_checker(ar, len, b))
			if ((b < ar[i + 1] && ar[i] > ar[i + 1]
					&& i < ((len - 1) / 2)) || len == 2)
				return (3);
		if (min_limit_checker(ar, len, b))
			if ((b < ar[i + 1] && ar[i] > ar[i + 1]) && i >= ((len - 1) / 2))
				return (4);
		if (max_limit_checker(ar, len, b))
			if ((b > ar[i] && ar[i + 1] < ar[i]
					&& i < ((len - 1) / 2)) || len == 2)
				return (5);
		if (max_limit_checker(ar, len, b))
			if (b > ar[i] && ar[i + 1] < ar[i] && i >= ((len - 1) / 2))
				return (6);
	}
	return (0);
}
