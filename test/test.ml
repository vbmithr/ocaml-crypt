let () =
  let buf = Bytes.create 256 in
  let pwlen = Crypt.crypt_md5 buf "bleh" in
  let password = Bytes.sub_string buf 0 pwlen in
  Printf.printf "%s\n" password
