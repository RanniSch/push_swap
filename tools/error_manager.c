/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 06:13:46 by rschlott          #+#    #+#             */
/*   Updated: 2022/10/23 17:19:00 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* checks if arguments are not integers */
void	error_manager_int(const char *ptr_a)
{
	while (*ptr_a == 32 || (*ptr_a >= 9 && *ptr_a <= 13))
		ptr_a++;
	if (*ptr_a == '-' || *ptr_a == '+')
		ptr_a++;
	if (*ptr_a == '-' || *ptr_a == '+')
	{
		write(1, "Error! More than one sign.\n", 27);
		exit(0);
	}
	while (*ptr_a != '\0')
	{
		if (!(*ptr_a > 47 && *ptr_a < 58))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		ptr_a++;
	}
}

/* checks if arguments are duplicates */
void	error_manager_duplicate(struct s_node **a_liste)
{
	struct s_node	*ptr;
	struct s_node	*next;

	ptr = *a_liste;
	next = ptr->link;
	while (ptr->link != NULL)
	{
		while (next != NULL)
		{
			if (ptr->data == next->data)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			else
				next = next->link;
		}
		ptr = ptr->link;
		next = ptr->link;
	}
}

/* modified with checker if arguments are bigger than an integer */
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
		if ((convert > 2147483647 && sign == 1) || (convert > 2147483648 && sign == -1))
		{
			write(1, "Error\n", 6);
			exit(0);
		}
	}
	return (convert * sign);
}
