open Crypt

let () = if Array.length Sys.argv < 2 then
    Printf.eprintf "Usage: %s <key>\n" Sys.argv.(0)
  else
    print_endline (crypt_md5 Sys.argv.(1))
