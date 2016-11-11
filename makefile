all:
	cd src; make
	cd src; cp rlc-resolution ../
	
install:
	cd src; make install
	
clean:
	cd src; make clean
