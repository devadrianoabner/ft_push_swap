/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:10:08 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/23 18:33:36 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_vector(char **vector)
{
	int	i;

	if (!vector)
		return ;
	i = 0;
	while (vector[i])
	{
		free(vector[i]);
		i++;
	}
	free(vector);
}
