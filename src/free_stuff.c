/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:47:10 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/11 21:27:20 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_obj(void *obj)
{
	while (obj)
		free(obj++);
}

void	free_all(t_sc *sc)
{
	free(sc->amb);
	free(sc->cam);
	free(sc->light);
	free_obj((void *)(sc->sp));
	free_obj((void *)(sc->pl));
	free_obj((void *)(sc->cy));
}
