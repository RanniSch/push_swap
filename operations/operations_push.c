/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 06:36:09 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/03 06:44:01 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Takes first arg at top of one stack and puts it at top of other stack. */
void	push_first_element(struct s_node **src, struct s_node **dest)
{
	struct s_node	*ptr_to_head;
	struct s_node	*ptr_dest;
	struct s_node	*temp;

	ptr_to_head = *src;
	ptr_dest = *dest;
	temp = ptr_to_head;
	*src = ptr_to_head->link;
	if (ptr_dest != NULL)
	{
		temp->link = ptr_dest;
	}
	else
		temp->link = NULL;
	*dest = temp;
}

/* pushes first element from stack b to stack a */
void	push_to_a(struct s_node **a_liste, struct s_node **b_liste)
{
	push_first_element(b_liste, a_liste);
	write(1, "pa\n", 3);
}

/* pushes first element from stack a to stack b */
void	push_to_b(struct s_node **a_liste, struct s_node **b_liste)
{
	push_first_element(a_liste, b_liste);
	write(1, "pb\n", 3);
}
