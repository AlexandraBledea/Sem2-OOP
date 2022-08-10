# TableSweepers!
Create a collaborative implementation of the classical [Minesweeper game](https://www.google.com/search?q=play+minesweeper)! You have to implement the following functionalities:
1. The program reads the size of the playing field, number of mines and player information from an input file. The included `input.txt` file specifies a playing field of `8 x 8` (the playing area is always square in shape), a number of `10` mines and four players, named `Alice`, `Bob`, `Carol` and `Darryl`. The input file is presumed correct. The mines are laid out randomly within the playing field.
2. **[2p]** The program creates a new window for each player, having the player's name in its title. Each window includes the following elements:
* A [QTableView](https://doc.qt.io/qt-5/qtableview.html) with a custom model where the minefield is represented. The table will include a header that allows identifying each row/column, like in the photo below. Table cells have a square shape. When starting the game, all cells are unrevealed and have a light green background.
* A component that allows the user to enter a new coordinate (e.g. such as a [QLineEdit](https://doc.qt.io/qt-5/qlineedit.html))
* Two buttons, one labelled `Reveal` and the other `Mark Mine`.
3. **[2p]** On their turn, each player enters a coordinate into their window's input field (e.g. `B4`) and presses one of the buttons. 
* Pressing `Mark Mine` marks the corresponding table cell as a mine by placing an `*` into the corresponding cell and changing its background to red.
* Pressing `Reveal` on a cell that contains a mine defeats the player; they receive a defeat message through a [QMessageBox](https://doc.qt.io/qt-5/qmessagebox.html) and are eliminated from the game (either close their window or disable all controls). The game continues for the remaining players.
* Pressing `Reveal` on a cell that does not contain a mine reveals it by changing its background to light blue and showing the number of mines adjacent to it (on row, column or diagonal).  
* Pressing a button while an invalid coordinate is filled in (outside of playing area, already revealed cell, or marking a revealed cell as a mine) results in an error message.
4. **[2p]** Cells marked or revealed by one player are immediately updated across all player windows. 
5. **[2p]** Players take turns one at a time, in the order given in the input file. This is implemented by disabling the buttons within the windows of the players who are out of turn. 
6. **[1p]** The game ends when all players have been defeated or when all mines were correctly marked.

### default 1p.

## Observations
- The picture below shows the status of the board, represented in the form of a table during a game. Cells containing mines are represented with `*` to help you understand the layout; during an actual round, only cells marked as mines should be represented with `*`.
- Cells with green background are unrevealed
- Cells with blue background are revealed, and contain the number of adjacent mines. 

<img width="488" alt="mines" src="https://user-images.githubusercontent.com/25611695/124588379-64d7f280-de61-11eb-887c-c4b68992f1a3.png">
