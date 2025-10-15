# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmauley <cmauley@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/08 18:13:41 by cmauley           #+#    #+#              #
#    Updated: 2025/10/15 23:33:47 by cmauley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# fichiers source .c de la lib #
SRCS		=		ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
					ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
					ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
					ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
					ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
					ft_toupper.c ft_split.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c


# changements des .c en .o #
OBJS		=		$(SRCS:.c=.o)

# fichiers bonus #

# changements des fichiers bonus .c en .o #

# commandes #
CC			=		gcc
RM			=		rm -f
CFLAGS		=		-Wall -Wextra -Werror -I.

# Nom de la lib #
NAME		=		libft.a

# ========== REGLES ======= #

# Regle principale : "all" executee par defaut #
all:				$(NAME)

# Regle pour construire la librairie #
$(NAME):			$(OBJS)
					ar rcs $(NAME) $(OBJS)

# Supprimer les fichiers objets (.o) #
clean:
					$(RM) $(OBJS)

# Supprimer tout (objets + librairie) #
fclean:				clean
					$(RM) $(NAME)

# tout recompiler #
re:					fclean all

# cibles pour eviter les conflits de noms #
.PHONY:				all clean fclean re




