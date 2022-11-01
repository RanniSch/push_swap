/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 06:13:46 by rschlott          #+#    #+#             */
/*   Updated: 2022/11/01 06:38:41 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* checks if arguments are not integers */
bool	error_manager_int(const char *str)
{
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '-' || *str == '+')
	{
		write(1, "Error\n", 6);
		return(false);
	}
	while (*str != '\0')
	{
		if (!(*str > 47 && *str < 58))
		{
			write(1, "Error\n", 6);
			return(false);
		}
		str++;
	}
	return(true);
}

/* checks if arguments are duplicates */
bool	error_manager_duplicate(struct s_node **a_liste)
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
				return(false);
			}
			else
				next = next->link;
		}
		ptr = ptr->link;
		next = ptr->link;
	}
	return(true);
}

/* checks if arguments are smaller or bigger than an int */
bool	error_manager_outta_int(const char *str)
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
			return(false);
		}
	}
	return (true);
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
	}
	return (convert * sign);
}
