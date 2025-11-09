#include <crypt.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/alloc.h>
#include <caml/memory.h>

CAMLprim value ml_crypt(value key, value salt)
{
  CAMLparam2(key, salt);
  CAMLlocal1(key_hash_value);

  char *key_hash = crypt(String_val(key), String_val(salt));

  if (key_hash == NULL)
    caml_failwith("key_hash is NULL");

  key_hash_value = caml_alloc_initialized_string(strlen(key_hash), key_hash);

  CAMLreturn(key_hash_value);
}

CAMLprim value ml_crypt_md5(value key)
{
  CAMLparam1(key);
  CAMLlocal1(key_hash_value);

  unsigned long seed[2];
  char salt[] = "$1$........";
  const char *const seedchars =
      "./0123456789ABCDEFGHIJKLMNOPQRST"
      "UVWXYZabcdefghijklmnopqrstuvwxyz";

  /* Generate a (not very) random seed.
   You should do it better than this... */
  seed[0] = time(NULL);
  seed[1] = getpid() ^ (seed[0] >> 14 & 0x30000);

  /* Turn it into printable characters from `seedchars'. */
  for (int i = 0; i < 8; i++)
    salt[3 + i] = seedchars[(seed[i / 5] >> (i % 5) * 6) & 0x3f];

  /* Read in the user's password and encrypt it. */
  char *key_hash = crypt(String_val(key), salt);

  key_hash_value = caml_alloc_initialized_string(strlen(key_hash), key_hash);

  CAMLreturn(key_hash_value);
}
