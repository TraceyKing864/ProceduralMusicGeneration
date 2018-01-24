#include "MusicProcessor.h"

std::string getColorName(int c){
    switch(c){
        case red:
        default:
            return "Red";
        case orange:
            return "Orange";
        case yellow:
            return "Yellow";
        case green:
            return "Green";
        case blue:
            return "Blue";
        case lavenderII:
            return "LavenderII";
        case black:
            return "Black";
        case white:
            return "White";
    }
}

void initRandom(){
    static bool init = false;
    
    //seeds random based on current time
    if(!init){
        std::srand((unsigned int)std::time(0));
        init = true;
    }
}

colorType getRandomColorType(){
    initRandom();
    
    int rng = std::rand() % 8;
    switch(rng){
        case 0:
        default:
            return red;
        case 1:
            return orange;
        case 2:
            return yellow;
        case 3:
            return green;
        case 4:
            return blue;
        case 5:
            return lavenderII;
        case 6:
            return black;
        case 7:
            return white;
    }
}

colorContainer::colorContainer(colorType* inList, int inSize){
    for(int i = 0; i < inSize; i++)
        list[i] = inList[i];
    
    size = inSize;
    currentColor = &list[0];
    resetCounter = 0;

}
colorContainer::colorContainer(){
    for(size = 0; size < COLOR_CONTAINER_SEED_SIZE; size++)
        list[size] = getRandomColorType();
    
    currentColor = &list[0];
    resetCounter = 0;
    
}
colorContainer::~colorContainer(){

}
colorType colorContainer::getColor(){
    colorType* returnColor;
    if(currentColor > &list[size]){  //If we run out of colors
        //I wanted to offset the seed slightly to get more numbers,
        //  but in different sequences.
        //Uncomment to show the amount of times it loops through colors
        //std::cout << "Looping List: " << ++resetCounter << std::endl;
        currentColor = &list[resetCounter];
        returnColor = currentColor;
    }else{
        returnColor = currentColor;
        currentColor++;
    }

    return *returnColor;
}
bool colorContainer::addColor(colorType color){
    if (size < 256) {
        list[size] = color;
        size++;
        return true;
    }
    return false;
}
std::string colorContainer::getSeedNumber(){
    std::string str = "";
    colorType* seedNumber = &list[0];
    while(seedNumber < &list[size]){
        str.append(to_string(*seedNumber));
        seedNumber++;
    }

    return str;
}
void colorContainer::printSeed(){
    std::cout << "Seed Number: " << getSeedNumber() << std::endl;
}

float getFrequency(int noteName){
     switch(noteName){
         case 36:    //C2
            return 65.41;
        case 37:
            return 69.30;
        case 38:
            return 73.42;
        case 39:
            return 77.78;
        case 40:
            return 82.41;
        case 41:
            return 87.31;
        case 42:
            return 92.50;
        case 43:
            return 98.00;
        case 44:
            return 103.83;
        case 45:
            return 110.00;
        case 46:
            return 116.54;
        case 47:
            return 123.47;

        case 48:    //C3
            return 130.81;
        case 49:
            return 138.59;
        case 50:
            return 146.83;
        case 51:
            return 155.56;
        case 52:
            return 164.81;
        case 53:
            return 174.61;
        case 54:
            return 185.00;
        case 55:
            return 196.00;
        case 56:
            return 207.65;
        case 57:
            return 220.00;
        case 58:
            return 233.08;
        case 59:
            return 246.94;

        case 60:    //C4
            return 261.63;
        case 61:
            return 277.18;
        case 62:
            return 293.66;
        case 63:
            return 311.13;
        case 64:
            return 329.63;
        case 65:
            return 349.23;
        case 66:
            return 369.99;
        case 67:
            return 392.00;
        case 68:
            return 415.30;
        case 69:
        default:
            return 440.00;
        case 70:
            return 466.16;
        case 71:
            return 493.88;

        case 72:    //C5
            return 523.25;
        case 73:
            return 554.37;
        case 74:
            return 587.33;
        case 75:
            return 622.25;
        case 76:
            return 659.25;
        case 77:
            return 698.46;
        case 78:
            return 739.99;
        case 79:
            return 783.99;
        case 80:
            return 830.61;
        case 81:
            return 880.00;
        case 82:
            return 932.33;
        case 83:
            return 987.77;

        case 84:    //C6
            return 1046.59;
        case 85:
            return 1108.73;
        case 86:
            return 1174.66;
        case 87:
            return 1244.51;
        case 88:
            return 1318.51;
        case 89:
            return 1396.91;
        case 90:
            return 1479.98;
        case 91:
            return 1567.98;
        case 92:
            return 1661.22;
        case 93:
            return 1760.00;
        case 94:
            return 1864.66;
        case 95:
            return 1975.53;
        case 96:
            return 2093.00;

    }
}

