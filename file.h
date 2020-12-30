#ifndef file_h
#define file_h
#include <math.h>
#include "vector.h"
#include "objects.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


class file {
public:
	sphere s1[20];
	cones c1[20];
	polygon p1[20];
	color background, fill_polygon, fill_object;
	Vec3D eye, center_of_plane, up_vector, center_of_sphere[20], base[20], apex[20];
	float hither = 0.0f, radius;
	int angle = 0, nx = 0, ny = 0, i = 0, j = 0, k = 0, p = 0;
	char parse;
	int count = 0;
	string myText;
	void file_read()
	{
		ifstream treeFile("C:/Users/baap1/Desktop/Project1_Graphics/project1/trace/tree-3.nff");
		if (treeFile.is_open())
		{
			while (getline(treeFile, myText))
			{
				istringstream obj(myText);
				obj >> parse;
				switch (parse)
				{
				case 'b':
					float R, G, B;
					obj >> R >> G >> B;
					background = color(R, G, B);
					break;
				case 'v':
					while (i < 6) {
						if (i == 0) {
							getline(treeFile, myText);
							istringstream iss(myText);
							float ex, ey, ez;
							iss.ignore(4, ' ');
							iss >> ex >> ey >> ez;
							eye = Vec3D(ex, ey, ez);
						}
						else if (i == 1) {
							getline(treeFile, myText);
							istringstream iss(myText);
							float cx, cy, cz;
							iss.ignore(4, ' ');
							iss >> cx >> cy >> cz;
							center_of_plane = Vec3D(cx, cy, cz);
						}
						else if (i == 2) {
							getline(treeFile, myText);
							istringstream iss(myText);
							float ux, uy, uz;
							iss.ignore(4, ' ');
							iss >> ux >> uy >> uz;
							up_vector = Vec3D(ux, uy, uz);
						}
						else if (i == 3) {
							getline(treeFile, myText);
							istringstream iss(myText);
							int a;
							iss.ignore(5, ' ');
							iss >> a;
							angle = a;
						}
						else if (i == 4) {
							getline(treeFile, myText);
							istringstream iss(myText);
							float h;
							iss.ignore(6, ' ');
							iss >> h;
							hither = h;
						}
						else {
							getline(treeFile, myText);
							istringstream iss(myText);
							int n1, n2;
							iss.ignore(10, ' ');
							iss >> n1 >> n2;
							nx = n1;
							ny = n2;
						}
						i++;
					}
					break;
				case 'l':
					float x, y, z;
					obj >> x >> y >> z;
					Vec3D(x, y, z);
					break;
				case 'f':
					if (j == 0) {
						float R, G, B;
						obj >> R >> G >> B;
						fill_polygon = color(R, G, B);
					}
					else if (j == 1) {
						float R, G, B;
						obj >> R >> G >> B;
						fill_object = color(R, G, B);
					}
					break;
				case 's':
					float center_x, center_y, center_z, radius_c;
					obj >> center_x >> center_y >> center_z >> radius_c;
					center_of_sphere[k] = Vec3D(center_x, center_y, center_z);
					radius = radius_c;
					s1[k] = sphere(center_of_sphere[k], radius_c);
					k++;
					break;
				case 'p':
					int no_of_vertices;
					obj >> no_of_vertices;
					for (int i = 0; i < no_of_vertices; i++) 
					{
						getline(treeFile, myText);
						istringstream iss(myText);
						float x, y, z;
						iss >> x >> y >> z;
						Vec3D v = Vec3D(x, y, z);
						p1[i] = polygon(v);
					}
					break;
				case 'c':
					float bx, by, bz, br, ax, ay, az, ar;
					obj >> bx >> by >> bz >> br >> ax >> ay >> az >> ar;
					base[p] = Vec3D(bx, by, bz);
					apex[p] = Vec3D(ax, ay, az);
					c1[p] = cones(base[p], br, apex[p], ar);
					p++;
					break;
				default:
					break;
				}
			}
			treeFile.close();
		}
	}
};
#endif

