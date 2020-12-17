CC = g++
CPPFLAGS = -std=c++98 -g -Wall 
OBJS = songList.o artist.o artistList.o app.o

app:	$(OBJS)

app.o: artistList.h artist.h songList.h song.h 

artistList.o: artist.h songList.h song.h 

artist.o: songList.h song.h 

songList.o: song.h 

clean:
	rm *.o app
