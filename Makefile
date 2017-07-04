# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/12 09:31:31 by mrassokh          #+#    #+#              #
#    Updated: 2017/06/05 18:07:07 by elyahove         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	RT

#[----------------------------------HEADERS-----------------------------------]#

HEADERS			=	$(RT_H) $(LIBFT_H)
HEADERS_PATH	=	./includes/
LIBFT_H			=	./includes/libft/includes

#[---------------------------------LIBRARIES----------------------------------]#

LIBPATH = ./libs/
LIBMLX = -L ./includes/minilibx/ -lft
LIBFT = lft
LIBVECTOR = lvector
LIBFTPATH = $(LIBPATH)libft
LIBVECTORPATH = $(LIBPATH)libvector
LIBS = $(LIBFT) $(LIBVECTOR)

#[--------------------------------COMPILATION---------------------------------]#

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror -g
MLX_FLAG		=	-lmlx -framework OpenGL -framework AppKit

#[----------------------------------SOURCES-----------------------------------]#

SRC_PATH 	= ./src/

SHAPES_PATH = $(SRC_PATH)shapes/

LIGHTS_PATH = $(SRC_PATH)lights/

TRANSL_PATH	= $(SRC_PATH)translation/

KHOOK_PATH	= $(SRC_PATH)keyhooks/

SECOND_RAY_PATH	= $(SRC_PATH)secondary_rays/

CAMERA_PATH = $(SRC_PATH)camera/

IMG_PR_PATH	= $(SRC_PATH)image_processing/

LIM_SH_PATH = $(SRC_PATH)limited_shapes/

GENERAL 	=	rt.c error.c				\
				read_file.c					\
				read_contrast.c				\
				read_file_processing.c		\
				fill_object_list.c			\
				new_main_objects.c			\
				new_main_objects_part_2.c	\
				parsing_func.c				\
				fill_object_data.c			\
				fill_object_data_part_2.c	\
				fill_object_data_part_3.c	\
				parsing.c					\
				parsing_part_2.c			\
				shading.c					\
				object_add.c				\
				validation.c				\
				new_lights.c				\
				light_parsing.c				\
				render.c					\
				cast_ray.c					\
				fill_light_data.c			\
				fill_light_data_processing.c\
				read_normal_map.c			\
				read_texture.c				\
				fill_common.c				\
				color.c						\
				fill_object_base_data.c		\
			  	fill_object_base_data_part_2.c 	\
				shading_set.c				\
				ray_creation.c				\
				vector.c					\
				preparing.c					\
				calculate_light.c			\
				quadric.c					\
				quartic_part1.c				\
				quartic_part2.c				\
				quartic_part3.c				\
				quartic_part4.c				\
				bump_mapping.c				\
				work_with_obj_part_1_parsing.c \
				work_with_obj_part_2_add_to_list.c \

SHAPES 		= common.c			\
			  sphere_1.c		\
			  sphere_2.c		\
			  plain_1.c			\
			  plain_2.c			\
			  cylinder_1.c		\
			  cylinder_2.c		\
			  cone_1.c			\
			  cone_2.c			\
			  ellipsoid.c		\
			  hyperboloid.c 	\
			  torus_part1.c 	\
			  torus_part2.c		\
			  triangle.c		\
			  triangle_t.c


LIGHTS		= direct_light.c	\
			  parallel_light.c 	\
			  point_light.c		\
			  light_intensity.c

TRANSL		= initial_translation.c \
			  moving.c 				\
			  rotation.c			\
			  lights_translations.c	\
			  lights_translations2.c\
			  rotation_part_2.c		\
			  moving_part_2.c		\
			  utility.c


KEY_HOOKS	= init_hooks.c			\
			  button_press_hook.c	\
			  button_release_hook.c	\
			  key_press_hook.c		\
			  key_release_hook.c	\
			  camera_rotation_hooks.c\
			  window_destroyed_hook.c

SECOND_RAY = reflection.c \
			 refraction.c \
			 refraction_list/add_elem.c \
			 refraction_list/new_elem.c \
			 refraction_list/get_elem.c \
			 refraction_list/del_elem.c \
			 refraction_list/copy_lst.c \
			 refraction_list/get_prev_elem.c\
			 refraction_list/clear_refracted.c

CAMERA	   = init_camera.c

IMG_PR	   = black_and_white.c sepia.c negative.c contrast.c

LIM_SH	   =  disc.c disc2.c

SRC = $(addprefix $(SRC_PATH),$(GENERAL)) $(addprefix $(LIGHTS_PATH),$(LIGHTS)) \
	$(addprefix $(SHAPES_PATH),$(SHAPES)) $(addprefix $(TRANSL_PATH),$(TRANSL)) \
	$(addprefix $(KHOOK_PATH),$(KEY_HOOKS)) $(addprefix $(CAMERA_PATH), $(CAMERA)) \
	$(addprefix $(SECOND_RAY_PATH),$(SECOND_RAY)) $(addprefix $(IMG_PR_PATH), $(IMG_PR)) \
	$(addprefix $(LIM_SH_PATH),$(LIM_SH))

OBJ = $(SRC:.c=.o)

#[-----------------------------------COLORS-----------------------------------]#

GREEN			=	\033[32m
RESET			=	\033[39m
YELLOW			=	\033[33m
RED				=	\033[31m

#[------------------------------------MAKE------------------------------------]#

.PHONY: make_libs
.PHONY: cc_libft
.PHONY: cc_libvector

all: $(NAME)

$(NAME): make_libs $(OBJ)
	@ $(CC) $(FLAGS) -o $(NAME) $(OBJ) -I ./includes $(LIBMLX) $(MLX_FLAG) -L$(LIBPATH) -$(LIBFT) -$(LIBVECTOR) -g
	@ echo "$(GREEN)[$(NAME)]$(RESET)"

%.o:%.c
	@ $(CC) $(FLAGS) -c -o $@ $< -I $(HEADERS_PATH)
	@ printf ' $(GREEN)[add]$(RESET) $<\n'


clean: make_clean_libs
	@ rm -f $(OBJ)
	@ echo "$(YELLOW)[clean]$(RESET)"

fclean: clean fclean_libs
	@ rm -f $(NAME) $(NAMELIB)
	@ echo "$(RED)[fclean]$(RESET)"

re: fclean all

make_libs: cc_libft cc_libvector

cc_libft:
	@cd $(LIBFTPATH);\
	make;\
	cp libft.a ../;

cc_libvector:
	@cd $(LIBVECTORPATH);\
	make;\
	cp libvector.a ../;

make_clean_libs:
	@cd $(LIBFTPATH);\
	make clean
	@cd $(LIBVECTORPATH);\
	make clean

fclean_libs:
	@cd $(LIBFTPATH);\
	make fclean
	@cd $(LIBVECTORPATH);\
	make fclean
	@ rm -f $(LIBPATH)libft.a
	@ echo "$(RED)[libft fclean]$(RESET)"
	@ rm -f $(LIBPATH)libvector.a
	@ echo "$(RED)[libvector fclean]$(RESET)"
