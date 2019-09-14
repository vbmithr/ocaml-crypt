let () =
  let buf = String.init 256 (fun _ -> 'a') in
  let pwlen = Crypt.crypt_md5 buf "bleh" in
  let password = String.sub buf 0 pwlen in
  Printf.printf "%s\n" password
