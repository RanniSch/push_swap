/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:33:55 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/23 18:56:49 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* &a_liste gibt die Adresse des Pointers,
der zur Liste zeigt durch = double pointer */
int	main(int argc, char **argv)
{
	struct s_node	*a_liste;
	struct s_node	*b_liste;
	int	smallest_a;

	a_liste = NULL;
	b_liste = NULL;
    smallest_a = 0;
	stack_receive(argc, argv, &a_liste);
	//print_stack(&a_liste);
	smallest_a = smallest_in_a(&a_liste);
    if (count_of_nodes(&a_liste) >= 2 && count_of_nodes(&a_liste) <= 5)
        little_input(&a_liste, &b_liste, smallest_a);
    else
    {
        set_index(&a_liste);
	    lis_process(&a_liste, &b_liste, count_of_nodes(&a_liste));
	    minimum_sorting(&a_liste, &b_liste, smallest_a);
    }
	//biggest_a = biggest_in_a(&a_liste);
	//printf("smallest a %d\n", smallest_in_a(&a_liste));
	//printf("biggest a %d\n", biggest_in_a(&a_liste));
	return (0);
}
