make
rm data.txt
cp artprevo.filler test/players
cd test
./filler_vm -f maps/map00 -p1 players/artprevo.filler -p2 players/artprevo.filler
