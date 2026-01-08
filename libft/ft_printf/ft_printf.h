/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvazquez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:41:05 by mvazquez          #+#    #+#             */
/*   Updated: 2025/12/26 18:07:36 by mvazquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
void	ft_putchar_pf(char c, size_t *counter);
void	ft_putstr_pf(char *s, size_t *counter);
void	ft_puthex_pf(unsigned int nbr, int uppercase, size_t *counter);
void	ft_putnbr_pf(int n, size_t *counter);
void	ft_putunbr_pf(unsigned int n, size_t *counter);
void	ft_putptr_pf(void *ptr, size_t *counter);

#endif
