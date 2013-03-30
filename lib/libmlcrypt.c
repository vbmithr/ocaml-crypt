#define _XOPEN_SOURCE
#include <unistd.h>
#include <time.h>

#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>

value crypt_raw(value key, value salt) {
  CAMLparam2(key, salt);

  char *result = crypt(String_val(key), String_val(salt));
  if (result == NULL)
    caml_failwith("crypt(3) returned NULL");

  CAMLreturn(caml_copy_string(result));
}

// http://www.gnu.org/software/libc/manual/html_node/crypt.html
value crypt_md5(value key) {
  CAMLparam1(key);

  unsigned long seed[2];
  char salt[] = "$1$........";
  const char *const seedchars =
    "./0123456789ABCDEFGHIJKLMNOPQRST"
    "UVWXYZabcdefghijklmnopqrstuvwxyz";
  char *password;
  int i;

  /* Generate a (not very) random seed.
     You should do it better than this... */
  seed[0] = time(NULL);
  seed[1] = getpid() ^ (seed[0] >> 14 & 0x30000);

  /* Turn it into printable characters from `seedchars'. */
  for (i = 0; i < 8; i++)
    salt[3+i] = seedchars[(seed[i/5] >> (i%5)*6) & 0x3f];

  /* Read in the user's password and encrypt it. */
  password = crypt(String_val(key), salt);

  /* Print the results. */
  CAMLreturn(caml_copy_string(password));
}
