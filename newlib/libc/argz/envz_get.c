/* Copyright (C) 2002 by  Red Hat, Incorporated. All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software
 * is freely granted, provided that this notice is preserved.
 */

#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <envz.h>

extern int buf_findstr(const char *str, char **buf, size_t *buf_len);

char *
envz_get (const char *envz, size_t envz_len, const char *name)
{
  const char *buf_ptr = envz;
  size_t buf_len = envz_len;

  while(buf_len)
    {
      if (buf_findstr(name, &buf_ptr, &buf_len))
        {
          if (*buf_ptr == '=')
            {
              buf_ptr++;
              return buf_ptr;
            }
          else
            {
              if (*buf_ptr == '\0')
                /* NULL entry. */
                return NULL;
            }
        }
    }
  /* No matching entries found. */
  return NULL;
}