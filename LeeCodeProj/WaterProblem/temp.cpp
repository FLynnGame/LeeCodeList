class Shape                     // 形状类
{
public:
	virtual double calcArea()
	{
		return 0;
	}
	virtual ~Shape() {};
};
class Circle : public Shape     // 圆形类
{
public:
	virtual double calcArea(){
		return 0;

	}
};

class Rect : public Shape       // 矩形类
{
public:
	virtual double calcArea() {
		return 0;
	}
};

//int main()
//{
//	Shape* shape0 = new Shape();
//	((Circle*)shape0)->calcArea();
//	Circle * shape1 = new Circle();
//	Shape * shape2 = new Rect();
//	shape1->calcArea();         // 调用圆形类里面的方法
//	((Shape*)shape1)->calcArea();
//	shape2->calcArea();         // 调用矩形类里面的方法
//	delete shape1;
//	shape1 = nullptr;
//	delete shape2;
//	shape2 = nullptr;
//	return 0;
//}