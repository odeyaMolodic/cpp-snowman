/**
 * DO TOU WANT TO BUILD A SNOWMAN?
 * a program that takes in an eight digit number in the format HNLRXYTB
 * where each letter is a digit from 1 to 4 that denotes which preset to use for the corresponding section of the snowman. 
 * 
 * Author: Odeya Lavi
 * Since : 2021-03
 */

#include "snowman.hpp"
#include <iostream>
#include<array>
using namespace std;

const array<string,4> H = {" _===_ ", "  ___  \n ..... ", "   _  \n  /_\\  ", "  ___  \n (_*_) "}; //for Hat
const array<string,4> N = {",", ".", "_", " "}; //for Nose
const array<string,4> LR = {".", "o", "O", "-"}; //for Left and Right Eye
const array<string,4> Xup = {" ", "\\", " ", " "}; //for Left Arm
const array<string,4> Yup = {" ", "/", " ", " "}; //for Right Arm
const array<string,4> Xdown = {"<", " ", "/", " "}; //for Left Arm
const array<string,4> Ydown = {">", " ", "\\", " "}; //for Right Arm
const array<string,4> T = {"( : )", "(] [)", "(> <)", "(   )"}; //for Torso
const array<string,4> B = {" ( : ) ", " (\" \") ", " (___) ", " (   ) "}; //for Base

const int MAX = 44444444;
const int MIN = 11111111;
const int SIZE = 8;
const int DIGIT = 10;

namespace ariel{

    /*
     * The function decomposes the input into digits
     * get a reference to the input number
     * Return the last digit (and deletes it).
     */
    int getIndex(int &ref){
        int index = ref%DIGIT;
        if (index>4 || index<1) {
            throw out_of_range("Invalid input, the number in each choice must be between 1 and 4");
        }
        ref = ref/DIGIT;
        
        return index;

    }

    /*
     * Create and print the full snowman to stdout.
     */
    string snowman(int num){

        if (num <= 0) {
            throw out_of_range("Invalid input, the number must be positive");
        }

        if (to_string(num).size() < SIZE || to_string(num).size() > SIZE) {
            throw out_of_range("Invalid input, the number is not 8 digits long");
        }

        if (num<MIN || num>MAX) {
            throw out_of_range{"Invalid input, the number in each choice must be between 1 and 4"};
        }

        string strSnowman = B.at(getIndex(num)-1) + "\n";

        int torsoIndex = getIndex(num);
        int rightArmIndex = getIndex(num);
        strSnowman = Ydown.at(rightArmIndex-1) + "\n" + strSnowman;

        strSnowman = T.at(torsoIndex-1) + strSnowman;

        int leftArmIndex = getIndex(num);
        strSnowman = Xdown.at(leftArmIndex-1) + strSnowman;

        strSnowman = Yup.at(rightArmIndex-1) + "\n" + strSnowman;

        strSnowman = LR.at(getIndex(num)-1) + ")" + strSnowman;

        int leftEyeIndex = getIndex(num);
        strSnowman = N.at(getIndex(num)-1) + strSnowman;

        strSnowman = "(" + LR.at(leftEyeIndex-1) + strSnowman;

        strSnowman = Xup.at(leftArmIndex-1) + strSnowman;

        strSnowman = H.at(getIndex(num)-1) + "\n" + strSnowman;

        return strSnowman;

    }

}