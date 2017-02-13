#pragma once

struct point{
    int x,y;
};

bool operator==(const point&,const point&);
bool operator<(const point&,const point&);

