#!/bin/bash

rm frac fracScene
make -f makeFrac
make -f fracScene
make -f makeAnim
# frac <n> <D> <s> <sigma>
#./frac  2  2.2 15   20

#turn in
#./frac  8  2.2  5   11 | ./fracScene | ./rd_view -
./frac  8  2.2  5   11 | ./fracScene > starryNight.rd
#./frac 8 2.2 5 11 | ./fracAnim > starryAnim.rd
./rd_view starryNight.rd