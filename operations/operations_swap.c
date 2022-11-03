/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:44:09 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/03 06:44:27 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* swap function: Swap the first two elements at the top of the stack */
void	swap_elements(struct s_node **liste)
{
	struct s_node	*temp1;
	struct s_node	*temp2;
	struct s_node	*ptr_to_head;

	ptr_to_head = *liste;
	temp1 = ptr_to_head->link;
	temp2 = temp1->link;
	*liste = temp1;
	ptr_to_head->link = temp2;
	temp1->link = ptr_to_head;
}

/* Swaps the first two elements at the top of a */
void	swap_a(struct s_node **a_liste)
{
	swap_elements(a_liste);
	write(1, "sa\n", 3);
}

/* Swaps the first two elements at the top of b */
void	swap_b(struct s_node **b_liste)
{
	swap_elements(b_liste);
	write(1, "sb\n", 3);
}

/* swap a and b at the same time */
void	swap_both(struct s_node **a_liste, struct s_node **b_liste)
{
	swap_elements(a_liste);
	swap_elements(b_liste);
	write(1, "ss\n", 3);
}
