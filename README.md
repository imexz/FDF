# FDF
This project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.
Its goal is to give an introduction to graphics programming using the MiniLibX library.

## Usage
- Run `make` in the root of the repository.
- Run ` ./fdf <.fdf file> `.
- Press ESC or click cross on window's frame to exit the program.
- Additional features (press key):
  - Switch projection: I (isometric), P (parallel)
  - Zoom: - , +
  - Translate model: ArrowUp, ArrowDown, ArrowLeft, ArrowRight
  - Rotate model: NUMPAD2, NUMPAD8, NUMPAD4, NUMPAD6, NUMPAD1, NUMPAD9
  - Adjust altitude: < , >

### Characteristics of .fdf files
- Contain numbers which represent a point in space.
- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.

Example for a .fdf file:

<img width="364" alt="Screenshot 2022-12-16 at 17 55 28" src="https://user-images.githubusercontent.com/82594855/208149336-a7dd943d-4d8d-4e65-bcb0-8de5bb04e190.png">

Example for how the 42.fdf file renderes:

<img width="501" alt="Screenshot 2022-12-16 at 17 56 52" src="https://user-images.githubusercontent.com/82594855/208149633-0f5cfb1d-5489-451c-9920-3284ecd1da9d.png">
