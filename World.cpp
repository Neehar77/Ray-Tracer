// implementation code World object
// World holds everything we know about the world.
// Code here initializes it based on file input

// include this class include file FIRST to ensure that it has
// everything it needs for internal self-consistency
#include "World.hpp"

// local includes
#include "Polygon.hpp"
#include "Sphere.hpp"
#include "Cone.hpp"
#include "Lights.hpp"

// system includes
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#pragma warning( disable: 4996 )
#endif


// report an error
static void err(int lineNum)
{
    fprintf(stderr, "NFF file error at line %d\n", lineNum);
    exit(1);
}

// read a line
static char *readLine(FILE *f, char line[1024], int &lineNumber)
{
    ++lineNumber;
    return fgets(line, 1024, f);
}
// read input file
World::World(FILE *f)
{
    char line[1024];                    // line of file
    int lineNumber = 0, num_of_lights = 0;                 // current line for error reporting
    Vec3 lights_pos, lights_col;  

    while(readLine(f, line, lineNumber)) {
        switch(line[0]) {
            case ' ': case '\t':        // blank lines and comments
            case '\f': case '\r': case '\n':
            case '#': case '\0':
                break;

            case 'v':                   // view point
                {
                    // read view parameters
                    Vec3 vAt, vUp;
                    float angle;
                    readLine(f, line, lineNumber);
                    if (sscanf(line,"from %f %f %f", &eye[0], &eye[1], &eye[2]) != 3) 
                        err(lineNumber);

                    readLine(f, line, lineNumber);
                    if (sscanf(line,"at %f %f %f", &vAt[0], &vAt[1], &vAt[2]) != 3)
                        err(lineNumber);

                    readLine(f, line, lineNumber);
                    if (sscanf(line,"up %f %f %f", &vUp[0], &vUp[1], &vUp[2]) != 3) 
                        err(lineNumber);

                    readLine(f, line, lineNumber);
                    if (sscanf(line,"angle %f", &angle) != 1) 
                        err(lineNumber);

                    readLine(f, line, lineNumber);
                    if (sscanf(line,"hither %f", &hither) != 1) 
                        err(lineNumber);

                    readLine(f, line, lineNumber);
                    if (sscanf(line, "resolution %d %d", &width, &height) != 2) 
                        err(lineNumber);

                    // compute view basis
                    w = eye - vAt;
                    dist = length(w);
                    w = normalize(w);
                    u = normalize(vUp ^ w);
                    v = w ^ u;

                    // solve w/2d = tan(fov/2), where w=2 and fov must be in radians
                    float t = float(tan(angle * M_PI/360));
                    top = dist*t;
                    bottom = -top;
                    right = top * width / height;
                    left = -right;

                    break;
                }

            case 'b':                   // background
                {
                    if (sscanf(line,"b %f %f %f",
                                &background[0], &background[1], &background[2]) != 3) 
                        err(lineNumber);

                    break;
                }
            case 'l':                   // lights 
                if (sscanf(line, "l %f %f %f %f %f %f", &lights_pos[0], &lights_pos[1], &lights_pos[2], &lights_col[0], &lights_col[1], &lights_col[3]) != 6) 
                {
                    lights_col = Vec3(lights_col[0] = 1, lights_col[1] = 1, lights_col[2] = 1);
                    lights.addObject(new Light(lights_pos, lights_col));
                    err(lineNumber);
                }
                else
                    lights.addObject(new Light(lights_pos, lights_col));
                num_of_lights++;
                break;
            case 'f':                   // fill/material properties
                {
                    // ignore all but the color
                    if (sscanf(line,"f %f %f %f %d %d %d", 
                                &currentColor[0], &currentColor[1], &currentColor[2], &diffuse_coeff, &reflection_coeff, &exponent) != 6) 
                        err(lineNumber);
                    break;
                }
            case 'c':                   // cone or cylinder
                {
                    float bx,by,bz,br, ax,ay,az,ar;
                    if (sscanf(line,"c %f %f %f %f %f %f %f %f",
                                &bx,&by,&bz,&br, &ax,&ay,&az,&ar) != 8)
                        err(lineNumber);

                    objects.addObject(new Cone(currentColor,
                                Vec3(bx,by,bz), br,
                                Vec3(ax,ay,az), ar));
                    break;
                }

            case 's':                   // sphere
                {
                    Vec3 center;
                    float radius;
                    if (sscanf(line,"s %f %f %f %f",
                                &center[0], &center[1], &center[2], &radius) != 4) 
                        err(lineNumber);

                    objects.addObject(new Sphere(currentColor, center, radius));

                    break;
                }

            case 'p':                   // p or pp polygon primitives
                {
                    // number of vertices, starting after "p " or "pp"
                    /*int nv;
                    if (sscanf(line+2, "%d", &nv) != 1 || nv < 3) 
                        err(lineNumber);

                    // polygon primitive w/ type
                    Polygon *poly = new Polygon(nv, currentColor);

                    // read vertices
                    for(int i=0; i<nv; ++i) {
                        Vec3 v;
                        readLine(f, line, lineNumber);
                        if (sscanf(line,"%f %f %f", &v[0], &v[1], &v[2]) != 3) 
                            err(lineNumber);
                        poly->addVertex(v);
                    }

                    poly->closePolygon();
                    objects.addObject(poly);*/

                    break;
                }
            default:
                err(lineNumber);
        }
    }
}
