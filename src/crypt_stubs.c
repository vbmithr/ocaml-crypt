#include <string.h>
#include <unistd.h>
#include <time.h>

#include <caml/mlvalues.h>

CAMLprim value ml_crypt(value buf, value key, value salt) {
  int pwlen;
  char *password = crypt(String_val(key), String_val(salt));

  if (password == NULL)
      return Val_int(-1);

  pwlen = strlen(password);
  memcpy(String_val(buf), password, pwlen);
  return Val_int(pwlen);
}

// http://www.gnu.org/software/libc/manual/html_node/crypt.html
value ml_crypt_md5(value buf, value key) {
  unsigned long seed[2];
  char salt[] = "$1$........";
  const char *const seedchars =
    "./0123456789ABCDEFGHIJKLMNOPQRST"
    "UVWXYZabcdefghijklmnopqrstuvwxyz";
  char *password;
  int i, pwlen;

  /* Generate a (not very) random seed.
     You should do it better than this... */
  seed[0] = time(NULL);
  seed[1] = getpid() ^ (seed[0] >> 14 & 0x30000);

  /* Turn it into printable characters from `seedchars'. */
  for (i = 0; i < 8; i++)
    salt[3+i] = seedchars[(seed[i/5] >> (i%5)*6) & 0x3f];

  /* Read in the user's password and encrypt it. */
  password = crypt(String_val(key), salt);
  pwlen = strlen(password);

  /* Print the results. */
  memcpy(String_val(buf), password, pwlen);
  return Val_int(pwlen);
}
