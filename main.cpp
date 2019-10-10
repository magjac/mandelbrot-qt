#include <QApplication>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    const int width = 1024;
    const int height = 512;

    QApplication a(argc, argv);
    QGraphicsScene scene (0, 0, width, height);
    QGraphicsView view(&scene);
    view.show();

    QPixmap pixmap(width, height);
    QPainter p(&pixmap);

    for (int ir = 0; ir < height; ir++)
    {
        for (int ic = 0; ic < width; ic++)
        {
            QColor color (ir % 256, ic % 256, ir % 256);
            p.setPen(color);
            p.drawPoint(ic, ir);
        }
    }
    scene.addPixmap(pixmap);
    return a.exec();
}
