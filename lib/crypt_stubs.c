#include <string.h>
#include <time.h>
#include <unistd.h>

#ifdef __linux__
#include <crypt.h>
#endif

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
    caml_failwith("fail to hash the key");

  key_hash_value = caml_copy_string(key_hash);

  CAMLreturn(key_hash_value);
}
