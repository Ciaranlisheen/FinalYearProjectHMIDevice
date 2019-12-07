# invoke SourceDir generated makefile for empty_min.pem3
empty_min.pem3: .libraries,empty_min.pem3
.libraries,empty_min.pem3: package/cfg/empty_min_pem3.xdl
	$(MAKE) -f D:\Code\empty_min_CC2650_LAUNCHXL_TI/src/makefile.libs

clean::
	$(MAKE) -f D:\Code\empty_min_CC2650_LAUNCHXL_TI/src/makefile.libs clean

