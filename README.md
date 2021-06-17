# Conway Game Of Life
  The "Game of Life", also known simply as "Life". Devised by John Horton Conway back in 1970.
  
  Here is the screenshot of what I have done: <br/>
  <img src="https://raw.githubusercontent.com/Lackym/conway-game-of-life/master/game-of-life.png" alt="drawing" width="450"/>

# Rules

  The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, live or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

1) Any live cell with fewer than two live neighbours dies, as if by underpopulation.
2) Any live cell with two or three live neighbours lives on to the next generation.
3) Any live cell with more than three live neighbours dies, as if by overpopulation.
4) Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

These rules, which compare the behavior of the automaton to real life, can be condensed into the following:

1) Any live cell with two or three live neighbours survives.
2) Any dead cell with three live neighbours becomes a live cell.
3) All other live cells die in the next generation. Similarly, all other dead cells stay dead.

  The initial pattern constitutes the seed of the system. The first generation is created by applying the above rules simultaneously to every cell in the seed, live or dead; births and deaths occur simultaneously, and the discrete moment at which this happens is sometimes called a tick. Each generation is a pure function of the preceding one. The rules continue to be applied repeatedly to create further generations.

Visit [this wikipedia page](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) for more information about "Game of Life".