void seperateNoteAndOctave(int inNote, int* outNoteName, int* outNoteOctave){
    *outNoteOctave = 0;
    while(inNote > 12){
        inNote -= 12;
        *outNoteOctave += 1;
    }
    *outNoteName = inNote;
}
int getScale(int key, int rootNote){
    int returnScale;
    int actualNote;
    int actualOctave;
    seperateNoteAndOctave(rootNote, &actualNote, &actualOctave);
    int baseNote;

    switch(key){
        case key_B:
            baseNote = B;
            break;
        case key_E:
            baseNote = E;
            break;
        case key_A:
            baseNote = A;
            break;
        case key_D:
            baseNote = D;
            break;
        case key_G:
            baseNote = G;
            break;
        case key_F:
            baseNote = F;
            break;
        case key_Bb:
            baseNote = Bflat;
            break;
        case key_Eb:
            baseNote = Eflat;
            break;
        case key_Ab:
            baseNote = Aflat;
            break;
        case key_Db:
            baseNote = Dflat;
            break;
        case key_C:
        default:
            baseNote = C;
            break;
    }

    if((baseNote) == actualNote){
        returnScale = Ionian;
    }else if((baseNote + MajorSecond) == actualNote){
        returnScale = Dorian;
    }else if((baseNote + MajorThird) == actualNote){
        returnScale = Phrygian;
    }else if((baseNote + PerfectFourth) == actualNote){
        returnScale = Lydian;
    }else if((baseNote + PerfectFifth) == actualNote){
        returnScale = Mixolydian;
    }else if((baseNote + MajorSixth) == actualNote){
        returnScale = Aeolian;
    }else if((baseNote + MajorSeventh) == actualNote){
        returnScale = Locrian;
    }else{
        returnScale = Ionian;
    }
    return returnScale;
}
int getRootNote(int key, int chord, int octave){
    int rootNote;
    //First set the key to the middle octave
    switch(key){
        case key_B:
            rootNote = B4;
            break;
        case key_E:
            rootNote = E4;
            break;
        case key_A:
            rootNote = A4;
            break;
        case key_D:
            rootNote = D4;
            break;
        case key_G:
            rootNote = G4;
            break;
        case key_F:
            rootNote = F4;
            break;
        case key_Bb:
            rootNote = Bflat4;
            break;
        case key_Eb:
            rootNote = Eflat4;
            break;
        case key_Ab:
            rootNote = Aflat4;
            break;
        case key_Db:
            rootNote = Dflat4;
            break;
        case key_C:
        default:
            rootNote = C4;
            break;
    }
    //Find the correct root note from base key
    switch(chord){
        case ii:
            rootNote += 2;
            break;
        case iii:
            rootNote += 4;
            break;
        case IV:
            rootNote += 5;
            break;
        case V:
            rootNote += 7;
            break;
        case vi:
            rootNote += 9;
            break;
        case vii:
            rootNote += 11;
            break;
        case I:     //This is intended to do nothing
        default:
            break;
    }
    //Bring down to the correct octave
    if(octave == 2){
        if(rootNote >= 72)
            rootNote -= 36;
        else if(rootNote >= 60)
            rootNote -= 24;
        else if(rootNote >= 48)
            rootNote -= 12;
    }else if(octave == 3){
        if(rootNote >= 72)
            rootNote -= 24;
        else if(rootNote >= 60)
            rootNote -= 12;
    }else{  //octave == 4
        if(rootNote >= 72)
            rootNote -= 12;
    }
    return rootNote;
}

int getNoteInKey(int key, int scaleDegree){
    int rootNote;
    //First set the key to the middle octave
    switch(key){
        case key_B:
            rootNote = B4;
            break;
        case key_E:
            rootNote = E4;
            break;
        case key_A:
            rootNote = A4;
            break;
        case key_D:
            rootNote = D4;
            break;
        case key_G:
            rootNote = G4;
            break;
        case key_F:
            rootNote = F4;
            break;
        case key_Bb:
            rootNote = Bflat4;
            break;
        case key_Eb:
            rootNote = Eflat4;
            break;
        case key_Ab:
            rootNote = Aflat4;
            break;
        case key_Db:
            rootNote = Dflat4;
            break;
        case key_C:
        default:
            rootNote = C4;
            break;
    }
    //Find the correct root note from base key
    switch(scaleDegree){
        case Second:
            rootNote += MajorSecond;
            break;
        case Third:
            rootNote += MajorThird;
            break;
        case Fourth:
            rootNote += PerfectFourth;
            break;
        case Fifth:
            rootNote += PerfectFifth;
            break;
        case Sixth:
            rootNote += MajorSixth;
            break;
        case Seventh:
            rootNote += MajorSeventh;
            break;
        case First:     //This is intended to do nothing
        default:
            break;
    }
    return rootNote;
}

