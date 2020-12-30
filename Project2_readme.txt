I have added LightList and Light files to the code. LightList collects all the lights as an object from the file. 
Moreover I have added calculations for surface normals to the sphere and cones for every intersecting point. So for every intersection of ray with the object,
it will trace a reflected ray from the intersecting point as the start and light to the point as its direction.
There is a Method in light list namely: ray_color which return color at the end after calculating for diffsuion, specular and reflection.


references:
https://graphicscompendium.com/raytracing/06-lighting
https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/ligth-and-shadows
https://www.scratchapixel.com/code.php?id=3&origin=/lessons/3d-basic-rendering/introduction-to-ray-tracing