make
rm data.txt
cp artprevo.filler test/players
cd test
./filler_vm -f maps/map02 -p2 players/carli.filler -p1 players/artprevo.filler
