make
rm data.txt
cp artprevo.filler test/players
cd test
./filler_vm -f maps/map02 -p1 players/artprevo.filler -p2 players/superjeannot.filler