int getNoteFromMode(int key, int mode, int scaleDegree){
    int rootNote;

    //First set the key to the middle octave
    switch(key){
        case key_B:
            rootNote = B4;
            break;
        case key_E:
            rootNote = E4;
            break;
        case key_A:
            rootNote = A4;
            break;
        case key_D:
            rootNote = D4;
            break;
        case key_G:
            rootNote = G4;
            break;
        case key_F:
            rootNote = F4;
            break;
        case key_Bb:
            rootNote = Bflat4;
            break;
        case key_Eb:
            rootNote = Eflat4;
            break;
        case key_Ab:
            rootNote = Aflat4;
            break;
        case key_Db:
            rootNote = Dflat4;
            break;
        case key_C:
        default:
            rootNote = C4;
            break;
    }

    switch(mode){
        default:
        case Ionian:
            switch(scaleDegree){
                case Second:
                    rootNote += MajorSecond;
                    break;
                case Third:
                    rootNote += MajorThird;
                    break;
                case Fourth:
                    rootNote += PerfectFourth;
                    break;
                case Fifth:
                    rootNote += PerfectFifth;
                    break;
                case Sixth:
                    rootNote += MajorSixth;
                    break;
                case Seventh:
                    rootNote += MajorSeventh;
                    break;
                case First:     //This is intended to do nothing
                default:
                    break;
            }
            break;
        case Dorian:
            switch(scaleDegree){
                case Second:
                    rootNote += MajorSecond;
                    break;
                case Third:
                    rootNote += MinorThird;
                    break;
                case Fourth:
                    rootNote += PerfectFourth;
                    break;
                case Fifth:
                    rootNote += PerfectFifth;
                    break;
                case Sixth:
                    rootNote += MajorSixth;
                    break;
                case Seventh:
                    rootNote += MinorSeventh;
                    break;
                case First:     //This is intended to do nothing
                default:
                    break;
            }
            break;
        case Phrygian:
            switch(scaleDegree){
                case Second:
                    rootNote += MinorSecond;
                    break;
                case Third:
                    rootNote += MinorThird;
                    break;
                case Fourth:
                    rootNote += PerfectFourth;
                    break;
                case Fifth:
                    rootNote += PerfectFifth;
                    break;
                case Sixth:
                    rootNote += MinorSixth;
                    break;
                case Seventh:
                    rootNote += MinorSeventh;
                    break;
                case First:     //This is intended to do nothing
                default:
                    break;
            }
            break;
        case Lydian:
            switch(scaleDegree){
                case Second:
                    rootNote += MajorSecond;
                    break;
                case Third:
                    rootNote += MajorThird;
                    break;
                case Fourth:
                    rootNote += AugmentedFourth;
                    break;
                case Fifth:
                    rootNote += PerfectFifth;
                    break;
                case Sixth:
                    rootNote += MajorSixth;
                    break;
                case Seventh:
                    rootNote += MajorSeventh;
                    break;
                case First:     //This is intended to do nothing
                default:
                    break;
            }
            break;
        case Mixolydian:
            switch(scaleDegree){
                case Second:
                    rootNote += MajorSecond;
                    break;
                case Third:
                    rootNote += MajorThird;
                    break;
                case Fourth:
                    rootNote += PerfectFourth;
                    break;
                case Fifth:
                    rootNote += PerfectFifth;
                    break;
                case Sixth:
                    rootNote += MajorSixth;
                    break;
                case Seventh:
                    rootNote += MinorSeventh;
                    break;
                case First:     //This is intended to do nothing
                default:
                    break;
            }
            break;
        case Aeolian:
            switch(scaleDegree){
                case Second:
                    rootNote += MajorSecond;
                    break;
                case Third:
                    rootNote += MinorThird;
                    break;
                case Fourth:
                    rootNote += PerfectFourth;
                    break;
                case Fifth:
                    rootNote += PerfectFifth;
                    break;
                case Sixth:
                    rootNote += MinorSixth;
                    break;
                case Seventh:
                    rootNote += MinorSeventh;
                    break;
                case First:     //This is intended to do nothing
                default:
                    break;
            }
            break;
        case Locrian:
            switch(scaleDegree){
                case Second:
                    rootNote += MinorSecond;
                    break;
                case Third:
                    rootNote += MinorThird;
                    break;
                case Fourth:
                    rootNote += PerfectFourth;
                    break;
                case Fifth:
                    rootNote += DiminishedFifth;
                    break;
                case Sixth:
                    rootNote += MinorSixth;
                    break;
                case Seventh:
                    rootNote += MinorSeventh;
                    break;
                case First:     //This is intended to do nothing
                default:
                    break;
            }
            break;
    }

    return rootNote;
}


smallSection::smallSection(){
    for(int i = 0; i < 64; i++){
        melody[i].noteName = -1;
        melody[i].rhythm = -1;
    }
    for(int i = 0; i < 32; i++){
        harmony[i].noteRoot = -1;
        harmony[i].noteThird = -1;
        harmony[i].noteFifth = -1;
        harmony[i].rhythm = -1;
    }
}
smallSection::~smallSection(){

}

