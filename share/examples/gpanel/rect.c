/*
 * Draw random rectangles.
 */
#include <stdio.h>
#include <sys/gpanel.h>

int xsize, ysize;

int main()
{
    char *devname = "/dev/tft0";
    int x0, y0, x1, y1, color;

    if (gpanel_open(devname) < 0) {
        printf("Cannot open %s\n", devname);
        exit(-1);
    }
    gpanel_clear(0, &xsize, &ysize);
    printf("Screen size %u x %u.\n", xsize, ysize);

    srand(time(0));
    printf("Draw random rectangles.\n");
    printf("Press ^C to stop.\n");

    for (;;) {
        x0 = rand() % xsize;
        y0 = rand() % ysize;
        x1 = rand() % xsize;
        y1 = rand() % ysize;
        color = rand() << 1;
        gpanel_rect(color, x0, y0, x1, y1);
    }
    return 0;
}
