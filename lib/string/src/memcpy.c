/*
** memcpy.c for string in /home/lecouv_v/LokiOS/kernel/lib/string
** 
** Made by Victorien LE COUVIOUR--TUFFET
** Login   <lecouv_v@epitech.net>
** 
** Started on  Thu Jul 23 18:06:03 2015 Victorien LE COUVIOUR--TUFFET
** Last update Thu Jul 23 18:14:54 2015 Victorien LE COUVIOUR--TUFFET
*/

#include <stddef.h>
#include "types.h"

void		*memcpy(void *const dest, void const *src, size_t const n)
{
  size_t	i;

  i = 0;
  while (i < n)
    {
      ((byte *)dest)[i] = ((byte *)src)[i];
      i++;
    }
  return (dest);
}
