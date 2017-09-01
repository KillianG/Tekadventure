##
## Makefile for tekadventure in /home/segfault/Delivery/Alpha/tekadventure/mark
## 
## Made by Marc PEREZ
## Login   <marc.perez@epitech.eu>
## 
## Started on  Fri Aug 25 13:40:28 2017 Marc PEREZ
## Last update Fri Aug 25 13:40:30 2017 Marc PEREZ
##

all:
	make -C client
	make -C server

debug:
	make debug -C client
	make debug -C server

clean:
	make clean -C client
	make clean -C server

fclean:
	make fclean -C client
	make fclean -C server

re: fclean all

.PHONY: all debug clean fclean re
