# OpenGL
OpenGL programs done in lab

### 1. Draw red color ellipse
![IMG](http://i67.tinypic.com/k1qah2.png)

### 2. Move circle around a line
Circle moves clockwise around a line using right arrow. Logic is simple, at the endpoints of line the velocity direction gets reversed, the y-axis position is also changed by 2 * Radius. 
![Alt Text](https://thumbs.gfycat.com/ImaginaryOrdinaryHorseshoecrab-size_restricted.gif)

### 3. Move circle with arrow keys
![Imgur](https://i.imgur.com/kel6jYm.png)

### 4. Zoom in/ out of a circle
I used glScalef function to scale the image
!![Alt Text](https://thumbs.gfycat.com/DeliriousNeglectedGoldenmantledgroundsquirrel-size_restricted.gif)

### 5. Dashed line in 3 different colors
We have to enable stippled lines

![Imgur](https://i.imgur.com/gb94TKA.png)

### 6. Draw free hand line using mouse
I simply store all the points while the LMB is pressed and clear the screen when RMB is pressed. I use small connected line segments (GL_LINE_STRIP) to draw the curves

![Imgur](https://i.imgur.com/JMJq6rT.png)
