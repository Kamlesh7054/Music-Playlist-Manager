# C++ Music Playlist Management System

A console-based music playlist management system built in C++. This project allows users to create, manage, search, reorder, save, and load songs in a circular doubly linked list. The application simulates a basic music manager system where each song has a title, artist name, and duration.

---

## Features

### Add New Song(s)
- Add one or multiple songs to the playlist.
- Each song includes:
  - Title
  - Artist
  - Duration (in minutes and seconds)

### Display Playlist
- View the entire playlist in a tabular format (serial number, title, artist, duration).
- Shows total playlist duration in `HH:MM:SS`.

### Remove a Song
- Remove a song by providing its **title**.
- Handles edge cases (head, tail, single/middle node).

### Reorder Songs
- Move a song from one position to another using indices.
- Internally updates the circular doubly linked list.

### Search Functionality
- Search by:
  - Title
  - Artist name
- Supports partial match and structured result display.

### Save Playlist to File
- Save the playlist to a `.txt` file.
- Format: title, artist, duration per song.

### Load Playlist from File
- Load songs from a saved playlist file.
- Replaces current list with the loaded one.

### Clear Playlist
- Clears the entire playlist and deallocates memory.

---

## Technologies Used

- **Language:** C++
- **Data Structure:** Circular Doubly Linked List
- **File I/O:** Save/load playlist to/from text files
- **Standard Libraries:** `<iostream>`, `<fstream>`, `<string>`, `<iomanip>`

---

## How to Run

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/Kamlesh7054/Music-Playlist-Manager.git
   cd playlist-management
   ```

2. **Compile the Code:**
   ```bash
   g++ Music Playlist Manager.cpp -o playlist
   ```

3. **Run the Executable:**
   ```bash
   ./playlist
   ```

---

##  Sample Menu

```text

____________________Music System____________________

Press:
1 --> To add a New Music
2 --> To display Playlist
3 --> To delete a song from Playlist
4 --> To Reorder a Song
5 --> To Search a Song
6 --> To Save the newely added Songs
7 --> To Clear the songs in your Playlist
8 --> To load the playlist
0 --> To exit
-->8

Enter the filename: Playlist.txt

Playlist loaded form Playlist.txt Successfully...!


____________________Music System____________________

Press:
1 --> To add a New Music
2 --> To display Playlist
3 --> To delete a song from Playlist
4 --> To Reorder a Song
5 --> To Search a Song
6 --> To Save the newely added Songs
7 --> To Clear the songs in your Playlist
8 --> To load the playlist
0 --> To exit
-->2



____________________Songs in your Playlist____________________

No.          SONG TITLE         ARTIST NAME  DURATION

1.                Song1             Artist1    2:35
2.                Song2             Artist2    4:23
3.                Song3             Artist3    5:1
4.                Song4             Artist4    4:23
5.                Song5             Artist4    2:45

Total duratioin of Playlist:  0:19: 7 (In formate HH:MM:SS)


____________________Music System____________________

Press:
1 --> To add a New Music
2 --> To display Playlist
3 --> To delete a song from Playlist
4 --> To Reorder a Song
5 --> To Search a Song
6 --> To Save the newely added Songs
7 --> To Clear the songs in your Playlist
8 --> To load the playlist
0 --> To exit
-->1

Enter the number of Songs you want to add: 1

Enter the Song number 1

Enter song title: Song7

Enter artist name: Artist3

Enter duration in format 'min sec': 3 54



____________________Music System____________________

Press:
1 --> To add a New Music
2 --> To display Playlist
3 --> To delete a song from Playlist
4 --> To Reorder a Song
5 --> To Search a Song
6 --> To Save the newely added Songs
7 --> To Clear the songs in your Playlist
8 --> To load the playlist
0 --> To exit
-->2



____________________Songs in your Playlist____________________

No.          SONG TITLE         ARTIST NAME  DURATION

1.                Song1             Artist1    2:35
2.                Song2             Artist2    4:23
3.                Song3             Artist3    5:1
4.                Song4             Artist4    4:23
5.                Song5             Artist4    2:45
6.                Song7             Artist3    3:54

Total duratioin of Playlist:  0:23: 1 (In formate HH:MM:SS)


____________________Music System____________________

Press:
1 --> To add a New Music
2 --> To display Playlist
3 --> To delete a song from Playlist
4 --> To Reorder a Song
5 --> To Search a Song
6 --> To Save the newely added Songs
7 --> To Clear the songs in your Playlist
8 --> To load the playlist
0 --> To exit
-->4

Enter the old position: 6

Enter the new position: 3
Node moved from position 6 to position 3.



____________________Music System____________________

Press:
1 --> To add a New Music
2 --> To display Playlist
3 --> To delete a song from Playlist
4 --> To Reorder a Song
5 --> To Search a Song
6 --> To Save the newely added Songs
7 --> To Clear the songs in your Playlist
8 --> To load the playlist
0 --> To exit
-->2



____________________Songs in your Playlist____________________

No.          SONG TITLE         ARTIST NAME  DURATION

1.                Song1             Artist1    2:35
2.                Song2             Artist2    4:23
3.                Song7             Artist3    3:54
4.                Song3             Artist3    5:1
5.                Song4             Artist4    4:23
6.                Song5             Artist4    2:45

Total duratioin of Playlist:  0:23: 1 (In formate HH:MM:SS)


____________________Music System____________________

Press:
1 --> To add a New Music
2 --> To display Playlist
3 --> To delete a song from Playlist
4 --> To Reorder a Song
5 --> To Search a Song
6 --> To Save the newely added Songs
7 --> To Clear the songs in your Playlist
8 --> To load the playlist
0 --> To exit
-->6

Enter the file name: myplaylist

Playlist saved to myplaylist


____________________Music System____________________

Press:
1 --> To add a New Music
2 --> To display Playlist
3 --> To delete a song from Playlist
4 --> To Reorder a Song
5 --> To Search a Song
6 --> To Save the newely added Songs
7 --> To Clear the songs in your Playlist
8 --> To load the playlist
0 --> To exit
-->0
```

---