void smallSection::generateChords(int key){
    int color;
    int remainingNoteLength = bars * whole;
    harmonyPtr = &harmony[0];
    int currentChord = I;

    //continue until the sum of the note lengths equals the amount
    while(remainingNoteLength > 0){

        ////////////////////////
        //get rhythm
        ////////////////////////
        color = colorList->getColor();
        switch(color){
            //Each color has a priority system for each rhythm this ensures
            //  that you can always reach the correct amount of beats per section
            case red:
                if(remainingNoteLength >= whole)
                    harmonyPtr->rhythm = whole;
                else if(remainingNoteLength >= dotHalf)
                    harmonyPtr->rhythm = dotHalf;
                else if(remainingNoteLength >= half)
                    harmonyPtr->rhythm = half;
                else if(remainingNoteLength >= dotQuarter)
                    harmonyPtr->rhythm = dotQuarter;
                else if(remainingNoteLength >= quarter)
                    harmonyPtr->rhythm = quarter;
                else
                    harmonyPtr->rhythm = eighth;
                break;
            case orange:
                if(remainingNoteLength >= half)
                    harmonyPtr->rhythm = half;
                else if(remainingNoteLength >= quarter)
                    harmonyPtr->rhythm = quarter;
                else
                    harmonyPtr->rhythm = eighth;
                break;
            case yellow:
                if(remainingNoteLength >= quarter)
                    harmonyPtr->rhythm = quarter;
                else
                    harmonyPtr->rhythm = eighth;
                break;
            case green:
                if(remainingNoteLength >= dotQuarter)
                    harmonyPtr->rhythm = dotQuarter;
                else if(remainingNoteLength >= quarter)
                    harmonyPtr->rhythm = quarter;
                else
                    harmonyPtr->rhythm = eighth;
                break;
            case blue:
                if(remainingNoteLength >= whole)
                    harmonyPtr->rhythm = whole;
                else if(remainingNoteLength >= dotHalf)
                    harmonyPtr->rhythm = dotHalf;
                else if(remainingNoteLength >= half)
                    harmonyPtr->rhythm = half;
                else if(remainingNoteLength >= dotQuarter)
                    harmonyPtr->rhythm = dotQuarter;
                else if(remainingNoteLength >= quarter)
                    harmonyPtr->rhythm = quarter;
                else if(remainingNoteLength >= eighth)
                    harmonyPtr->rhythm = eighth;
                break;
            case lavenderII:
                harmonyPtr->rhythm = eighth;
                break;
            case black:
                if(remainingNoteLength >= half)
                    harmonyPtr->rhythm = half;
                else if(remainingNoteLength >= dotQuarter)
                    harmonyPtr->rhythm = dotQuarter;
                else if(remainingNoteLength >= quarter)
                    harmonyPtr->rhythm = quarter;
                else
                    harmonyPtr->rhythm = eighth;
                break;
            case white:
                if(remainingNoteLength >= quarter)
                    harmonyPtr->rhythm = quarter;
                else
                    harmonyPtr->rhythm = eighth;
                break;
            default:
                if(remainingNoteLength >= whole)
                    harmonyPtr->rhythm = whole;
                else if(remainingNoteLength >= dotHalf)
                    harmonyPtr->rhythm = dotHalf;
                else if(remainingNoteLength >= half)
                    harmonyPtr->rhythm = half;
                else if(remainingNoteLength >= dotQuarter)
                    harmonyPtr->rhythm = dotQuarter;
                else if(remainingNoteLength >= quarter)
                    harmonyPtr->rhythm = quarter;
                else if(remainingNoteLength >= dotEighth)
                    harmonyPtr->rhythm = dotEighth;
                else if(remainingNoteLength >= eighth)
                    harmonyPtr->rhythm = eighth;
                else
                    harmonyPtr->rhythm = sixteenth;
                break;
        }
        remainingNoteLength -= harmonyPtr->rhythm;

        ////////////////////////
        //get chord
        ////////////////////////
        if(currentChord == I){           //can go anywhere
            color = colorList->getColor();
            switch(color){
                case red:
                    currentChord = I;
                    break;
                case orange:
                    currentChord = ii;
                    break;
                case yellow:
                    currentChord = IV;
                    break;
                case green:
                    currentChord = V;
                    break;
                case blue:
                    currentChord = iii;
                    break;
                case lavenderII:
                    currentChord = vi;
                    break;
                case black:
                    currentChord = vii;
                    break;
                case white:
                default:
                    currentChord = ii;
                    break;
            }
        }else if(currentChord == ii){    //can go to vii V
            color = colorList->getColor();
            switch(color){
                case red:
                case orange:
                case yellow:
                case green:
                case white:
                    currentChord = V;
                    break;
                case blue:
                case lavenderII:
                case black:
                default:
                    currentChord = vii;
                    break;
            }
        }else if(currentChord == iii){   //can go to IV vi
            color = colorList->getColor();
            switch(color){
                case orange:
                case yellow:
                case green:
                case blue:
                    currentChord = IV;
                    break;
                case red:
                case lavenderII:
                case black:
                case white:
                default:
                    currentChord = vi;
                    break;
            }
        }else if(currentChord == IV){    //can go to I ii V vii
            color = colorList->getColor();
            switch(color){
                case red:
                case blue:
                    currentChord = ii;
                    break;
                case orange:
                case yellow:
                    currentChord = V;
                    break;
                case green:
                case lavenderII:
                    currentChord = I;
                    break;
                case black:
                case white:
                default:
                    currentChord = vii;
                    break;
            }
        }else if(currentChord == V){     //can go to vi I
            color = colorList->getColor();
            switch(color){
                case black:
                case red:
                case green:
                case orange:
                case yellow:
                    currentChord = I;
                    break;
                case blue:
                case lavenderII:
                case white:
                default:
                    currentChord = vi;
                    break;
            }
        }else if(currentChord == vi){    //can go to IV ii
            color = colorList->getColor();
            switch(color){
                case red:
                case blue:
                case yellow:
                case black:
                case white:
                    currentChord = IV;
                    break;
                case orange:
                case green:
                case lavenderII:
                default:
                    currentChord = ii;
                    break;
            }
        }else if(currentChord == vii){   //can go to I
            color = colorList->getColor();
            switch(color){
                case red:
                case orange:
                case yellow:
                case green:
                case blue:
                case lavenderII:
                case black:
                case white:
                default:
                    currentChord = I;
                    break;
            }
        }else{  //rest???
            currentChord = I;
        }

        ////////////////////////
        //get octave
        ////////////////////////
        int octave;
        color = colorList->getColor();
        switch(color){
            case black:
            case red:
            case green:
                octave = 2;
                break;
            case orange:
            case yellow:
            case lavenderII:
                octave = 3;
                break;
            case blue:
            case white:
            default:
                octave = 4;
                break;
        }
        harmonyPtr->noteRoot = getRootNote(key, currentChord, octave);

        //this prevents jumps

        if(harmonyPtr != &harmony[0]){
            chord* prev = harmonyPtr-1;
            if(((harmonyPtr->noteRoot) - (prev->noteRoot)) > Octave){
                harmonyPtr->noteRoot = (harmonyPtr->noteRoot) - Octave;
            }else if(((prev->noteRoot) - (harmonyPtr->noteRoot)) > Octave){
                harmonyPtr->noteRoot = (harmonyPtr->noteRoot) + Octave;
            }
        }

        ////////////////////////
        //build chord
        ////////////////////////
        if(currentChord == I || currentChord == IV || currentChord == IV){  //major
            harmonyPtr->noteThird = (harmonyPtr->noteRoot) + 4;
            harmonyPtr->noteFifth = (harmonyPtr->noteThird) + 3;
        }else if(currentChord == vii){  //diminished
            harmonyPtr->noteThird = (harmonyPtr->noteRoot) + 3;
            harmonyPtr->noteFifth = (harmonyPtr->noteThird) + 3;
        }else{  //minor
            harmonyPtr->noteThird = (harmonyPtr->noteRoot) + 3;
            harmonyPtr->noteFifth = (harmonyPtr->noteThird) + 4;
        }

        harmonyPtr++;
    }
    //finishes generation for harmony


}
void smallSection::generateMelody(int key){
    int color;
    int remainingNoteLength = bars * whole;
    melodyPtr = &melody[0];
    int currentChord = I;


    //continue until the sum of the note lengths equals the amount
    while(remainingNoteLength > 0){
        //first find the most recent chord
        int harmonySum = 0;
        int melodySum = (bars * whole) - remainingNoteLength;
        int chord = 0;
        while(harmonySum < melodySum){
            harmonySum += harmony[chord].rhythm;
            chord++;
        }



        ////////////////////////
        //get rhythm
        ////////////////////////
        color = colorList->getColor();
        switch(color){
                //Each color has a priority system for each rhythm this ensures
                //  that you can always reach the correct amount of beats per section
            case red:
                if(remainingNoteLength >= half)
                    melodyPtr->rhythm = half;
                else if(remainingNoteLength >= dotQuarter)
                    melodyPtr->rhythm = dotQuarter;
                else if(remainingNoteLength >= quarter)
                    melodyPtr->rhythm = quarter;
                else if(remainingNoteLength >= dotEighth)
                    melodyPtr->rhythm = dotEighth;
                else if(remainingNoteLength >= eighth)
                    melodyPtr->rhythm = eighth;
                else
                    melodyPtr->rhythm = sixteenth;
                break;
            case orange:
                melodyPtr->rhythm = sixteenth;
                break;
            case yellow:
                if(remainingNoteLength >= quarter)
                    melodyPtr->rhythm = quarter;
                else if(remainingNoteLength >= eighth)
                    melodyPtr->rhythm = eighth;
                else
                    melodyPtr->rhythm = sixteenth;
                break;
            case green:
                if(remainingNoteLength >= dotQuarter)
                    melodyPtr->rhythm = dotQuarter;
                else if(remainingNoteLength >= dotEighth)
                    melodyPtr->rhythm = dotEighth;
                else if(remainingNoteLength >= eighth)
                    melodyPtr->rhythm = eighth;
                else
                    melodyPtr->rhythm = sixteenth;
                break;
            case blue:
                if(remainingNoteLength >= eighth)
                    melodyPtr->rhythm = eighth;
                else
                    melodyPtr->rhythm = sixteenth;
                break;
            case lavenderII:
                if(remainingNoteLength >= quarter)
                    melodyPtr->rhythm = quarter;
                else if(remainingNoteLength >= dotEighth)
                    melodyPtr->rhythm = dotEighth;
                else if(remainingNoteLength >= eighth)
                    melodyPtr->rhythm = eighth;
                else
                    melodyPtr->rhythm = sixteenth;
                break;
            case black:
                if(remainingNoteLength >= quarter)
                    melodyPtr->rhythm = quarter;
                else if(remainingNoteLength >= dotEighth)
                    melodyPtr->rhythm = dotEighth;
                else if(remainingNoteLength >= eighth)
                    melodyPtr->rhythm = eighth;
                else
                    melodyPtr->rhythm = sixteenth;
                break;
            case white:
                if(remainingNoteLength >= eighth)
                    melodyPtr->rhythm = eighth;
                else
                    melodyPtr->rhythm = sixteenth;
                break;
            default:
                if(remainingNoteLength >= half)
                    melodyPtr->rhythm = half;
                else if(remainingNoteLength >= dotQuarter)
                    melodyPtr->rhythm = dotQuarter;
                else if(remainingNoteLength >= quarter)
                    melodyPtr->rhythm = quarter;
                else if(remainingNoteLength >= dotEighth)
                    melodyPtr->rhythm = dotEighth;
                else if(remainingNoteLength >= eighth)
                    melodyPtr->rhythm = eighth;
                else
                    melodyPtr->rhythm = sixteenth;
                break;
        }
        remainingNoteLength -= melodyPtr->rhythm;

        ////////////////////////
        //get next note
        ////////////////////////
        note* prevNote;
        int actualNote;
        int actualOctave;

        if(melodyPtr == &melody[0]){    //start melody randomly
            prevNote = NULL;
            color = colorList->getColor();
            switch(color){
                default:
                case red:
                    melodyPtr->noteName = getNoteInKey(key, First);
                    break;
                case orange:
                    melodyPtr->noteName = getNoteInKey(key, Fifth);
                    break;
                case yellow:
                    melodyPtr->noteName = getNoteInKey(key, Second);
                    break;
                case green:
                    melodyPtr->noteName = getNoteInKey(key, First);
                    break;
                case blue:
                    melodyPtr->noteName = getNoteInKey(key, Fourth);
                    break;
                case lavenderII:
                    melodyPtr->noteName = getNoteInKey(key, Third);
                    break;
                case black:
                    melodyPtr->noteName = getNoteInKey(key, Seventh);
                    break;
                case white:
                    melodyPtr->noteName = getNoteInKey(key, Sixth);
                    break;
            }
        }else{  //note based off previous note
            prevNote = melodyPtr-1;
            seperateNoteAndOctave(melodyPtr->noteName, &actualNote, &actualOctave);
            int modeToUse;
            modeToUse = getScale(key, actualNote);


            color = colorList->getColor();
            switch(color){
                default:
                case red:
                    melodyPtr->noteName = getNoteFromMode(key, modeToUse, Second);
                    break;
                case orange:
                    melodyPtr->noteName = getNoteFromMode(key, modeToUse, First);
                    break;
                case yellow:
                    melodyPtr->noteName = getNoteFromMode(key, modeToUse, Third);
                    break;
                case green:
                    melodyPtr->noteName = getNoteFromMode(key, modeToUse, Fourth);
                    break;
                case blue:
                    melodyPtr->noteName = getNoteFromMode(key, modeToUse, Fifth);
                    break;
                case lavenderII:
                    melodyPtr->noteName = getNoteFromMode(key, modeToUse, Second);
                    break;
                case black:
                    melodyPtr->noteName = getNoteFromMode(key, modeToUse, Third);
                    break;
                case white:
                    melodyPtr->noteName = getNoteFromMode(key, modeToUse, Sixth);
                    break;
            }

            if(((melodyPtr->noteName) - (prevNote->noteName)) > Octave){
                melodyPtr->noteName = (melodyPtr->noteName) - Octave;
            }else if(((prevNote->noteName) - (melodyPtr->noteName)) > Octave){
                    melodyPtr->noteName = (melodyPtr->noteName) + Octave;
            }
        }


        melodyPtr++;
    }
}
void smallSection::generatorLoop(int key, colorContainer* inColorList){
    colorList = inColorList;
    int color;
    //decide number of bars
    color = colorList->getColor();
    switch(color){
        case red:
            bars = 4;
            break;
        case orange:
            bars = 2;
            break;
        case yellow:
            bars = 4;
            break;
        case green:
            bars = 4;
            break;
        case blue:
           bars = 2;
            break;
        case lavenderII:
            bars = 2;
            break;
        case black:
            bars = 4;
            break;
        case white:
            bars = 4;
            break;
        default:
            bars = 4;
            break;
    }
    //generate chords
    generateChords(key);

    //generate melody
    generateMelody(key);
}
void smallSection::variationGeneratorLoop(int key, colorContainer* inColorList){
    colorList = inColorList;
    //TODO: create variation

    //for now the music will not have variation within each section
}
note smallSection::getNote(int n){
    return melody[n];
}
chord smallSection::getChord(int n){
    return harmony[n];
}

