# FDF
The first project in the Graphics Branch of the curriculum, this project requires us to read in a file containing point values and render them on screen in a wireframe, connecting adjacent points.
####Requirements:
- does not error (no double free, segfault, or unexpected termination)
- displays a wireframe of the points
- listens in the window to terminate when "esc" is pressed

#### Bonus:
- Colors, color gradients
- be able to move and/or rotate the wireframe and/or view
- be able to read in custom colors from the input file

For my project, I am to go above and beyond by rendering not one, but three windows that share the same world space. Each window will spawn at a different location and orientation. This will provide three different views of the same grid. Each will be able to move and rotate the grid, which will be reflected in the views of the other windows. 
Not only will colors be present, but smooth color gradients will be drawn between points. Points will be given color values based on their altitude. 
