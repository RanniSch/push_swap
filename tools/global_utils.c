/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:36:34 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/03 12:45:53 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* counts the number of nodes */
int	count_of_nodes(struct s_node **liste)
{
	int				count;
	struct s_node	*ptr;

	count = 0;
	ptr = *liste;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->link;
	}
	return (count);
}

/* adds an index to each node; one node now has the value of the data 
and the value of the index */
void	set_index(struct s_node **liste)
{
	struct s_node	*ptr;
	int				i;

	ptr = *liste;
	i = 0;
	if (ptr != NULL)
	{
		while (ptr != NULL)
		{
			ptr->index = i;
			ptr = ptr->link;
			i++;
		}
	}
}

/* identifies the smallest number in Stack a after receiving arguments. */
int	smallest_in_a(struct s_node **a_liste)
{
	int	*array_a;
	int	smallest_num;

	array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
	if (!array_a)
		return (0);
	current_a(a_liste, array_a);
	smallest_num = min(a_liste, array_a);
	free(array_a);
	return (smallest_num);
}

/* identifies biggest number in Stack a (checks its representative array) 
after receiving arguments. */
int	biggest_in_a(struct s_node **a_liste)
{
	int	*array_a;
	int	len_a;
	int	biggest_num;

	array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
	if (!array_a)
		return (0);
	len_a = current_a(a_liste, array_a) + 1;
	biggest_num = max(array_a, len_a);
	free(array_a);
	return (biggest_num);
}

/* print the data of a linked list */
/*void	print_stack(struct s_node **liste)
{
	struct s_node	*ptr;

	if (*liste == NULL)
	{
		write(1, "Linked List is empty!\n", 22);
		exit(0);
	}
	ptr = *liste;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}*/
