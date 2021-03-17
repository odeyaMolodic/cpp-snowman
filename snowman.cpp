#include "snowman.hpp"
#include <iostream>
using namespace std;

const string H[] = {" _===_ ", "  ___  \n ..... ", "   _  \n  /_\\  ", "  ___  \n (_*_) "}; //for Hat
const string N[] = {",", ".", "_", " "}; //for Nose
const string LR[] = {".", "o", "O", "-"}; //for Left and Right Eye
const string Xup[] = {" ", "\\", " ", " "}; //for Left Arm
const string Yup[] = {" ", "/", " ", " "}; //for Right Arm
const string Xdown[] = {"<", " ", "/", " "}; //for Left Arm
const string Ydown[] = {">", " ", "\\", " "}; //for Right Arm
const string T[] = {"( : )", "(] [)", "(> <)", "(   )"}; //for Torso
const string B[] = {" ( : ) ", " (\" \") ", " (___) ", " (   ) "}; //for Base

int n;

namespace ariel{

    int getIndex(){
        int index = n%10;
        if (index>4 || index<1) {
            throw out_of_range("The number in each choice must be between 1 and 4");
        }
        n = n/10;
        
        return index;

    }

    /**
     * a function that takes in an eight character string in the format HNLRXYTB
     * where each letter is a digit from 1 to 4 that denotes which preset to use for the corresponding section of the snowperson. 
     * Print the full snowperson to stdout.
    */
    string snowman(int num){

        if (num<11111111 || num>44444444) {
            throw out_of_range{"The number is not 8 digits long"};
        }
        n = num;

        string strSnowman = B[getIndex()-1] + "\n";

        int torsoIndex = getIndex();
        int rightArmIndex = getIndex();
        strSnowman = Ydown[rightArmIndex-1] + "\n" + strSnowman;

        strSnowman = T[torsoIndex] + strSnowman;

        int leftArmIndex = getIndex();
        strSnowman = Xdown[leftArmIndex-1] + strSnowman;

        strSnowman = Yup[rightArmIndex-1] + "\n" + strSnowman;

        strSnowman = LR[getIndex()-1] + ")" + strSnowman;

        int leftEyeIndex = getIndex();
        strSnowman = N[getIndex()-1] + strSnowman;

        strSnowman = "(" + LR[leftEyeIndex-1] + strSnowman;

        strSnowman = Xup[leftArmIndex-1] + strSnowman;

        strSnowman = H[getIndex()-1] + "\n" + strSnowman;

        return strSnowman;

    }

}