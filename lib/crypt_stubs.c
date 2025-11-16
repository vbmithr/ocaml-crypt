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

#if defined(__linux__) || defined(__FreeBSD__)

CAMLprim value ml_crypt(value key, value salt)
{
  CAMLparam2(key, salt);
  CAMLlocal1(key_hash_value);

  struct crypt_data data;
  data.initialized = 0;

  const char *key_hash =
      crypt_r(String_val(key), String_val(salt), &data);

  if (key_hash == NULL)
    caml_failwith("crypt_r: fail to hash the key");

  key_hash_value = caml_copy_string(key_hash);

  CAMLreturn(key_hash_value);
}

#else

CAMLprim value ml_crypt(value key, value salt)
{
  CAMLparam2(key, salt);
  CAMLlocal1(key_hash_value);

  char *key_hash = crypt(String_val(key), String_val(salt));

  if (key_hash == NULL)
    caml_failwith("crypt: fail to hash the key");

  key_hash_value = caml_copy_string(key_hash);

  CAMLreturn(key_hash_value);
}

#endif

#ifdef __APPLE__
#include <stdlib.h>

CAMLprim value ml_macosx_encrypt(value buffer, value edfalg)
{
  encrypt(Bytes_val(buffer), Int_val(edfalg));
  return Val_unit;
}

CAMLprim value ml_macosx_setkey(value key)
{
  setkey(String_val(key));
  return Val_unit;
}

#endif
