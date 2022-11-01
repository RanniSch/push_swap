/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:23:03 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/01 07:22:29 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* adds a new node to the list */
int	add_at_end(struct s_node **a_liste, struct s_node *current, int data)
{
	struct s_node *ptr_a;

    ptr_a = *a_liste;
	current->data = data;
	current->link = NULL;
	if (ptr_a != NULL)
	{
		while (ptr_a->link != NULL)
			ptr_a = ptr_a->link;
		ptr_a->link = current;
	}
	else
		*a_liste = current;
	return(0);
}

/* adds an index to each node; one node now has the value of the data and the value of the index */
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

/* counts the number of nodes */
int	count_of_nodes(struct s_node **liste)
{
	int			count;
	struct s_node	*ptr;

	count = 0;
	if (*liste == NULL)
		write(1, "Stack is empty\n", 15);
	ptr = NULL;
	ptr = *liste;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->link;
	}
	return (count);
}

/* print the data of a linked list */
void	print_stack(struct s_node **liste)
{
	struct s_node	*ptr;

	if (*liste == NULL)
	{
		write(1, "Linked List is empty!\n", 22);
		exit(0);
	}
	ptr = NULL;
	ptr = *liste;
	while (ptr != NULL)
	{
		printf("%d ", ptr->data); // insert printf function!!!!!!!!!!!
		ptr = ptr->link;
	}
	printf("\n"); // noch weg!!!
}

/* runs all functions if number of arguments are 2-5 or > 5 */
void	run_sorting_process(struct s_node **a_liste, struct s_node **b_liste)
{
	int	smallest_a;
	
	smallest_a = smallest_in_a(a_liste);
	//printf("drin\n");
    if (count_of_nodes(a_liste) >= 2 && count_of_nodes(a_liste) <= 5)
        little_input(a_liste, b_liste, smallest_a);
    else
    {
        set_index(a_liste);
	    lis_process(a_liste, b_liste, count_of_nodes(a_liste));
	    minimum_sorting(a_liste, b_liste, smallest_a);
    }
}

/* receiving arguments from user input. argc zählt den ersten String in argv mit und der ist immer ./a.out */
int		stack_receive(int argc, char **argv, struct s_node **a_liste, struct s_node **b_liste)
{
	struct s_node	*current;
	//struct s_node	*ptr_a;
	int				i;

	i = 1;
	if (argc < 2)
		exit(0);
	while (i < argc)
	{
		current = (struct s_node *)malloc(sizeof(struct s_node));
		if (!current)
			return(0);
		if (!error_manager_int(argv[i]) || !error_manager_outta_int(argv[i]))
		{
			free(current);
			exit(0);
		}
		add_at_end(a_liste, current, ft_atoi(argv[i]));
		i++;
	}
	current = *a_liste;
	if (current->link == NULL || !error_manager_duplicate(a_liste))
	{
		free(current);
		exit(0);
	}
	run_sorting_process(a_liste, b_liste);
	free(current);
	return(0);
}

/* identifies the smallest number in Stack a after receiving arguments. */
int	smallest_in_a(struct s_node **a_liste)
{
	int	*array_a;
	int	smallest_num;

	array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
    if (!array_a)
		return(0);
	current_a(a_liste, array_a);
	//printf("len a %d\n", len_a);
	smallest_num = min(a_liste, array_a);
	free(array_a);
	return (smallest_num);
}

/* identifies the biggest number in Stack a (checken its representative array) after receiving arguments. */
int	biggest_in_a(struct s_node **a_liste)
{
	int	*array_a;
	int	len_a;
	int	biggest_num;

	array_a = (int *)malloc((count_of_nodes(a_liste)) * sizeof(int));
    if (!array_a)
		return(0);
	len_a = current_a(a_liste, array_a) + 1;
	//printf("len a %d\n", len_a);
	biggest_num = max(array_a, len_a);
	free(array_a);
	return (biggest_num);
}
