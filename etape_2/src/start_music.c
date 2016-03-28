/*
** start_music.c<2> for epikong in /home/kersal_e/Dropbox/rush1 (1)/last_version/etape_2
**
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
**
** Started on  Sat Mar  8 23:09:32 2014 Elliot Kersale
** Last update Sun Mar  9 17:06:31 2014 abgral_f
*/

#include		"epikong.h"

Mix_Chunk		*jump;

int			start_music()
{
  Mix_Music		*music;

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      fprintf(stderr, "%s\n", Mix_GetError());
      return (EXIT_FAILURE);
    }
  Mix_AllocateChannels(3);
  jump = Mix_LoadWAV(JUMP);
  if (!jump)
    fprintf(stderr, "Mix_LoadWAV: %s\n", Mix_GetError());
  music = Mix_LoadMUS(AMBIANCE);
  Mix_VolumeChunk(jump, MIX_MAX_VOLUME);
  Mix_PlayMusic(music, -1);
  return (EXIT_SUCCESS);
}

void			do_effects()
{
  Mix_PlayChannel(-1, jump, 0);
}
