# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 11:36:57 by nsainton          #+#    #+#              #
#    Updated: 2023/05/05 16:57:16 by nsainton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= so_long

PROG:= $(NAME).c

SRCS_DIR:= sources

SRCS_SUBDIRS:= $(shell find $(SRCS_DIR) -type d)

SRCS_NAMES:= $(subst $(SRCS_DIR)/,, $(foreach dir, $(SRCS_SUBDIRS), $(wildcard $(dir)/*.c)))

SRCS:= $(addprefix $(SRCS_DIR)/, $(SRCS_NAMES))

OBJS_DIR:= objects

OBJS_NAMES:= $(SRCS_NAMES:.c=.o)

OBJS:= $(addprefix $(OBJS_DIR)/, $(OBJS_NAMES))

INCS_DIR:= includes

INCS:= $(wildcard $(INCS_DIR)/*)

DEPS_DIR:= dependencies

DEPS:= $(patsubst %.c, $(DEPS_DIR)/%.d, $(SRCS_NAMES) $(PROG))

LIBS_DIR ?= $(addprefix $(shell pwd)/, libs)

LFT_URL := "git@github.com:nsainton/libft.git"

LFT_DIR:= $(addprefix $(LIBS_DIR)/, libft)

LFT_NAME:= libft.a

LFT_ABBR:= -lft

LFT:= $(addprefix $(LFT_DIR)/, $(LFT_NAME))

MLX_URL:= "git@github.com:42Paris/minilibx-linux.git"

MLX_DIR:= $(addprefix $(LIBS_DIR)/, minilibx-linux)

MLX_NAME:= libmlx.a

MLX_ABBR:= -lmlx -lXext -lX11

ABBRS:= $(LFT_ABBR) $(MLX_ABBR)

CC:= cc

CFLAGS:= -Wall -Wextra -Werror

HEADER_SCRIPT_DIR:= ../../Header

HEADER_EXEC:= header

HEADER_SCRIPT:= $(addprefix $(HEADER_SCRIPT_DIR)/, $(HEADER_EXEC))

HEADER_NAME:= $(NAME).h

FUNCS_HEADER:= $(addprefix $(INCS_DIR)/, $(HEADER_NAME))

GIT_ADD:= --all

export C_INCLUDE_PATH=$(INCS_DIR):$(LFT_DIR)/$(INCS_DIR):$(MLX_DIR)
export LIBRARY_PATH=$(LFT_DIR):$(MLX_DIR)

.PHONY: all

all: | $(LFT_DIR) $(MLX_DIR)
	$(MAKE) -C $(LFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(GG) $(OPT) $(PROG) $(OBJS) \
	-MD -MF $(DEPS_DIR)/$(NAME).d $(ABBRS) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(LFT)
	[ -d $(@D) ] || mkdir -p $(@D)
	arg="$$(dirname $(DEPS_DIR)/$*)"; \
	[ -d $$arg ] || mkdir -p $$arg
	$(CC) $(CFLAGS) $(GG) $(OPT) -MD -MF $(DEPS_DIR)/$*.d -c $< -o $@

$(LFT_DIR):
	git clone $(LFT_URL) $(LFT_DIR)

$(MLX_DIR):
	git clone $(MLX_URL) $(MLX_DIR)

.PHONY: clean
clean:
	$(RM) -r $(OBJS_DIR)
	$(RM) -r $(DEPS_DIR)

.PHONY: oclean
oclean:
	$(RM) $(NAME)

.PHONY: lclean
lclean:
	$(RM) $(LIBS_DIR)

.PHONY: fclean
fclean:
	$(MAKE) clean
	$(MAKE) oclean
	$(MAKE) lclean

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE)

.PHONY: debug
debug:
	$(MAKE) fclean
	$(MAKE) GG=-g3 OPT=-O0

.PHONY: git
git:
	git add $(GIT_ADD)
	git commit
	git push

.PHONY: makedebug
makedebug:
	@echo $(DEPS)
	@echo GIT_ADD : $(GIT_ADD)

.PHONY: header

ifndef HEADER_SCRIPT
$(error HEADER_SCRIPT is not set)
endif
ifndef FUNCS_HEADER
$(error FUNCS_HEADER is not set)
endif

header:
	$(MAKE) -C $(HEADER_SCRIPT_DIR)
	$(HEADER_SCRIPT) ./$(SRCS_DIR) $(FUNCS_HEADER)

-include $(DEPS)
