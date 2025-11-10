module C = Configurator.V1

let () =
  C.main ~name:"crypt" begin fun c ->
      if C.ocaml_config_var_exn c "system" = "macosx" then
        C.Flags.write_sexp "c_library_flags.sexp" []
      else C.Flags.write_sexp "c_library_flags.sexp" [ "-lcrypt" ]
    end
