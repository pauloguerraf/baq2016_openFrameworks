# Quito Architecture Biennial / Final Implementation / 2016

Final implementation of the software behind the submissions gallery of the 2016 Quito Biennial. The first prototype can be found here [baq2016 - Processing version](https://github.com/pauloguerraf/baq2016_Processing)

The final verrsion of this project is meant to run on a Raspberry Pi using openFrameworks. The interface controls projection mapped digital posters through OSC messages. The Biennnial visitors were able to navigate through posters of the submmitted works using a wireless rotary interface. 

The project consists of an image gallery that looks for images within a data folder. The image selected by a visitor is projected as a quad texture. Each of the 4 points of the projected texture can be tranlasted in order to achieve the right projection perspective on a flat projection surface. The user can navigate through the image gallery using a knob connected to a [Particle Photon](https://docs.particle.io/photon/) that sends the current knob position via OSC messages to the server controlling the projection. 

![BAQ2016](https://github.com/pauloguerraf/baq2016_Processing/blob/master/baq2016.jpg "BAQ2016")

![BAQ2016](https://github.com/pauloguerraf/baq2016_Processing/blob/master/baq2016_2.jpg "BAQ2016")
