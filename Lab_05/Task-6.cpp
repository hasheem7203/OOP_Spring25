//task6
#include <iostream>
#include <string>
using namespace std;

class Level {
public:
    string levelName;
    int difficulty;

    Level(string name, int diff) : levelName(name), difficulty(diff) {}
};

class VideoGame {
private:
    string title;
    string genre;
    Level** levels;
    int levelCount;

public:
    VideoGame(string gameTitle, string gameGenre, int numLevels) 
        : title(gameTitle), genre(gameGenre), levelCount(numLevels) {
        levels= new Level*[levelCount];
        for (int i=0;i<levelCount;i++) {
            string levelName="Level "+to_string(i +1);
            int difficulty=(i+1)*3;
            levels[i] = new Level(levelName,difficulty); 
        }
    }

    ~VideoGame() {
        for (int i=0;i<levelCount;i++) {
            delete levels[i];
        }
        delete[] levels;
    }

    void displayGameDetails() const {
        cout <<"\nTitle: "<<title<<"\nGenre: "<<genre<<"\nLevels:\n";
        for (int i=0;i<levelCount;i++) {
            cout<<"- "<<levels[i]->levelName<<" | Difficulty: "<<levels[i]->difficulty<< "\n";
        }
    }
};

int main() {
    VideoGame game1("Call Of Duty Warzone","Action-Adventure",3);
    game1.displayGameDetails();
    
    return 0;
}
