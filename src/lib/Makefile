CC:= /usr/bin/gcc
AR:= /usr/bin/ar

CPPFLAGS:= -I ../include/ -Wall -DLINUX -D_GNU_SOURCE

SRCS:= $(shell ls *.c)
LIBS:= liberror.a liberpa.a liberrpetwst.a libersnpm.a liberlf.a libersfcflrtw.a libertw.a libercc2is2itsd.a \
 libersprfsesfwnbacceldss.a liberittncitm.a liberpopflpdvtmsiwnsp.a

all: $(LIBS)

libcp1.a libcp2.a libcp3.a libcp5.a libcp6.a libcp7.a libcp9.a libcp11.a libcp12.a: liberror.a
	ln -sf $< $@

libcp4.a: liberpa.a
	ln -sf $< $@

libcp8.a: liberrpetwst.a
	ln -sf $< $@

libcp10.a: libersnpm.a
	ln -sf $< $@

libcp13.a: liberlf.a
	ln -sf $< $@

libcp14.a: libersfcflrtw.a
	ln -sf $< $@

libcp15.a: libertw.a
	ln -sf $< $@

libcp16.a: libercc2is2itsd.a
	ln -sf $< $@

libcp17.a: libersprfsesfwnbacceldss.a
	ln -sf $< $@

libcp18.a: liberittncitm.a
	ln -sf $< $@

libcp19.a: liberpopflpdvtmsiwnsp.a
	ln -sf $< $@

liberror.a: error.o
	$(AR) -rsv $@ $?

liberpa.a: error.o pathalloc.o
	$(AR) -rsv $@ $?

liberrpetwst.a: error.o prexit.o tellwait.o system.o
	$(AR) -rsv $@ $?

libersnpm.a: error.o signal.o prmask.o
	$(AR) -rsv $@ $?

liberlf.a: error.o lockfile.o
	$(AR) -rsv $@ $?

libersfcflrtw.a: error.o lockfile.o setfl.o clrfl.o lockreg.o tellwait.o
	$(AR) -rsv $@ $?

libertw.a: error.o tellwait.o
	$(AR) -rsv $@ $?

libercc2is2itsd.a: error.o clconn2.o initsrv2.o init.o setfd.o
	$(AR) -rsv $@ $?

libersprfsesfwnbacceldss.a: error.o spipe.o recvfd.o senderr.o sendfd.o writen.o bufargs.o cliconn.o \
 errorlog.o daemonize.o servaccept.o servlisten.o
	$(AR) -rsv $@ $?

liberittncitm.a: error.o isatty.o ttyname.o ctermid.o getpass.o ttymodes.o
	$(AR) -rsv $@ $?

liberpopflpdvtmsiwnsp.a: error.o ptyopen.o ptyfork.o loop.o driver.o ttymodes.o signalintr.o writen.o spipe.o
	$(AR) -rsv $@ $?

%.o: %.c
	$(CC) -c $(CPPFLAGS) -o $@ $<

%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

-include $(SRCS:.c=.d)

clean:
	rm -rf $(LIBS) *.a *.o *.d

cp1-clean:
	rm -rf libcp1.a error.o error.d

cp2-clean:
	rm -rf libcp2.a error.o error.d

cp3-clean:
	rm -rf libcp3.a error.o error.d

cp4-clean:
	rm -rf libcp4.a error.o error.d pathalloc.o pathalloc.d

cp5-clean:
	rm -rf libcp5.a error.o error.d

cp6-clean:
	rm -rf libcp6.a error.o error.d

cp7-clean:
	rm -rf libcp7.a error.o error.d

cp8-clean:
	rm -rf libcp8.a error.o error.d prexit.o prexit.d tellwait.o tellwait.d system.o system.d

cp9-clean:
	rm -rf libcp9.a error.o error.d

cp10-clean:
	rm -rf libcp10.a error.o error.d signal.o signal.d prmask.o prmask.d

cp11-clean:
	rm -rf libcp11.a error.o error.d

cp12-clean:
	rm -rf libcp12.a error.o error.d

cp13-clean:
	rm -rf libcp13.a error.o error.d lockfile.o lockfile.d

cp14-clean:
	rm -rf libcp14.a error.o error.d setfl.o setfl.d clrfl.o clrfl.d lockreg.o lockreg.d tellwait.o tellwait.d

cp15-clean:
	rm -rf libcp15.a error.o error.d tellwait.o tellwait.d

cp16-clean:
	rm -rf libcp16.a error.o error.d clconn2.o clconn2.d initsrv2.o initsrv2.d init.o init.d setfd.o setfd.d

cp17-clean:
	rm -rf libcp17.a error.o error.d spipe.o spipe.d recvfd.o recvfd.d senderr.o senderr.d sendfd.o sendfd.d \
	 writen.o writen.d bufargs.o bufargs.d cliconn.o cliconn.d errorlog.o errorlog.d daemonize.o daemonize.d \
	 servaccept.o servaccept.d servlisten.o servlisten.d

cp18-clean:
	rm -rf libcp18.a error.o error.d isatty.o isatty.d ttyname.o ttyname.d ctermid.o ctermid.d \
	 getpass.o getpass.d ttymodes.o ttymodes.d

cp19-clean:
	rm -rf libcp19.a error.o error.d ptyopen.o ptyopen.d ptyfork.o ptyfork.d loop.o loop.d driver.o driver.d \
	 ttymodes.o ttymodes.d signalintr.o signalintr.d writen.o writen.d spipe.o spipe.d

.PHONY: all clean
