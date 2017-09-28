#include <unistd.h>
#include "stdio.h"
#include "client.h"

int		main(int argc, char **argv)
{
  t_player	*my_player;
  t_player	*his_player;

  if (argc == 3)
    {
      my_player = malloc(sizeof(*my_player));
      memset(my_player, 0, sizeof(*my_player));
      my_player->id = init_connection(argv[1], argv[2]);
      my_player->shoot = my_player->id + 1;
      while (1)
	{
	  sleep(3);
	  send_data(my_player);
	  if (!(his_player = receive_data()))
	    continue;
	  printf("His player ID:%i, SHOOT:%i\n", his_player->id, his_player->shoot);
	  if (his_player->shoot == my_player->id)
	    printf("He shot me\n");
	  else
	    printf("He missed\n");
	  free(his_player);
	}
      printf("DONE\n");
    }
  else
    printf("USAGE: %s IP PORT\n", argv[0]);
  return (0);
}
