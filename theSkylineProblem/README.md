
<pre>

  ^
  |
  |      (h2)
  |      +---------+
  |      |         |
  |  +---+-+(h1)   | 
  |  |   | |       |
  |  |   | |       |
  |  |   | |       |
  |  |   | |       |
--+--+---+-+-------+-------------------->
  |  x1    x1'
  |     x2        x2'


</pre>

Rectangles = List structure
[left,right, x1, x1', h1, x2, x2', h2]
[...]

if the left position of building(x1) is exist in the rangle of rectangles (rectangle[0]), 
then 
    1. Enlarge the range, x and x' , of rectangle[0]
    2. Check the height(h) if it is in the consective horizontal line of rectangle[0].
       if yes, skip
       if not, add the new height into rectangle[0]
       then find the left outline point through all rectangle[0]
        remove right point if the next point cover the last 
else

  Add a new range into rectangle, such as rectangle[1].


At the end, return the points


Example:
* add (x1, x1', h1);
  Create rectangle[0] = {x1, x1', (h1)},
* add (x2, x2', h2)
  Enlarge the range: rectangle[0] = {x1, x2', (h1)}
  is not a consective horizontal line,  rectangle[0] = {x1, x2', (h1, h2)}


<pre>

  ^
  |
  |      (h2)
  |      +---------+
  |               
  |  +---+xx(h1)    
  |                  -------
  |  
  |                       xx-----------
  |  
--+--+---+-+-------+-------------------->
  |  x1    x1'
  |     x2        x2'


</pre>

