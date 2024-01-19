/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:47:10 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/18 18:12:35 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*It frees the structure pointers*/
void	free_all(t_sc *sc)
{
	free(sc->sp.obj);
	free(sc->pl.obj);
	free(sc->cy.obj);
}
