#include "Ray.hpp"
#include "Lights.hpp"
#include "ObjectList.hpp"
#include "Object.hpp"
#include "World.hpp"
#include "LightList.hpp"

class ObjectList;
class Object;
class World;

LightList::~LightList()
{
	for (l_list::iterator i = light_list.begin(); i != light_list.end(); ++i) 
	{
		delete* i;
	}
}

const Vec3 LightList::ray_color(Ray &ray, World &w)
{
	float snear = 0, sfar = INFINITY;        //new t
	int diffuse = 0;
	int specular = 0;

    Vec3 light_to_point1;       // no object, t = infinity
        for (l_list::iterator i = light_list.begin(); i != light_list.end(); ++i) {
			Light *l1 = (*i);
			bool shadow = false;
			Vec3 point = ray.point_at_object();
			light_to_point1 = l1->position - point;
			int dist2 = length(light_to_point1);
			light_to_point1 = normalize(light_to_point1);
			Ray reflectionray(point, light_to_point1, w.hither/dist2);
			Intersection i1 = w.objects.trace(reflectionray);
			if (i1.t == INFINITY) 
			{
				return w.background;
			}
			else
			{
				if (i1.t < length(light_to_point1)) 
				{
					shadow = true;
					return Vec3();
				}
				else 
				{
					Vec3 h = normalize(w.ray_direction + light_to_point1);
					diffuse = diffuse + dot(w.normal, light_to_point1);
					int temp = dot(w.normal, h);
					specular = specular + pow(temp, w.exponent);
					Vec3 color = w.objects.trace(reflectionray).color(w);
					color[0] = color[0] + (w.diffuse_coeff * w.current_color[0] + w.reflection_coeff * specular)* diffuse * 1 / sqrt(light_list.size());
					color[1] = color[1] + (w.diffuse_coeff * w.current_color[1] + w.reflection_coeff * specular) * diffuse * 1 / sqrt(light_list.size());
					color[2] = color[2] + (w.diffuse_coeff * w.current_color[2] + w.reflection_coeff * specular) * diffuse * 1 / sqrt(light_list.size());
					for (int i = 0; i < w.recursion_limit; i++)
					{
						if (w.reflection_coeff > 0) 
						{
							w.total_color = w.total_color + w.reflection_coeff * w.objects.trace(reflectionray).color(w);
							return w.total_color;
						}
						else
						{
							w.total_color = color;
							return color;
						}
					}
				}
			}
        }
}
