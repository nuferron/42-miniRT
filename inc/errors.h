/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:07:57 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/07 19:09:04 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERROR "\033[1;31mError\n\033[0m"
# define WARN "\033[1;33mWarning\n\033[0m"

# define ARGS "Invalid number of arguments: you must provide ONE file *.rt\n"
# define FNF "File not found: "
# define TYPE "The file must end with the extension \".rt\"\n"
# define EMPTY "This file is empty!\n"
# define LINE "Invalid line: "
# define MEM "Memory problems\n"
# define RANGE "The input is either invalid or out of range "
# define REPE "Repeated element: "
# define INT "Found float when expecting integer: "
# define PARAM "Invalid number of parameters in line "
# define ELEM "Element not found: "
# define MUST "There must be ONE \"A\", ONE \"C\" and ONE \"L\" element\n"
# define SIZE "Length must be greater than 0\n"
# define BIG "Huge number detected in line: "
# define REC "We recommend you to work with lower numbers\n"
# define UNNORM "Unnormalized vector found in line "
# define NORM "We'll work with its normalized version\n"
# define CAM "Your camera is inside of an object. \
Change the position to see the world.\n"
#endif
