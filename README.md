# mandelbrot-qt
Zooming into the Mandelbrot set using Qt and C++

A simple desktop application that draws the Mandelbot set and zooms into a predefined point. This is just a quick hack to learn Qt. There are much better Mandelbrot programs out threre.

## Build and run from Qt Creator
* Install [Qt](https://www.qt.io/download).
* Start qtcreator
* Accept default configuration
* Build -> Build All
* Build -> Run

## Build and run from shell
* cd ../build-mandelbrot-Desktop-Debug
* make
./mandelbrot

## Change size, speed and precision
* The size of the graph can be changed [here](https://github.com/magjac/mandelbrot-qt/blob/fe0655939df9bd09f4397887cbfd9c5476f3fdf1/main.cpp#L11). Smaller is faster.
* The precision of the graph can be changed [here](https://github.com/magjac/mandelbrot-qt/blob/fe0655939df9bd09f4397887cbfd9c5476f3fdf1/main.cpp#L30). Lower precision is faster, but gives bad resolution for deep zooms.

The default values are small and slow, but gives a lot of detail in the deep zooms
