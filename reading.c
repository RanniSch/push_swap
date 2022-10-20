/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:23:03 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/20 06:29:27 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* converts char to int */
/*int ft_atoi(const char *str)
{
	int				sign;
	long int		convert;
	struct s_node	*ptr;
	struct s_node	*current;

	sign = 1;
	convert = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	while (*str && *str > 47 && *str < 58)
	{
		convert = (convert * 10) + *str - '0';
		str++;
		if (convert > 2147483647 && sign == 1)
			return (-1);
		if (convert > 2147483648 && sign == -1)
			return (0);
	}
	return (convert * sign);
}*/
/* adds a new node to the list */
void	add_at_end(struct s_node **a_liste, int data)
{
	struct s_node *ptr;
    struct s_node *current;

    ptr = *a_liste;
	current = (struct s_node *)malloc(sizeof(struct s_node));
	current->data = data;
	current->link = NULL;
	if (ptr != NULL)
	{
		while (ptr->link != NULL)
		{
			ptr = ptr->link;
		}
		ptr->link = current;
	}
	else
		*a_liste = current;
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
	printf("\n");
	//printf("\nnumber of nodes: %d\n", count_of_nodes(liste));      
		// insert printf function!!!!!!!!!!!
}

/* receiving arguments from user input */
void	stack_receive(int argc, char **argv, struct s_node **a_liste)
{
	struct s_node	*ptr;
	int				i;

	i = 1;
	/* argc zählt den ersten String in argv mit und der ist immer ./a.out */
	if (argc >= 2)
	{
		while (i < argc)
		{
			error_manager_int(argv[i]);
			add_at_end(a_liste, ft_atoi(argv[i]));
			i++;
		}
		ptr = *a_liste;
		if (ptr->link == NULL)
		{
			printf("%d\n", ptr->data);
			exit(0);
		}
		error_manager_duplicate(a_liste);
	}
	else
	{
		write(1, "No input! Input some numbers!\n", 30);
		exit(0);
	}
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

/* identifies the biggest number in Stack a after receiving arguments. */
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

int	main(int argc, char **argv)
{
	struct s_node	*a_liste;
	struct s_node	*b_liste;
	int	smallest_a;
	int	biggest_a;

	a_liste = NULL;
	b_liste = NULL;
	/* &a_liste gibt die Adresse des Pointers,
		der zur Liste zeigt durch = double pointer */
	stack_receive(argc, argv, &a_liste);
	print_stack(&a_liste);
	smallest_a = smallest_in_a(&a_liste);
	biggest_a = biggest_in_a(&a_liste);
	//printf("smallest a %d\n", smallest_in_a(&a_liste));
	//printf("biggest a %d\n", biggest_in_a(&a_liste));
	set_index(&a_liste);
	lis_process(&a_liste, &b_liste, count_of_nodes(&a_liste));
	minimum_sorting(&a_liste, &b_liste, smallest_a, biggest_a);
	return (0);
}
