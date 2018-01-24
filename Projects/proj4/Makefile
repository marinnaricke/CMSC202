CPPFLAGS = -ansi -Wall

proj4: proj4.o card.o game.o player.o
	g++ $(CPPFLAGS) proj4.o card.o game.o player.o -o proj4

proj4.o: proj4.cpp card.cpp card.h game.cpp game.h player.cpp player.h
	g++ $(CPPFLAGS) -c proj4.cpp

mytest: mytest.o card.o game.o player.o Cruno8.o CrunoSkip.o CrunoReverse.o /
	CrunoDraw2.o CrunoGame.o CrunoPlayer.o
	g++ $(CPPFLAGS) mytest.o card.o game.o player.o Cruno8.o CrunoSkip.o /
	CrunoReverse.o CrunoDraw2.o CrunoGame.o CrunoPlayer.o -o mytest

mytest.o: mytest.cpp card.cpp card.h game.cpp game.h player.cpp player.h /
	Cruno8.cpp Cruno8.h CrunoSkip.cpp CrunoSkip.h /
	CrunoReverse.cpp CrunoReverse.h CrunoDraw2.cpp CrunoDraw2.h /
	CrunoGame.cpp CrunoGame.h CrunoPlayer.cpp CrunoPlayer.h
	g++ $(CPPFLAGS) -c mytest.cpp

card.o: card.cpp card.h player.cpp player.h game.cpp game.h
	g++ $(CPPGFLAGS) -c card.cpp

game.o: game.cpp game.h card.cpp card.h player.cpp player.h
	g++ $(CPPFLAGS) -c game.cpp

player.o: player.cpp player.h card.cpp card.h game.cpp game.h
	g++ $(CPPFLAGS) -c player.cpp

Cruno8.o: Cruno8.cpp Cruno8.h CrunoGame.cpp CrunoGame.h card.cpp card.h /
	CrunoPlayer.cpp CrunoPlayer.h
	g++ $(CPPFLAGS) -c Cruno8.cpp

CrunoSkip.o: CrunoSkip.cpp CrunoSkip.h card.cpp card.h /
	CrunoGame.cpp CrunoGame.h CrunoPlayer.cpp CrunoPlayer.h
	g++ $(CPPFLAGS) -c CrunoSkip.cpp

CrunoReverse.o: CrunoReverse.cpp CrunoReverse.h card.cpp card.h /
	CrunoGame.cpp CrunoGame.h CrunoPlayer.cpp CrunoPlayer.h
	g++ $(CPPFLAGS) -c CrunoReverse.cpp

CrunoDraw2.o: CrunoDraw2.cpp CrunoDraw2.h card.cpp card.h /
	CrunoGame.cpp CrunoGame.h CrunoPlayer.cpp CrunoPlayer.h
	g++ $(CPPFLAGS) -c CrunoDraw2.cpp

CrunoPlayer.o: CrunoPlayer.cpp CrunoPlayer.h player.cpp player.h /
	card.cpp card.h game.cpp game.h
	g++ $(CPPFLAGS) -c CrunoPlayer.cpp

CrunoGame.o: CrunoGame.cpp CrunoGame.h game.cpp game.h CrunoPlayer.cpp 
	CrunoPlayer.h card.cpp card.h CrunoSkip.cpp CrunoSkip.h /
	CrunoReverse.cpp CrunoReverse.h CrunoDraw2.cpp CrunoDraw2.h /
	Cruno8.cpp Cruno8.h
	g++ $(CPPFLAGS) -c CrunoGame.cpp

#make: Makefile
#        emacs Makefile

# this tells the Makefile that these rules have no dependencies
.PHONY: clean
.PHONY: cleaner
.PHONY: cleanest
clean:
	rm -f *~ *#
cleaner: clean
	rm -f *.o
#cleanest: cleaner
#        rm -f mytest