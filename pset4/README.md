# Image Recognition in C

Using file I/O in C to uncover patters in an image, resize images, and recover lost images

## Whodunit
Find who did the crime by uncovering hidden text in the Image.

Removed all red and green colors from the BMP image to reveal the name.

<p float="left">
  <img src="/clue.bmp" width="100" />
  <img src="/result.bmp" width="100" /> 
</p>

## Resize

Resized a BMP image by a multiplier that is greater than 1.

<p float="left">
  <img src="/small.bmp" width="50" />
  <img src="/larger.bmp" width="100" /> 
</p>

## Recover

Recovered jpeg images from a memory card by parsing through the file 512 bytes at a time, looking
for a jpeg image identifier, and saving it to a jpeg image.