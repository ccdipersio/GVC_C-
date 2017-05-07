#include "translation_utils.h"

void getInVerb(string &inVerb) {
    cout << "English Infinitive Verb: ";
    getline(cin, inVerb);
    capitalizeWord(inVerb);

    if (inVerb.at(0) == 'T' && inVerb.at(1) == 'O') {
        int space = inVerb.find_first_of(' ');
        if (space != -1)
            inVerb.erase(space, 1);
        inVerb.erase(0,2);
    }
}

void getInSubPronoun(string &inSubPronoun, bool &isPluralYou) {
    do {
        cout << "English Subject Pronoun: ";
        cin >> inSubPronoun;
        capitalizeWord(inSubPronoun);
    } while (inSubPronoun.compare("I") != 0 && inSubPronoun.compare("YOU") != 0 && inSubPronoun.compare("HE") != 0 && inSubPronoun.compare("SHE") != 0 && inSubPronoun.compare("IT") != 0 && inSubPronoun.compare("WE") != 0 && inSubPronoun.compare("THEY") != 0);

    if (inSubPronoun.compare("YOU") == 0) {
        char choice;
        do {
            cout << "Plural 'YOU'? (y/n): ";
            cin >> choice;
            cin.sync();
            choice = toupper(choice);
        } while (choice != 'Y' && choice != 'N');
        if (choice == 'Y')
            isPluralYou = true;
        else
            isPluralYou = false;
    }
}

void translationControl(string &inVerb, string &translatedVerb, string &inSubPronoun, string &translatedSubPronoun, bool isPluralYou) {
    if (inSubPronoun.compare("I") == 0)
        translatedSubPronoun.assign("ICH");
    else if (inSubPronoun.compare("YOU") == 0 && !isPluralYou)
        translatedSubPronoun.assign("DU");
    else if (inSubPronoun.compare("HE") == 0)
        translatedSubPronoun.assign("ER");
    else if (inSubPronoun.compare("SHE") == 0)
        translatedSubPronoun.assign("SIE");
    else if (inSubPronoun.compare("IT") == 0)
        translatedSubPronoun.assign("ES");
    else if (inSubPronoun.compare("WE") == 0)
        translatedSubPronoun.assign("WIR");
    else if (inSubPronoun.compare("YOU") == 0 && isPluralYou)
        translatedSubPronoun.assign("IHR");
    else if (inSubPronoun.compare("THEY") == 0)
        translatedSubPronoun.assign("SIEP");

    ifstream file("verbs_with_translation.txt");
    string line;
    string englishVerb;
    while (getline(file, line)) {
        int comma = line.find(',');
        englishVerb.assign(line.substr(comma + 1, line.length() - 2));
        capitalizeWord(englishVerb);
        if (inVerb.compare(englishVerb) == 0) {
            translatedVerb.assign(line.substr(0, comma));
            capitalizeWord(translatedVerb);
            break;
        }
    }
    file.close();
}
