/*
** start_music.c<2> for epikong in /home/kersal_e/Dropbox/rush1 (1)/last_version/etape_2
**
** Made by Elliot Kersale
** Login   <kersal_e@epitech.net>
**
** Started on  Sat Mar  8 23:09:32 2014 Elliot Kersale
** Last update Sun Mar  9 17:27:55 2014 Elliot Kersale
*/

#include		"epikong.h"

int			start_music(t_map *map)
{
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      fprintf(stderr, "%s\n", Mix_GetError());
      return (EXIT_FAILURE);
    }
  Mix_AllocateChannels(10);
  map->sound_jump = Mix_LoadWAV(JUMP);
  map->sound_life = Mix_LoadWAV(SLIFE);
  map->sound_key = Mix_LoadWAV(SKEY);
  map->sound_door = Mix_LoadWAV(SDOOR);
  if (!map->sound_jump || !map->sound_life || !map->sound_key ||
      !map->sound_door)
    fprintf(stderr, "Mix_LoadWAV: %s\n", Mix_GetError());
  map->music = Mix_LoadMUS(AMBIANCE);
  Mix_VolumeChunk(map->sound_jump, MIX_MAX_VOLUME);
  Mix_PlayMusic(map->music, -1);
  return (EXIT_SUCCESS);
}

void			start_death_music(t_map *map)
{
  Mix_FreeMusic(map->music);
  if (map->hero->is_alive == FALSE)
    map->music = Mix_LoadMUS("./music/gameover.wav");
  else
    map->music = Mix_LoadMUS("./music/winner.wav");
  if (!map->music)
    {
      fprintf(stderr, "Mix_LoadMUS: %s\n", Mix_GetError());
      return ;
    }
  Mix_PlayMusic(map->music, -1);
}

void      	       	start_intro()
{
  Mix_Music		*music;

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		    MIX_DEFAULT_CHANNELS, 1024) == -1)
    {
      fprintf(stderr, "%s\n", Mix_GetError());
      return ;
    }
  Mix_AllocateChannels(10);
  music = Mix_LoadMUS(INTRO_MUSIC);
  if (!music)
    {
      fprintf(stderr, "Mix_LoadMUS: %s\n", Mix_GetError());
      return ;
    }
  Mix_PlayMusic(music, -1);
}

void			do_effects(Mix_Chunk *sound)
{
  if (sound != NULL)
    Mix_PlayChannel(-1, sound, 0);
}
