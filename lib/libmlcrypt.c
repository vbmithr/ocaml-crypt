#define _XOPEN_SOURCE
#include <unistd.h>

#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/mlvalues.h>

value ml_crypt(value key, value salt) {
  CAMLparam2(key, salt);
  char * result = crypt(String_val(key), String_val(salt));
  if (result == NULL)
    caml_failwith("crypt error");
  CAMLreturn(copy_string(result));
}
