#include "textOutputter.h"

string TextOutputter::makeGibberish(string text) {
    for(auto & i : text) {
        i += 1;
    }
    return text;
}
