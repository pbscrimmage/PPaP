/**
 * eng_grammar.cpp
 *
 * Author: Patrick Rummage
 *
 * Objective: 
 *      Write a program to evaluate the correctness of a series of words
 *      based on the folowing primitive grammar.
 *
 *      Sentence:
 *          Noun Verb
 *          Article Noun Verb
 *          Sentence Conjunction Sentence
 *      
 *      Conjunction:
 *          "and"
 *          "or"
 *          "but"
 *
 *      Noun:
 *          "birds"
 *          "fish"
 *          "C++"
 *      
 *      Verb:
 *          "rules"
 *          "fly"
 *          "swim"
 *      
 *      Article:
 *          "the"
 *
 * TODO: separate sentence() into multiple functions
 */
#include "../std_lib_facilities.h"

bool sentence()
{
    string previous = "";
    string word;
    cin >> word;
    while(word != ".") {
        /*ARTICLE*/
        if (word == "the") {
            if (previous == "" || previous == "and" || previous == "or" ||
                    previous == "but") {
                previous = word;
            }
            else {
                return false;
            }
        }
        /*NOUNS*/
        else if (word == "birds" || word == "fish" || word == "C++") {
            if (previous == "" || previous == "the" || previous == "and"
                    || previous == "or" || previous == "but") {
                previous = word;    
            }
            else {
                return false;
            }
        }
        /*VERBS*/
        else if (word == "rules" || word == "fly" || word == "swim") {
            if (previous == "birds" || previous == "fish" || 
                    previous == "C++") {
                previous = word;
            }
            else {
                return false;
            }
        }
        /*CONJUNCTIONS*/
        else if (word == "and" || word == "or" || word == "but") {
            if (previous == "rules" || previous == "fly" ||
                    previous == "swim") {
                previous = word;
            }
            else {
                return false;
            }
        }
        /*BAD INPUT*/
        else {
            return false;
        }
        cin >> word;
    }//End while
    /*Recieved full stop*/
    if (previous == "rules" || previous == "fly" || previous == "swim") {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    cout << "Enter a sentence followed by a full stop ' . ':\n";
    bool isSentence = sentence();
    if (isSentence) {
        cout << "OK\n";
    }
    else {
        cout << "Not OK.\n";
    }

    return 0;
}

