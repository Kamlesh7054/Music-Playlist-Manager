#include <iostream>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>

using namespace std;

class TIME {
public:
    int seconds;
    int minutes;
    int hours;
};

class Song {
public:
    string title;
    string artist;
    TIME duration;
    Song *next;
    Song *previous;
};

class Playlist {
public:
    Song *head;
    Playlist() {
        head = NULL;
    }

    void addNewSong() {
        Song *newSong = new Song();

        cout << "\nEnter song title: ";
        cin >> newSong->title;

        cout << "\nEnter artist name: ";
        cin >> newSong->artist;

        cout << "\nEnter duration in format 'min sec': ";
        cin >> newSong->duration.minutes >> newSong->duration.seconds;

        if (!head) {
            head = newSong;
            newSong->next = head;
            newSong->previous = head;
        } else {
            newSong->previous = head->previous;
            head->previous->next = newSong;
            head->previous = newSong;
            newSong->next = head;
        }
    }

    void displayPlaylist() {
        cout << "\n\n\n____________________Songs in your Playlist____________________";
        if (!head) {
            cout << "\nEmpty playlist\n";
        } else {
            Song *temphead = head;
            int i = 1;
            cout<<"\n\nNo."<<setw(20)<<"SONG TITLE"<<setw(20)<<"ARTIST NAME"<<setw(10) <<"DURATION"<<"\n";
            do {
                cout << "\n" << i << ". " <<setw(20) << temphead->title <<setw(20) << temphead->artist
                      <<setw(5)<< temphead->duration.minutes << ":" << temphead->duration.seconds;
                temphead = temphead->next;
                i++;
            } while (temphead != head);
        }

        totalDuration();
    }

    void removeASong() {
        if (!head) {
            cout << "\nThere is no song in your playlist to delete!";
            return;
        }

        string s;
        cout << "\nEnter 'title' of the song to delete: ";
        cin >> s;

        Song *temphead = head;
        Song *toDelete = NULL;

        // Search for Song to delete
        do {
            if (temphead->title == s) {
                toDelete = temphead;
                break;
            }
            temphead = temphead->next;
        } while (temphead != head);

        if (!toDelete) {
            cout << "The Song with title '" << s << "' does not exist in your playlist\n";
            return;
        }

        // Deleting Song with only one existing Song
        if (toDelete == head && toDelete->next == head) {
            head = NULL;
        } else if (toDelete == head) {  // Deleting the First Song
            Song *last = head->previous;
            head = head->next;
            head->previous = last;
            last->next = head;
        } else if (toDelete->next == head) {  // Deleting the last Song
            Song *prevSong = toDelete->previous;
            prevSong->next = head;
            head->previous = prevSong;
        } else {  // Deleting a song somewhere in between
            Song *prevSong = toDelete->previous;
            Song *nextSong = toDelete->next;
            prevSong->next = nextSong;
            nextSong->previous = prevSong;
        }

        delete toDelete;
        cout << "\nAFTER DELETING THE SONG '" << s << "'";
        displayPlaylist();
    }

    void totalDuration() {
        int hrs, min = 0, sec = 0;
        Song* temphead = head;
    
        do{
            min = min + temphead->duration.minutes;
            sec += temphead->duration.seconds;
            temphead = temphead->next;
        }while(temphead != head);

        int tmin, tsec;

        if(sec>=60)
        tsec = sec%60;
        else tsec = sec;

        min = sec/60 + min;
        if(min>=60)
        tmin = min%60;
        else tmin = min;

        if(tmin>=60)
        hrs = min/60;
        else hrs = 00;
        
        

        cout<<"\n\nTotal duratioin of Playlist: "<<setw(2)<<hrs<<":"<<setw(2)
        <<tmin<<":"<<setw(2)<<tsec<<" (In formate HH:MM:SS) ";
        
    }

void Reorder() {
    int oldPosition, newPosition;
    cout << "\nEnter the old position: ";
    cin >> oldPosition;
    cout << "\nEnter the new position: ";
    cin >> newPosition;

    if (!head || oldPosition == newPosition) return;  // No change if the list is empty or positions are the same

    Song* current = head;
    int i = 1;

    // Locate the node at oldPosition
    while (i < oldPosition && current->next != head) {
        current = current->next;
        i++;
    }

    // If oldPosition is out of bounds
    if (i != oldPosition) {
        cout << "Invalid old position!" << endl;
        return;
    }

    // Detach the node to be moved
    Song* toMove = current;
    toMove->previous->next = toMove->next;
    toMove->next->previous = toMove->previous;

    // If toMove was the head, update head pointer
    if (toMove == head) {
        head = toMove->next;
    }

    // Move to the target new position
    Song* target = head;
    i = 1;

    while (i < newPosition && target->next != head) {
        target = target->next;
        i++;
    }

    // Reattach toMove at the new position
    toMove->next = target;
    toMove->previous = target->previous;
    target->previous->next = toMove;
    target->previous = toMove;

    // If the node is moved to the head position
    if (newPosition == 1) {
        head = toMove;
    }

    cout << "Node moved from position " << oldPosition << " to position " << newPosition << "." << endl;
}


