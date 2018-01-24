#ifndef __MusicProcessor_H__
#define __MusicProcessor_H__

#include "MidiFile.h"
#include <iostream>
#include <ctime>

//This is used to output generation process
const bool TRACE_GENERATION = true;
// std::fstream LOG_FILE;
//

const int COLOR_CONTAINER_SEED_SIZE = 64;

enum colorType {red = 0, orange = 1, yellow = 2, green = 3, blue = 4, lavenderII = 5, black = 6, white = 7, none = 8};

    std::string getColorName(int c);
    colorType getRandomColorType();

class colorContainer{
private:
    
    colorType* currentColor;
    colorType list[COLOR_CONTAINER_SEED_SIZE];
    int size;
    int resetCounter;   //count of cycling through full list

public:
    colorContainer(colorType* inList, int inSize);
    colorContainer();
    ~colorContainer();
    

    void initRandom();  //returns if randomness has been init
    
    colorType getColor();
    bool addColor(colorType color);
    void printSeed();
    std::string getSeedNumber();

};


////////////////////////
//  The following enumerations are used for theory
////////////////////////

//This is an easy way to convert note names into MIDI note ints
enum noteName{
    //Note Names without octave
    C = 0,
    Csharp = 1,
    Dflat = 1,
    D = 2,
    Dsharp = 3,
    Eflat = 3,
    E = 4,
    Fflat = 4,
    Esharp = 5,
    F = 5,
    Fsharp = 6,
    Gflat = 6,
    G = 7,
    Gsharp = 8,
    Aflat = 8,
    A = 9,
    Asharp = 10,
    Bflat = 10,
    B = 11,
    Cflat = 11,
    Bsharp = 12,



    //Octave 2
    C2 = 36,
    Csharp2 = 37,
    Dflat2 = 37,
    D2 = 38,
    Dsharp2 = 39,
    Eflat2 = 39,
    E2 = 40,
    Fflat2 = 40,
    Esharp2 = 41,
    F2 = 41,
    Fsharp2 = 42,
    Gflat2 = 42,
    G2 = 43,
    Gsharp2 = 44,
    Aflat2 = 44,
    A2 = 45,
    Asharp2 = 46,
    Bflat2 = 46,
    B2 = 47,
    Cflat2 = 47,
    Bsharp2 = 48,
    //Octave 3
    C3 = 48,
    Csharp3 = 49,
    Dflat3 = 49,
    D3 = 50,
    Dsharp3 = 51,
    Eflat3 = 51,
    E3 = 52,
    Fflat3 = 52,
    Esharp3 = 53,
    F3 = 53,
    Fsharp3 = 54,
    Gflat3 = 54,
    G3 = 55,
    Gsharp3 = 56,
    Aflat3 = 56,
    A3 = 57,
    Asharp3 = 58,
    Bflat3 = 58,
    B3 = 59,
    Cflat3 = 59,
    Bsharp3 = 60,
    //Octave 4
    C4 = 60,
    Csharp4 = 61,
    Dflat4 = 61,
    D4 = 62,
    Dsharp4 = 63,
    Eflat4 = 63,
    E4 = 64,
    Fflat4 = 64,
    Esharp4 = 65,
    F4 = 65,
    Fsharp4 = 66,
    Gflat4 = 66,
    G4 = 67,
    Gsharp4 = 68,
    Aflat4 = 68,
    A4 = 69,
    Asharp4 = 70,
    Bflat4 = 70,
    B4 = 71,
    Cflat4 = 71,
    Bsharp4 = 72,
    //Octave 5
    C5 = 72,
    Csharp5 = 73,
    Dflat5 = 73,
    D5 = 74,
    Dsharp5 = 75,
    Eflat5 = 75,
    E5 = 76,
    Fflat5 = 76,
    Esharp5 = 77,
    F5 = 77,
    Fsharp5 = 78,
    Gflat5 = 78,
    G5 = 79,
    Gsharp5 = 80,
    Aflat5 = 80,
    A5 = 81,
    Asharp5 = 82,
    Bflat5 = 82,
    B5 = 83,
    Cflat5 = 83,
    Bsharp5 = 84,
    //Octave 6
    C6 = 84,
    Csharp6 = 85,
    Dflat6 = 85,
    D6 = 86,
    Dsharp6 = 87,
    Eflat6 = 87,
    E6 = 88,
    Fflat6 = 88,
    Esharp6 = 89,
    F6 = 89,
    Fsharp6 = 90,
    Gflat6 = 90,
    G6 = 91,
    Gsharp6 = 92,
    Aflat6 = 92,
    A6 = 93,
    Asharp6 = 94,
    Bflat6 = 94,
    B6 = 95,
    Cflat6 = 95,
    Bsharp6 = 96,
};