songSection::songSection(){

}
songSection::~songSection(){

}
void songSection::generatorLoop(int key, colorContainer* inColorList){
    colorList = inColorList;
    int color;

    //decide form
    color = colorList->getColor();
    switch(color){
        case red:
            smallForm = 0;
            break;
        case orange:
            smallForm = 1;
            break;
        case yellow:
            smallForm = 1;
            break;
        case green:
            smallForm = 0;
            break;
        case blue:
            smallForm = 1;
            break;
        case lavenderII:
            smallForm = 0;
            break;
        case black:
            smallForm = 1;
            break;
        case white:
            smallForm = 0;
            break;
        default:
            smallForm = 0;
            break;
    }

    //generate sections
    if(smallForm == 0){ //Binary form: aa'bb'
        sectionNum = 4;
        for(int i = 0; i < sectionNum; i++){
            if(i == 1 || i == 3)
                createVariationFromSection(i, i-1, key);
            else
                createSection(i, key);
        }
    }else{  //Ternary form: aba'
        sectionNum = 3;
        for(int i = 0; i < sectionNum; i++){
            if(i == 2){
                createVariationFromSection(i, i-2, key);
            }else{
                createSection(i, key);
            }
        }
    }
}
void songSection::variationGeneratorLoop(int key, colorContainer* inColorList){
    colorList = inColorList;

}
void songSection::createSection(int sectionNumber, int key){
    sections[sectionNumber].generatorLoop(key, colorList);
}
void songSection::createVariationFromSection(int sectionNumber, int variationNumber, int key){
    sections[sectionNumber] = sections[variationNumber];
    sections[sectionNumber].variationGeneratorLoop(key, colorList);
}
int songSection::getSectionNum(){
    return sectionNum;
}
smallSection* songSection::getSmallSection(int n){
    return &sections[n];
}