    void searchSong(){
        if (!head) {
            cout << "\nThere is no song in your playlist to Search!";
            return;
        }

        cout<<"\nEnter: ";
        cout<<"\n1 --> for Search by \"TITLE NAME\"";
        cout<<"\n2 --> for Search by \"ARTIST NAME\"";
        cout<<"\n-->";
        int x;
        cin>>x;

        string s = "\0", a = "\0";
        switch (x)
        {
        case 1:
            cout<<"\nEnter Song TITLE: ";
            cin>>s;
            break;
        case 2:
            cout<<"\nEnter Song ARTIST NAME: ";
            cin>>a;
            break;
        
        default:
            cout<<"\nINVALID INPUTE";
            return;
        }
        
        string toSearchString;
        if(s != "\0")
        toSearchString = s;
        else toSearchString = a;

        Song *temphead = head;
        Song *toSearch = NULL;
        int i =1;

        // Searching
        do {
            if (temphead->title == toSearchString or temphead->artist == toSearchString) {
                if(i == 1)
                cout<<"\n\nNo."<<setw(20)<<"SONG TITLE"<<setw(20)<<"ARTIST NAME"<<setw(10) <<"DURATION"<<"\n";
                cout << "\n"<<i<<". " <<setw(20) << temphead->title <<setw(20) << temphead->artist
                      <<setw(5)<< temphead->duration.minutes << ":" << temphead->duration.seconds;
                toSearch = temphead;
                i++;
            }
            temphead = temphead->next;
        } while (temphead != head);

        if(toSearch == NULL)
        cout<<"\nDOES NOT EXIST IN YOUR PLAYLIST";
        if(i>1)
        cout<< "\nThere are "<< i-1 << " Songs, given by your search title '" << toSearchString<<"'";

    }

    void saveToPlaylist(){
        string filename;
        cout<< "\nEnter the file name: ";
        cin>>filename;
        ofstream file(filename);

        if(!file.is_open()){
            cerr<<"\nError: could not open the file to Save the song.\n";
            return;
        }
        Song* current = head;
        if (current == NULL) {
            cout << "Playlist is empty; nothing to save.\n";
            return;
        }

        do{
            file<<current->title<<", "<<current->artist<<", "
            <<current->duration.minutes<<":"<<current->duration.seconds<<"\n";
            current = current->next;
        }while (current != head);
        
        cout<<"\nPlaylist saved to "<<filename;
        file.close();

    }

    // Clear playlist
    void clearPlaylist() {
        if (!head) return;

        Song* current = head;
        do {
            Song* nextSong = current->next;
            delete current;
            current = nextSong;
        } while (current != head);

        head = nullptr;
    }

    void loadPlalist(){
        string filename;
        cout<<"\nEnter the filename: ";
        cin>>filename;
        ifstream file(filename);

        if(!file.is_open()){
            cerr<<"Error: Could not open to read the file.";
            return;
        }

        string line;
        clearPlaylist(); //Clear current playlist

        while (getline(file, line))
        {
            unsigned pos1 = line.find(',');
            unsigned pos2 = line.find_last_of(',');
            unsigned pos3 = line.find(':');

            string Title = line.substr(0, pos1);
            string Artist = line.substr(pos1+2, pos2-pos1-2);
            int durationMin = stoi(line.substr(pos2+2, pos3-pos2-1));
            int durationSec = stoi(line.substr(pos3+1));

            //Adding a song
            Song* newSong = new Song();

            newSong->title = Title;
            newSong->artist = Artist;
            newSong->duration.minutes = durationMin;
            newSong->duration.seconds = durationSec;


            if (!head) {
                head = newSong;
                newSong->next = head;
                newSong->previous = head;
            } else {
                newSong->previous = head->previous;
                head->previous->next = newSong;
                head->previous = newSong;
                newSong->next = head;
            }
        }

        cout<<"\nPlaylist loaded form "<<filename<<" Successfully...!";
        file.close();
        
    }

};

int main() {
    Playlist x;

menu:
    cout << "\n\n\n____________________Music System____________________";
    cout << "\n\nPress:";
    cout << "\n1 --> To add a New Music";
    cout << "\n2 --> To display Playlist";
    cout << "\n3 --> To delete a song from Playlist";
    cout << "\n4 --> To Reorder a Song";
    cout << "\n5 --> To Search a Song";
    cout << "\n6 --> To Save the newely added Songs";
    cout << "\n7 --> To Clear the songs in your Playlist";
    cout << "\n8 --> To load the playlist";
    cout << "\n0 --> To exit";
    cout << "\n-->";

    int choice;
    cin >> choice;

    switch (choice) {
    case 1:
        int n;
        cout << "\nEnter the number of Songs you want to add: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "\nEnter the Song number " << i + 1 << endl;
            x.addNewSong();
        }
        goto menu;
        break;
    case 2:
        x.displayPlaylist();
        goto menu;
        break;
    case 3:
        x.removeASong();
        goto menu;
        break;
    case 4:
        x.Reorder();
        goto menu;
        break;
    case 5:
        x.searchSong();
        goto menu;
        break;
    case 6:
        x.saveToPlaylist();
        goto menu;
        break;
    case 7:
        x.clearPlaylist();
        goto menu;
        break;
    case 8:
        x.loadPlalist();
        goto menu;
        break;
    default:
        break;
    }
    return 0;
}
