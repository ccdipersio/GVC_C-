#include "conjugation_utils.h"

void setInitialConjVerb(string &conjVerb, string &infinVerb, string subPronoun, string &separablePrefix, string &inseparablePrefix) {
    prefixSet(infinVerb, separablePrefix, inseparablePrefix);
    char type;

    if (subPronoun.compare("DU") == 0 || subPronoun.compare("ER") == 0 || subPronoun.compare("SIE") == 0 || subPronoun.compare("ES") == 0)
        type = stemChangeCheck(infinVerb);

    int conjVerbLen;
    if (infinVerb.compare("SEIN") == 0)
        conjVerbLen = infinVerb.length();
    else if (infinVerb.compare("TUN") == 0)
        conjVerbLen = infinVerb.length() - 1;
    else if (infinVerb.at(infinVerb.length() - 2) == 'E' && infinVerb.at(infinVerb.length() - 1) == 'N')
        conjVerbLen = infinVerb.length() - 2;
    else
        conjVerbLen = infinVerb.length() - 3;

    conjVerb.assign(infinVerb.substr(0, conjVerbLen));

    if (type == 'x') {
        int e_index = conjVerb.find('E');
        conjVerb.at(e_index) = 'I';
    } else if (type == 'a' || type == 'e') {
        int change_pos = conjVerb.find((char)(type - 32));
        if (type == 'a')
            conjVerb.insert(conjVerb.begin() + change_pos + 1, 'E');
        else
            conjVerb.insert(conjVerb.begin() + change_pos, 'I');
    }
}

void prefixSet(string &infinVerb, string &separablePrefix, string &inseparablePrefix) {
    if (infinVerb.at(0) == 'A' && infinVerb.at(1) == 'B')
        separablePrefix.assign("AB");
    else if (infinVerb.at(0) == 'A' && infinVerb.at(1) == 'N')
        separablePrefix.assign("AN");
    else if (infinVerb.at(0) == 'A' && infinVerb.at(1) == 'U' && infinVerb.at(2) == 'F')
        separablePrefix.assign("AUF");
    else if (infinVerb.at(0) == 'A' && infinVerb.at(1) == 'U' && infinVerb.at(2) == 'S')
        separablePrefix.assign("AUS");
    else if (infinVerb.at(0) == 'B' && infinVerb.at(1) == 'E' && infinVerb.at(2) == 'I')
        separablePrefix.assign("BEI");
    else if (infinVerb.at(0) == 'D' && infinVerb.at(1) == 'U' && infinVerb.at(2) == 'R' && infinVerb.at(3) == 'C' && infinVerb.at(4) == 'H')
        separablePrefix.assign("DURCH");
    else if (infinVerb.at(0) == 'E' && infinVerb.at(1) == 'I' && infinVerb.at(2) == 'N')
        separablePrefix.assign("EIN");
    else if (infinVerb.at(0) == 'F' && infinVerb.at(1) == 'O' && infinVerb.at(2) == 'R' && infinVerb.at(3) == 'T')
        separablePrefix.assign("FORT");
    else if (infinVerb.at(0) == 'M' && infinVerb.at(1) == 'I' && infinVerb.at(2) == 'T')
        separablePrefix.assign("MIT");
    else if (infinVerb.at(0) == 'N' && infinVerb.at(1) == 'A' && infinVerb.at(2) == 'C' && infinVerb.at(3) == 'H')
        separablePrefix.assign("NACH");
    else if (infinVerb.at(0) == 'V' && infinVerb.at(1) == 'O' && infinVerb.at(2) == 'R')
        separablePrefix.assign("VOR");
    else if (infinVerb.at(0) == 'W' && infinVerb.at(1) == 'E' && infinVerb.at(2) == 'G')
        separablePrefix.assign("WEG");
    else if (infinVerb.at(0) == 'Z' && infinVerb.at(1) == 'U' && infinVerb.at(2) == 'R' && infinVerb.at(3) == 'U' && infinVerb.at(4) == 'E' && infinVerb.at(5) == 'C' && infinVerb.at(6) == 'K')
        separablePrefix.assign("ZURUECK");
    else if (infinVerb.at(0) == 'Z' && infinVerb.at(1) == 'U')
        separablePrefix.assign("ZU");
    else if (infinVerb.at(0) == 'Z' && infinVerb.at(1) == 'U' && infinVerb.at(2) == 'S' && infinVerb.at(3) == 'A' && infinVerb.at(4) == 'M' && infinVerb.at(5) == 'M' && infinVerb.at(6) == 'E' && infinVerb.at(7) == 'N')
        separablePrefix.assign("ZUSAMMEN");
    else
        separablePrefix.assign("NONE");

    if (infinVerb.at(0) == 'B' && infinVerb.at(1) == 'E')
        inseparablePrefix.assign("BE");
    else if (infinVerb.at(0) == 'E' && infinVerb.at(1) == 'M' && infinVerb.at(2) == 'P')
        inseparablePrefix.assign("EMP");
    else if (infinVerb.at(0) == 'E' && infinVerb.at(1) == 'N' && infinVerb.at(2) == 'T')
        inseparablePrefix.assign("ENT");
    else if (infinVerb.at(0) == 'E' && infinVerb.at(1) == 'R')
        inseparablePrefix.assign("ER");
    else if (infinVerb.at(0) == 'G' && infinVerb.at(1) == 'E')
        inseparablePrefix.assign("GE");
    else if (infinVerb.at(0) == 'M' && infinVerb.at(1) == 'I' && infinVerb.at(2) == 'S' && infinVerb.at(3) == 'S')
        inseparablePrefix.assign("MISS");
    else if (infinVerb.at(0) == 'V' && infinVerb.at(1) == 'E' && infinVerb.at(2) == 'R')
        inseparablePrefix.assign("VER");
    else if (infinVerb.at(0) == 'V' && infinVerb.at(1) == 'O' && infinVerb.at(2) == 'L' && infinVerb.at(3) == 'L')
        inseparablePrefix.assign("VOLL");
    else if (infinVerb.at(0) == 'Z' && infinVerb.at(1) == 'E' && infinVerb.at(2) == 'R')
        inseparablePrefix.assign("ZER");
    else
        inseparablePrefix.assign("NONE");

    if (separablePrefix.compare("NONE") != 0) {
        int prefixLen = separablePrefix.length();
        string temp;
        temp.assign(infinVerb.substr(prefixLen));
        infinVerb.assign(temp);
    }
    if (inseparablePrefix.compare("NONE") != 0) {
        int prefixLen = inseparablePrefix.length();
        string temp;
        temp.assign(infinVerb.substr(prefixLen));
        infinVerb.assign(temp);
    }
}

