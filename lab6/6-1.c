#include <stdio.h>
#include <math.h>

int main(void)
{
	// 구조체 point 정의
	struct point {
		int x;
		int y;
	};
	
	// point로 정의된 pt1과 pt2에 x, y값 부여
	struct point pt1 = { 10, 20 };
	struct point pt2 = { 30, 40 };
	
	// 거리와 넓이 변수 정의
	double distance;
	double rectangle;
	
	// 거리와 넓이 공식 적용
	distance = sqrt((pt2.x - pt1.x)*(pt2.x-pt1.x) + (pt2.y - pt1.y)*(pt2.y - pt1.y));
	rectangle = fabs(pt2.x-pt1.x) *fabs(pt2.y-pt1.y);
	
	//출력
	printf("두 point 간의 거리 : %lf ", distance);
	putchar('\n');
	printf("사각형의 넓이 : %lf ", rectangle);
	putchar('\n');

	return 0;
}
