#ifndef TRANSLATION_UTILS_H_INCLUDED
#define TRANSLATION_UTILS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "gvc_utils.h"

using namespace std;

void getInVerb(string &inVerb);
void getInSubPronoun(string &inSubPronoun, bool &isPluralYou);
void translationControl(string &inVerb, string &translatedVerb, string &inSubPronoun, string &translatedSubPronoun, bool isPluralYou);



#endif // TRANSLATION_UTILS_H_INCLUDED