char stemChangeCheck(string infinVerb) {
    ifstream file("stem_change_verbs.txt");
    string line;
    while (getline(file, line)) {
        int comma = line.find(',');
        string verb;
        verb.assign(line.substr(0, comma));
        if (infinVerb.compare(verb) == 0) {
            file.close();
            return line.substr(comma + 1).at(0);
        }
    }
    file.close();
    return 'z';
}

void conjugationControl(string &conjVerb, string &infinVerb, string subPronoun) {
    if (conjVerb.compare("SEIN") == 0)
        conjugateSein(conjVerb, subPronoun);
    else if (infinVerb.compare("MUESSEN") == 0 || infinVerb.compare("KOENNEN") == 0 || infinVerb.compare("MOEGEN") == 0 || infinVerb.compare("DUERFEN") == 0 || infinVerb.compare("SOLLEN") == 0 || infinVerb.compare("WOLLEN") == 0 || infinVerb.compare("WISSEN") == 0)
        conjugateModal(conjVerb, subPronoun);
    else if (infinVerb.at(infinVerb.length() - 3) == 'E' && (infinVerb.at(infinVerb.length() - 2) == 'R' || infinVerb.at(infinVerb.length() - 2) == 'L') && infinVerb.at(infinVerb.length() - 1) == 'N') {
        char r_or_l = infinVerb.at(infinVerb.length() - 2);
        conjugateERN_ELN(conjVerb, r_or_l, subPronoun);
    } else
        conjugateNormal(conjVerb, subPronoun);
}

