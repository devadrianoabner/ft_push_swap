/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:10:08 by adrianda          #+#    #+#             */
/*   Updated: 2026/07/16 13:10:48 by adrianda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