enum noteLength{
    whole = 16,
    dotHalf = 12,
    half = 8,
    dotQuarter = 6,
    quarter = 4,
    dotEighth = 3,
    eighth = 2,
    sixteenth = 1
};

enum chordType{
    I = 1,
    ii = 2,
    iii = 3,
    IV = 4,
    V = 5,
    vi = 6,
    vii = 7
};

enum key{
    key_B = 5,
    key_E = 4,
    key_A = 3,
    key_D = 2,
    key_G = 1,
    key_C = 0,
    key_F = -1,
    key_Bb = -2,
    key_Eb = -3,
    key_Ab = -4,
    key_Db = -5
};

enum mode{
    Ionian = 1,
    Dorian = 2,
    Phrygian = 3,
    Lydian = 4,
    Mixolydian = 5,
    Aeolian = 6,
    Locrian = 7
};

enum interval{
    //Specific intervals
    PerfectUnison = 0,
    MinorSecond = 1,
    MajorSecond = 2,
    MinorThird = 3,
    MajorThird = 4,
    PerfectFourth = 5,
    AugmentedFourth = 6,
    DiminishedFifth = 6,
    PerfectFifth = 7,
    MinorSixth = 8,
    MajorSixth = 9,
    MinorSeventh = 10,
    MajorSeventh = 11,
    Octave = 12,

    //Non Specific Intervals
    First = -1,
    Second = -2,
    Third = -3,
    Fourth = -4,
    Fifth = -5,
    Sixth = -6,
    Seventh = -7,

    //Used to build from half steps
    HalfStep = 1,
    WholeStep = 2
};

//*Note: set rhythm and noteName to -1 to mean that the note hasn't been initialized yet
//      and/or means the song is over once it gets to the -1
struct note{
    int noteName;
    int rhythm;
};

struct chord{
    int noteRoot;
    int noteThird;
    int noteFifth;
    int rhythm;
};




////////////////////////
//  The following functions are for music theory
////////////////////////
float getFrequency(int noteName);
/*This function sets the outNoteName to the note without octave,
    and sets the outNoteOctave to the octave of the note    */
void seperateNoteAndOctave(int inNote, int* outNoteName, int* outNoteOctave);
int getScale(int key, int rootNote);
/*This uses the key and chord number to determine the note, and then use
  octave to offset that note to the correct octave  */
int getRootNote(int key, int chord, int octave);
int getNoteInKey(int key, int scaleDegree);

//Note: Always pass in Non Specific Intervals
int getNoteFromMode(int key, int mode, int scaleDegree);



////////////////////////
//  The following functions and structures are for song structure
////////////////////////

class smallSection{
private:
    int bars;
    note melody[64];
    chord harmony[32];
    note* melodyPtr;
    chord* harmonyPtr;

    colorContainer* colorList;

    void generateChords(int key);
    void generateMelody(int key);
public:
    smallSection();
    ~smallSection();
    //smallSection(const smallSection&);

    void generatorLoop(int key, colorContainer* inColorList);
    void variationGeneratorLoop(int key, colorContainer* inColorList);
    note getNote(int n);
    chord getChord(int n);

};

class songSection{
private:
    //Form can be:
    //  Binary = 0, which follows the form aa'bb'
    //  Ternary = 1, which follows the form aba'
    //  *form should not be changed after creation
    int smallForm;
    int sectionNum; //the number of sections

    smallSection sections[4];
    colorContainer* colorList;

    void createSection(int sectionNumber, int key);
    void createVariationFromSection(int sectionNumber, int variationNumber, int key);
public:
    songSection();
    ~songSection();
    //SongSection(const SongSection&);

    void generatorLoop(int key, colorContainer* inColorList);
    void variationGeneratorLoop(int key, colorContainer* inColorList);
    int getSectionNum();
    smallSection* getSmallSection(int n);


};



class MidiFileGenerator {
private:
    int melodyInstrument;
    int harmonyInstrument;
    int bpm;
    //Form can be:
    //  Binary = 0, which follows the form AA'BB'
    //  Ternary = 1, which follows the form ABA'
    //  *form should not be changed after creation
    int largeForm;
    int key;

    int sectionNum; //the number of sections
    songSection sections[4];
    colorContainer colorList;

    void createSection(int sectionNumber);
    void createVariationFromSection(int sectionNumber, int variationNumber);
public:
    MidiFileGenerator();
    ~MidiFileGenerator();

    void mainGeneratorLoop();
    void outputToFile();
    void writeMSPFile();
    void setColorList(colorType *);
};



#endif // __MusicProcessor_H__
