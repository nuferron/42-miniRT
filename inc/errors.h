/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:07:57 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 15:48:02 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#define ERROR	RED "Error\n" RESET
#define ARGS	ERROR "Invalid number of arguments: " \
				"you must provide ONE file *.rt"
#define FNF		ERROR "File not found:"
#define TYPE	ERROR "The file must end with the extension \".rt\""

#endif