void conjugateSein(string &conjVerb, string subPronoun) {
    if (subPronoun.compare("ICH") == 0)
        conjVerb.assign("BIN");
    else if (subPronoun.compare("DU") == 0)
        conjVerb.assign("BIST");
    else if (subPronoun.compare("ER") == 0 || subPronoun.compare("SIE") == 0 || subPronoun.compare("ES") == 0)
        conjVerb.assign("IST");
    else if (subPronoun.compare("WIR") == 0 || subPronoun.compare("IHR") == 0)
        conjVerb.assign("SIND");
    else if (subPronoun.compare("IHR") == 0)
        conjVerb.assign("SEID");
    else
        conjVerb.assign("COULD NOT CONJUGATE SEIN");
}

void conjugateModal(string &conjVerb, string subPronoun) {
    if (subPronoun.compare("ICH") == 0 || subPronoun.compare("DU") == 0 || subPronoun.compare("ER") == 0 || subPronoun.compare("SIE") == 0 || subPronoun.compare("ES") == 0) {
        if (conjVerb.compare("MUESS") == 0) {
            conjVerb.erase(2, 1);
            if (subPronoun.compare("DU") == 0)
                conjVerb.append(1, 'T');
        } else if (conjVerb.compare("KOENN") == 0 || conjVerb.compare("MOEG") == 0 || conjVerb.compare("DUERF") == 0) {
            conjVerb.replace(1, 2, 1, 'A');
            if (subPronoun.compare("DU") == 0)
                conjVerb.append("ST");
        } else if (conjVerb.compare("SOLL") == 0) {
            if (subPronoun.compare("DU") == 0)
                conjVerb.append("ST");
        } else if (conjVerb.compare("WOLL") == 0) {
            conjVerb.replace(1, 1, 1, 'I');
            if (subPronoun.compare("DU") == 0)
                conjVerb.append("ST");
        } else if (conjVerb.compare("WISS") == 0) {
            conjVerb.insert(1, 1, 'E');
            if (subPronoun.compare("DU") == 0)
                conjVerb.append(1, 'T');
        }
    } else {
        if (subPronoun.compare("WIR") == 0 || subPronoun.compare("SIEP") == 0)
            conjVerb.append("EN");
        else
            conjVerb.append(1, 'T');
    }
}

void conjugateERN_ELN(string &conjVerb, char r_or_l, string subPronoun) {
    if (subPronoun.compare("ICH") == 0) {
        conjVerb.append(1, r_or_l);
        conjVerb.append(1, 'E');
    } else {
        conjVerb.append(1, 'E');
        conjVerb.append(1, r_or_l);
        if (subPronoun.compare("DU") == 0)
            conjVerb.append("ST");
        else if (subPronoun.compare("ER") == 0 || subPronoun.compare("SIE") == 0 || subPronoun.compare("ES") == 0 || subPronoun.compare("IHR") == 0)
            conjVerb.append(1, 'T');
        else
            conjVerb.append(1, 'N');
    }
}

void conjugateNormal(string &conjVerb, string subPronoun) {
    if (conjVerb.compare("HAB") == 0 && (subPronoun.compare("DU") == 0 || subPronoun.compare("ER") == 0 || subPronoun.compare("SIE") == 0 || subPronoun.compare("ES") == 0))
        conjVerb.erase(conjVerb.length() - 1, 1);
    else if (conjVerb.compare("WIRD") == 0 && subPronoun.compare("DU") == 0)
        conjVerb.erase(conjVerb.length() - 1, 1);

    if (subPronoun.compare("ICH") == 0)
        conjVerb.append(1, 'E');
    else if (subPronoun.compare("DU") == 0) {
        if (conjVerb.at(conjVerb.length() - 1) == 'S')
            conjVerb.append(1, 'T');
        else if (conjVerb.at(conjVerb.length() - 1) == 'T' || conjVerb.at(conjVerb.length() - 1) == 'D')
            conjVerb.append("EST");
        else
            conjVerb.append("ST");
    } else if (subPronoun.compare("ER") == 0 || subPronoun.compare("SIE") == 0 || subPronoun.compare("ES") == 0 || subPronoun.compare("IHR") == 0) {
        if (conjVerb.at(conjVerb.length() - 1) == 'T' || conjVerb.at(conjVerb.length() - 1) == 'D')
            conjVerb.append("ET");
        else
            conjVerb.append(1, 'T');
    } else
        if (conjVerb.compare("TU") == 0)
            conjVerb.append(1, 'N');
        else
            conjVerb.append("EN");
}

