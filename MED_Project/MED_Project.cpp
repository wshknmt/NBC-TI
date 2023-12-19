#include "NBC.h"

int main() {
    NBC nbc("data/my_dataset.txt", 3);
    nbc.getPoints();
    nbc.printMaxLabel();
}
