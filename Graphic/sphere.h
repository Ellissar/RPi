#ifndef __SPHERE_H
#define __SPHERE_H

#include <vector>
#include "basic.h"
#include "object.h"
#include "circle.h"

class sphere: public object
{
public:
	inline sphere(class object *parent = 0, const class point p = point(), const float r = 0, const uint32_t c = 0);
	inline void set(const class point p = point(), const float r = 0, const uint32_t c = 0);
	inline void setColour(const uint32_t c = 0);

private:
	float radius;
	std::vector<class circle *> circles;
};

inline sphere::sphere(class object *parent, const class point p, const float r, const uint32_t c): object(parent)
{
	set(p, r, c);
}

inline void sphere::set(const class point p, const float r, const uint32_t c)
{
	radius = r;
	colour = c;
	setTPoint(p);
	float d = PI / 12;	//1 / r;
	for (float i = 0; i < PI; i += d)
		circles.push_back(new circle(this, point(), angle(0, i, 0), r, c));
}

inline void sphere::setColour(const uint32_t c)
{
	for (std::vector<class circle *>::size_type i = 0; i != circles.size(); i++)
		circles[i]->setColour(c);
}

#endif
