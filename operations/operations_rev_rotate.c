/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 06:56:35 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/03 06:44:09 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* reverse rotate function: The last element becomes the first one */
void	rotate_rev_elements(struct s_node **liste)
{
	struct s_node	*temp1;
	struct s_node	*temp2;
	struct s_node	*ptr_to_head;
	int				i;

	ptr_to_head = *liste;
	temp1 = ptr_to_head;
	temp2 = ptr_to_head;
	i = 1;
	while (i < count_of_nodes(liste))
	{
		if (i < (count_of_nodes(liste) - 1))
			temp1 = temp1->link;
		temp2 = temp2->link;
		i++;
	}
	temp2->link = ptr_to_head;
	*liste = temp2;
	temp1->link = NULL;
}

/* reverse rotate a. The last element becomes the first one */
void	reverse_rotate_a(struct s_node **a_liste)
{
	rotate_rev_elements(a_liste);
	write(1, "rra\n", 4);
}

/* reverse rotate b. The last element becomes the first one */
void	reverse_rotate_b(struct s_node **b_liste)
{
	rotate_rev_elements(b_liste);
	write(1, "rrb\n", 4);
}

/* reverse rotate a and b at the same time. */
void	reverse_rotate_both(struct s_node **a_liste, struct s_node **b_liste)
{
	rotate_rev_elements(a_liste);
	rotate_rev_elements(b_liste);
	write(1, "rrr\n", 4);
}