MidiFileGenerator::MidiFileGenerator():colorList(){
    if(TRACE_GENERATION){
        //open and create log file
    }
}
MidiFileGenerator::~MidiFileGenerator(){

}
void MidiFileGenerator::mainGeneratorLoop(){
    int color;

    if(TRACE_GENERATION){
        std::cout << "============================================" << std::endl;
        std::cout << "==========Starting Song Generation==========" << std::endl;
        std::cout << "============================================" << std::endl;
    }

    //decide melody instrument
    color = colorList.getColor();
    switch(color){  //Instruments correlate with VS1053
        case red:
        default:
            melodyInstrument = 80;  //Ocarina
            break;
        case orange:
            melodyInstrument = 41;  //Violin
            break;
        case yellow:
            melodyInstrument = 74;  //Flute
            break;
        case green:
            melodyInstrument = 5;   //Electric Piano
            break;
        case blue:
            melodyInstrument = 47;  //Harp
            break;
        case lavenderII:
            melodyInstrument = 10;  //Glockenspiel
            break;
        case black:
            melodyInstrument = 12;  //Vibraphone
            break;
        case white:
            melodyInstrument = 11;  //Music Box
            break;
    }
    if(TRACE_GENERATION){
        std::string instrument;
        switch(melodyInstrument){  //Instruments correlate with VS1053
            case 80:
            default:
                instrument = "Ocarina";  //Ocarina
                break;
            case 41:
                instrument = "Violin";  //Violin
                break;
            case 47:
                instrument = "Flute";  //Flute
                break;
            case 3:
                instrument = "Electric Piano";   //Electric Piano
                break;
            case 66:
                instrument = "Harp";  //Harp
                break;
            case 10:
                instrument = "Glockenspiel";  //Glockenspiel
                break;
            case 12:
                instrument = "Vibraphone";  //Vibraphone
                break;
            case 11:
                instrument = "Music Box";  //Music Box
                break;
        }
        std::cout << "Melody Instrument: " << instrument << " << " << getColorName(color) << std::endl;
    }

    //decide harmony instrument
    color = colorList.getColor();
    switch(color){  //Instruments correlate with VS1053
        case red:
        default:
            harmonyInstrument = 1;  //Acoustic Piano
            break;
        case orange:
            harmonyInstrument = 7;  //Harpsicord
            break;
        case yellow:
            harmonyInstrument = 49; //String Ensemble
            break;
        case green:
            harmonyInstrument = 14; //Xylophone
            break;
        case blue:
            harmonyInstrument = 5;  //Electric Piano
            break;
        case lavenderII:
            harmonyInstrument = 10; //Glockenspiel
            break;
        case black:
            harmonyInstrument = 95; //Halo Pad
            break;
        case white:
            harmonyInstrument = 90; //Warm Pad
            break;
    }
    if(TRACE_GENERATION){
        std::string instrument;
        switch(harmonyInstrument){  //Instruments correlate with VS1053
            case 1:
            default:
                instrument = "Acoustic Piano";  //Acoustic Piano
                break;
            case 7:
                instrument = "Harpsicord";  //Harpsicord
                break;
            case 49:
                instrument = "String Ensemble"; //String Ensemble
                break;
            case 14:
                instrument = "Xylophone"; //Xylophone
                break;
            case 5:
                instrument = "Electric Piano";  //Electric Piano
                break;
            case 10:
                instrument = "Glockenspiel"; //Glockenspiel
                break;
            case 89:
                instrument = "Halo Pad"; //Halo Pad
                break;
            case 90:
                instrument = "Warm Pad"; //Warm Pad
                break;
        }
        std::cout << "Harmony Instrument: " << instrument << " << " << getColorName(color) << std::endl;
    }

    //decide BPM
    color = colorList.getColor();
    switch(color){
        case red:
        case orange:
        default:
            bpm = 60;
            break;
        case yellow:
        case green:
            bpm = 80;
            break;
        case blue:
        case lavenderII:
            bpm = 100;
            break;
        case black:
        case white:
            bpm = 120;
            break;
    }
    if(TRACE_GENERATION){
        std::cout << "BPM: " << bpm << " << " << getColorName(color) << std::endl;
    }

    //decide Form
    color = colorList.getColor();
    switch(color){
        case red:
        default:
            largeForm = 0;
            break;
        case orange:
            largeForm = 1;
            break;
        case yellow:
            largeForm = 1;
            break;
        case green:
            largeForm = 0;
            break;
        case blue:
            largeForm = 1;
            break;
        case lavenderII:
            largeForm = 0;
            break;
        case black:
            largeForm = 1;
            break;
        case white:
            largeForm = 0;
            break;
    }
    if(TRACE_GENERATION){
        std::cout << "Large Form: " << largeForm<< " << " << getColorName(color) << std::endl;
    }

    //decide Key
    color = colorList.getColor();
    switch(color){
        case red:
        default:
            key = key_C;
            break;
        case orange:
            key = key_F;
            break;
        case yellow:
            key = key_G;
            break;
        case green:
            key = key_Bb;
            break;
        case blue:
            key = key_D;
            break;
        case lavenderII:
            key = key_Eb;
            break;
        case black:
            key = key_A;
            break;
        case white:
            key = key_Ab;
            break;
    }
    if(TRACE_GENERATION){
        std::cout << "Key: " << key << " << " << getColorName(color) << std::endl;
    }

    //generate sections
    if(largeForm == 0){ //Binary form: AA'BB'
        sectionNum = 4;
        for(int i = 0; i < sectionNum; i++){
            if(i == 1 || i == 3)
                createVariationFromSection(i, i-1);
            else
                createSection(i);
        }
    }else{  //Ternary form: ABA'
        sectionNum = 3;
        for(int i = 0; i < sectionNum; i++){
            if(i == 2){
                createVariationFromSection(i, i-2);
            }else{
                createSection(i);
            }
        }
    }

    //output midi and seed
    if(TRACE_GENERATION)
        colorList.printSeed();

    outputToFile();
}
void MidiFileGenerator::createSection(int sectionNumber){
    sections[sectionNumber].generatorLoop(key, &colorList);
}
void MidiFileGenerator::createVariationFromSection(int sectionNumber, int variationNumber){
    sections[sectionNumber] = sections[variationNumber];
    sections[variationNumber].variationGeneratorLoop(key, &colorList);
}
void MidiFileGenerator::outputToFile(){
    //create file
    MidiFile midiFile;
    int tpq = 120;
    int velocity;
    int channel;
    int track;
    int actiontick = 0;

    //header information for midi file
    midiFile.addTracks(2);
    midiFile.setTicksPerQuarterNote(tpq);
    midiFile.addTrackName(0, 0, "generatedMIDI");
    midiFile.addTempo(0, 0, bpm);


    //melody track header
    actiontick = 0;
    velocity = 80;
    channel = 0;
    track = 1;

    midiFile.addTrackName(track, actiontick, "Melody");
    midiFile.addPatchChange(track, actiontick, channel, melodyInstrument);


    //melody track notes
    smallSection* sectionNav = nullptr;
    for(int i = 0; i < sectionNum; i++){
        for(int j = 0; j < sections[i].getSectionNum(); j++){
            sectionNav = sections[i].getSmallSection(j);

            int n = 0;
            note tempNote = sectionNav->getNote(n);
            while(tempNote.rhythm > 0){
                if(tempNote.noteName == -1){   //if rest
                    //for how long
                    actiontick += tpq * tempNote.rhythm / 4;
                }else{
                    //turn on notes
                    midiFile.addNoteOn(track, actiontick, channel, tempNote.noteName, velocity);

                    //for how long
                    actiontick += tpq * tempNote.rhythm / 4;

                    //turn off notes
                    midiFile.addNoteOff(track, actiontick, channel, tempNote.noteName, velocity);
                }
                //increment
                n++;
                tempNote = sectionNav->getNote(n);
            }
        }
    }

    //harmony track header
    actiontick = 0;
    velocity = 60;
    channel = 1;
    track = 2;

    midiFile.addTrackName(track, actiontick, "Harmony");
    midiFile.addPatchChange(track, actiontick, channel, harmonyInstrument);


    //harmony track notes
    sectionNav = nullptr;
    for(int i = 0; i < sectionNum; i++){
        for(int j = 0; j < sections[i].getSectionNum(); j++){
            sectionNav = sections[i].getSmallSection(j);

            int n = 0;
            chord tempChord = sectionNav->getChord(n);
            while(tempChord.rhythm > 0){
                if(tempChord.noteRoot == -1){   //if rest
                    //for how long
                    actiontick += tpq * tempChord.rhythm / 4;
                }else{
                    //turn on notes
                    midiFile.addNoteOn(track, actiontick, channel, tempChord.noteRoot, velocity);
                    midiFile.addNoteOn(track, actiontick, channel, tempChord.noteThird, velocity);
                    midiFile.addNoteOn(track, actiontick, channel, tempChord.noteFifth, velocity);

                    //for how long
                    actiontick += tpq * tempChord.rhythm / 4;

                    //turn off notes
                    midiFile.addNoteOff(track, actiontick, channel, tempChord.noteRoot, velocity);
                    midiFile.addNoteOff(track, actiontick, channel, tempChord.noteThird, velocity);
                    midiFile.addNoteOff(track, actiontick, channel, tempChord.noteFifth, velocity);
                }
                //increment
                n++;
                tempChord = sectionNav->getChord(n);
            }
        }
    }

    //ending
    midiFile.sortTracks();
    midiFile.write("song.mid");
    //midiFile.write(colorList.getSeedNumber() + ".mid");

    //writeMSPFile();

}
void MidiFileGenerator::writeMSPFile(){
    std::ofstream mspFile;
    mspFile.open("FreqDurFile.txt");

    float freq = 0.0;
    float length = 0.0;
    int tpq = 120;

    //melody track notes
    smallSection* sectionNav = nullptr;
    for(int i = 0; i < sectionNum; i++){
        for(int j = 0; j < sections[i].getSectionNum(); j++){
            sectionNav = sections[i].getSmallSection(j);

            int n = 0;
            note tempNote = sectionNav->getNote(n);
            while(tempNote.rhythm > 0){
                if(tempNote.noteName == -1){   //if rest
                    //output frequency
                    freq = 0;
                    //output length
                    length = tpq * tempNote.rhythm / 4;
                }else{
                    //output frequency
                    freq = getFrequency(tempNote.noteName);
                    //output length
                    length = tpq * tempNote.rhythm / 4;
                }
                //increment
                n++;
                tempNote = sectionNav->getNote(n);
                
                //to file
                mspFile << freq;
                mspFile << " ";
                mspFile << length;
                mspFile << std::endl;
            }
        }
    }

    mspFile.close();
}
