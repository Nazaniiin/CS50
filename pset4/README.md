# Image Recognition in C

Using file I/O in C to uncover patters in an image, resize images, and recover lost images

## Whodunit
Find who did the crime by uncovering hidden text in the Image.

Removed all red and green colors from the BMP image to reveal the name.

<p float="left" align="center">
  <img src="whodunit/clue.bmp" width="300" />
  <img src="whodunit/verdict.bmp" width="300" /> 
</p>

## Resize

Resized a BMP image by a multiplier that is greater than 1.

<p float="left" align="center">
  <img src="resize/more/small.bmp" width="50" />
  <img src="resize/more/larger.bmp" width="300" /> 
</p>

## Recover

Recovered jpeg images from a memory card by parsing through the file 512 bytes at a time, looking
for a jpeg image identifier, and saving it to a jpeg image.
