/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:07:57 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 17:35:20 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#define ERROR	RED "Error\n" RESET
#define ARGS	ERROR "Invalid number of arguments: " \
				"you must provide ONE file *.rt\n"
#define FNF		ERROR "File not found: %s\n"
#define TYPE	ERROR "The file must end with the extension \".rt\"\n"
#define EMPTY	ERROR "This file is empty!\n"
#define LINE	ERROR "Invalid line: %s\nProgram stopped\n"

#endif
