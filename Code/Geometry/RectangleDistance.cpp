int rect_distance(int x1, int  y1, int  x1b, int  y1b, int x2, int  y2, int  x2b, int y2b){
	bool left = x2b < x1,
		 right = x1b < x2,
		 bottom = y2b < y1,
		 top = y1b < y2;
    
    if (top && left) return dist(x1, y1b, x2b, y2);
    if (left && bottom) return dist(x1, y1, x2b, y2b);
    if (bottom  &&  right) return dist(x1b, y1, x2, y2b);
    if (right  &&  top) return dist(x1b, y1b, x2, y2);
    if (left) return x1 - x2b;
    if (right) return x2 - x1b;
    if (bottom) return y1 - y2b;
    if (top) return y2 - y1b;
	return 0; // rectangles intersect
}

int dist(int x1, int y1, int x2, int y2){//Manhatam Distance
	return abs(x1-x2) + abs(y1-y2);
}