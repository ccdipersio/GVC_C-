#include "gvc_utils.h"
#include "conjugation_utils.h"
#include "translation_utils.h"

void conjugate();
void conjugate(string translatedVerb, string translatedSubPronoun);
void translateAndConjugate();

int main() {
    char choice;
    do {
        cout << "Conjugate or Translate and Conjugate? (c/t): ";
        cin >> choice;
        cin.sync();
        choice = toupper(choice);
    } while (choice != 'C' && choice != 'T');

    if (choice == 'C')
        conjugate();
    else
        translateAndConjugate();

    return 0;
}

void conjugate() {

    string infinVerb;
    string subPronoun;

    setInitialValues(infinVerb, subPronoun);

    string conjVerb;
    string separablePrefix;
    string inseparablePrefix;

    setInitialConjVerb(conjVerb, infinVerb, subPronoun, separablePrefix, inseparablePrefix);

    conjugationControl(conjVerb, infinVerb, subPronoun);

    if (separablePrefix.compare("NONE") == 0 && inseparablePrefix.compare("NONE") == 0)
        cout << subPronoun << " " << conjVerb << endl;
    else if (separablePrefix.compare("NONE") != 0 && inseparablePrefix.compare("NONE") == 0)
        cout << subPronoun << " " << conjVerb << " " << separablePrefix << endl;
    else if (separablePrefix.compare("NONE") == 0 && inseparablePrefix.compare("NONE") != 0)
        cout << subPronoun << " " << inseparablePrefix << conjVerb << endl;
    else
        cout << subPronoun << " " << inseparablePrefix << conjVerb << " " << separablePrefix << endl;

    return;
}

void conjugate(string translatedVerb, string translatedSubPronoun) {
    string infinVerb = translatedVerb;
    string subPronoun = translatedSubPronoun;

    string conjVerb;
    string separablePrefix;
    string inseparablePrefix;

    setInitialConjVerb(conjVerb, infinVerb, subPronoun, separablePrefix, inseparablePrefix);

    conjugationControl(conjVerb, infinVerb, subPronoun);

    if (separablePrefix.compare("NONE") == 0 && inseparablePrefix.compare("NONE") == 0)
        cout << subPronoun << " " << conjVerb << endl;
    else if (separablePrefix.compare("NONE") != 0 && inseparablePrefix.compare("NONE") == 0)
        cout << subPronoun << " " << conjVerb << " " << separablePrefix << endl;
    else if (separablePrefix.compare("NONE") == 0 && inseparablePrefix.compare("NONE") != 0)
        cout << subPronoun << " " << inseparablePrefix << conjVerb << endl;
    else
        cout << subPronoun << " " << inseparablePrefix << conjVerb << " " << separablePrefix << endl;

    return;
}

void translateAndConjugate() {
    string inVerb;
    getInVerb(inVerb);
    string inSubPronoun;
    bool isPluralYou;
    getInSubPronoun(inSubPronoun, isPluralYou);
    string translatedSubPronoun;
    string translatedVerb;
    translationControl(inVerb, translatedVerb, inSubPronoun, translatedSubPronoun, isPluralYou);
    conjugate(translatedVerb, translatedSubPronoun);
}
