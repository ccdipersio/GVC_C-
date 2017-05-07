#include "gvc_utils.h"

void setInitialValues(string &infinVerb, string &subPronoun) {
    getInfinVerb(infinVerb);
    getSubPronoun(subPronoun);
}

void getInfinVerb(string &infinVerb) {
    int infinVerbLen;
    do {
        cout << "Infinitive Verb: ";
        cin >> infinVerb;
        capitalizeWord(infinVerb);
        infinVerbLen = infinVerb.length();
    } while (infinVerb.compare("SEIN") != 0 && infinVerb.compare("TUN") != 0 && (infinVerb.at(infinVerbLen - 2) != 'E' || infinVerb.at(infinVerbLen - 1) != 'N') && (infinVerb.at(infinVerbLen - 3) != 'E' || (infinVerb.at(infinVerbLen - 2) != 'R' && infinVerb.at(infinVerbLen - 2) != 'L') || infinVerb.at(infinVerbLen - 1) != 'N'));
}

void getSubPronoun(string &subPronoun) {
    do {
        cout << "Subject Pronoun: ";
        cin >> subPronoun;
        capitalizeWord(subPronoun);
    } while (subPronoun.compare("ICH") !=0 && subPronoun.compare("DU") != 0 && subPronoun.compare("ER") != 0 && subPronoun.compare("SIE") != 0 && subPronoun.compare("ES") != 0 && subPronoun.compare("WIR") != 0 && subPronoun.compare("IHR") != 0 && subPronoun.compare("SIEP") != 0);
}

void capitalizeWord(string &word) {
    int wordLen = word.length();
    for (int i = 0; i < wordLen; i++)
        word[i] = toupper(word[i]);
}

