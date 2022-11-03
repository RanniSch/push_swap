/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:23:03 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/03 12:48:24 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* modified for only changing char to int */
int	ft_atoi(const char *str)
{
	int			sign;
	long int	convert;

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
	}
	return (convert * sign);
}

/* adds a new node to the list */
int	add_at_end(struct s_node **a_liste, struct s_node *current, int data)
{
	struct s_node	*ptr_a;

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
	return (0);
}

/* runs all functions if number of arguments are 2-5 or > 5 */
void	run_sorting_process(struct s_node **a_liste, struct s_node **b_liste)
{
	int	smallest_a;

	smallest_a = smallest_in_a(a_liste);
	if (count_of_nodes(a_liste) >= 2 && count_of_nodes(a_liste) <= 5)
		little_input(a_liste, b_liste, smallest_a);
	else
	{
		set_index(a_liste);
		lis_process(a_liste, b_liste, count_of_nodes(a_liste));
		minimum_sorting(a_liste, b_liste, smallest_a);
	}
}

/* deletes the whole list from head until NULL */
void	del_list(struct s_node **a_liste)
{
	struct s_node	*ptr_a;
	struct s_node	*temp;

	ptr_a = *a_liste;
	temp = *a_liste;
	while (ptr_a != NULL)
	{
		temp = ptr_a;
		ptr_a = ptr_a->link;
		free(temp);
	}
	free(ptr_a);
}

/* receiving args from user input. argc counts first string 
of argv (./a.out) as well */
int	stack_receive(int argc, char **argv, struct s_node **a_liste,
		struct s_node **b_liste)
{
	struct s_node	*current;
	struct s_node	*ptr_a;
	int				i;

	i = 0;
	if (argc < 2)
		exit(0);
	while (++i < argc)
	{
		current = (struct s_node *)malloc(sizeof(struct s_node));
		if (!current)
			return (0);
		if (!error_manager_int(argv[i]) || !error_manager_outta_int(argv[i]))
		{
			free(current);
			del_list(a_liste);
			exit(0);
		}
		add_at_end(a_liste, current, ft_atoi(argv[i]));
	}
	ptr_a = *a_liste;
	ft_more_exit(a_liste, ptr_a);
	run_sorting_process(a_liste, b_liste);
	del_list(a_liste);
	return (0);
}
