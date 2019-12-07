# invoke SourceDir generated makefile for rfExamples.pem3
rfExamples.pem3: .libraries,rfExamples.pem3
.libraries,rfExamples.pem3: package/cfg/rfExamples_pem3.xdl
	$(MAKE) -f D:\Code\rfPacketRx_CC2650_LAUNCHXL_TI/src/makefile.libs

clean::
	$(MAKE) -f D:\Code\rfPacketRx_CC2650_LAUNCHXL_TI/src/makefile.libs clean

