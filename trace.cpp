// ray tracer main program
// includes input file parsing and spawning screen pixel rays

// classes used directly by this file
#include "ObjectList.hpp"
#include "Polygon.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"
#include "World.hpp"
#include "Vec3.hpp"
#include "LightList.hpp"
#include "Object.hpp"
// standard includes
#include <stdio.h>
#include <string.h>
#include <list>

#ifdef _WIN32
// don't complain about MS-deprecated standard C functions
#pragma warning( disable: 4996 )
#endif

int main(int argc, char **argv)
{
    // input file from command line or stdin
    FILE *infile;
    if (argc <= 1)
        infile = stdin;
    else {
        infile = fopen(argv[1], "r");
        if (!infile) {
            fprintf(stderr, "error opening %s\n", argv[1]);
            return 1;
        }
    }

    // everything we know about the world
    // image parameters, camera parameters
    World world(infile);
    // True color
    Vec3 total_color;
    // array of image data in ppm-file order
    unsigned char (*pixels)[3] = new unsigned char[world.height * world.width][3];
    //Recursion limit
    int recursion_limit = 5;
    // spawn a ray for each pixel and place the result in the pixel
    for(int j=0; j<world.height; ++j) {

        if (j % 32 == 0) {
        } // show current line
        for(int i=0; i<world.width; ++i) {

            // trace new ray
            float us = world.left + 
                (world.right - world.left) * (i+0.5f)/world.width;
            float vs = world.top + 
                (world.bottom - world.top) * (j+0.5f)/world.height;
            world.ray_direction = -world.dist * world.w + us * world.u + vs * world.v;
            world.ray_direction = normalize(world.ray_direction);
            Ray ray(world.eye, world.ray_direction, world.hither / world.dist);
            Intersection obj = Intersection(world.objects.trace(ray));
            //const Object *obj1 = obj.d_obj;
            //world.normal = world.objects.trace(ray).normal(ray, obj1);
            world.point = ray.point_at_object();
            Vec3 local_color = world.lights.ray_color(ray, world);
            //Vec3 col = world.objects.trace(ray).color(world);
           
            // assign color
            pixels[j*world.width + i][0] = local_color.r();
            pixels[j*world.width + i][1] = local_color.g();
            pixels[j*world.width + i][2] = local_color.b();
        }
    }
    
    printf("done\n");

    // write ppm file of pixels
    FILE *output = fopen("balls.ppm","wb");
    fprintf(output, "P6\n%d %d\n255\n", world.width, world.height);
    fwrite(pixels, world.height * world.width*3, 1, output);
    fclose(output);

    delete[] pixels;
    return 0;
}

