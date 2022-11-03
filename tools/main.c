/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:33:55 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/03 06:47:57 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* &a_liste gives adress of pointer which points to list as a double pointer */
int	main(int argc, char **argv)
{
	struct s_node	*a_liste;
	struct s_node	*b_liste;

	a_liste = NULL;
	b_liste = NULL;
	stack_receive(argc, argv, &a_liste, &b_liste);
	return (0);
}
