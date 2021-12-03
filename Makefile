PROGRAMS=day1 day2 day3 day4 day5 day6 day7 day8 day9 day10 day11 day12 day13 day14 day15 day16 day17 day18 day19 day20 day21 day22 day23 day24 day25
PROGRAMSPT2=day1pt2 day2pt2 day3pt2 day4pt2 day5pt2 day6pt2 day7pt2 day8pt2 day9pt2 day10pt2 day11pt2 day12pt2 day13pt2 day14pt2 day15pt2 day16pt2 day17pt2 day18pt2 day19pt2 day20pt2 day21pt2 day22pt2 day23pt2 day24pt2 day25pt2

%: %.cpp
		g++ $^ -o $@

clean:
		rm -rf *.o $(PROGRAMS) $(PROGRAMSPT2) .vscode/*~ *~
