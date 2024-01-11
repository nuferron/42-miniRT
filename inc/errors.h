/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:07:57 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/11 22:12:19 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

#define ERROR	RED "Error\n" RESET
#define ARGS	ERROR "Invalid number of arguments: " \
				"you must provide ONE file *.rt\n" RESET
#define FNF		ERROR "File not found: %s\n" RESET
#define TYPE	ERROR "The file must end with the extension \".rt\"\n" RESET
#define EMPTY	ERROR "This file is empty!\n" RESET
#define LINE	ERROR "Invalid line: \"%s\"\nProgram stopped\n" RESET
#define MEM		ERROR "Memory problems\n" RESET
#define RANGE	ERROR "In line \"%s\", the input is either invalid " \
				"or out of range ([%d - %d])\n" RESET
#define REPE	ERROR "Element repeated: %s\n" RESET

#endif
