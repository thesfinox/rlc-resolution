all:
	cd src; make
	cd src; cp rlcsolve ../
	
install:
	cd src; make install
	
clean:
	cd src; make clean
