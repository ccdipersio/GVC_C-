#ifndef CONJUGATION_UTILS_H_INCLUDED
#define CONJUGATION_UTILS_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void setInitialConjVerb(string &conjVerb, string &infinVerb, string subPronoun, string &separablePrefix, string &inseparablePrefix);
void prefixSet(string &infinVerb, string &separablePrefix, string &inseparablePrefix);
char stemChangeCheck(string infinVerb);
void conjugationControl(string &conjVerb, string &infinVerb, string subPronoun);
void conjugateSein(string &conjVerb, string subPronoun);
void conjugateModal(string &conjVerb, string subPronoun);
void conjugateERN_ELN(string &conjVerb, char r_or_l, string subPronoun);
void conjugateNormal(string &conjVerb, string subPronoun);

#endif // CONJUGATION_UTILS_H_INCLUDED
