/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:06:25 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/03 06:44:15 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* rotate function: The first element becomes the last one */
void	rotate_elements(struct s_node **liste)
{
	struct s_node	*temp1;
	struct s_node	*temp2;
	struct s_node	*ptr_to_head;
	int				i;

	ptr_to_head = *liste;
	temp2 = ptr_to_head;
	temp1 = temp2->link;
	i = 1;
	*liste = temp1;
	while (i <= count_of_nodes(liste))
	{
		temp2 = temp2->link;
		i++;
	}
	temp2->link = ptr_to_head;
	ptr_to_head->link = NULL;
}

/* rotates a. The first element becomes the last */
void	rotate_a(struct s_node **a_liste)
{
	rotate_elements(a_liste);
	write(1, "ra\n", 3);
}

/* rotates b. The first element becomes the last */
void	rotate_b(struct s_node **b_liste)
{
	rotate_elements(b_liste);
	write(1, "rb\n", 3);
}

/* rotates a and b at the same time. The first elements become the last */
void	rotate_both(struct s_node **a_liste, struct s_node **b_liste)
{
	rotate_elements(a_liste);
	rotate_elements(b_liste);
	write(1, "rr\n", 3);
}
