all:
	cd lib && $(MAKE)
	cd test && $(MAKE)

install:
	ocamlfind install crypt lib/crypt* lib/dll* lib/lib* lib/META

uninstall:
	ocamlfind remove crypt

reinstall:
	$(MAKE) uninstall
	$(MAKE) install

clean:
	cd lib && $(MAKE) clean
	cd test && $(MAKE) clean
