class Shape                     // ��״��
{
public:
	virtual double calcArea()
	{
		return 0;
	}
	virtual ~Shape() {};
};
class Circle : public Shape     // Բ����
{
public:
	virtual double calcArea(){
		return 0;

	}
};

class Rect : public Shape       // ������
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
//	shape1->calcArea();         // ����Բ��������ķ���
//	((Shape*)shape1)->calcArea();
//	shape2->calcArea();         // ���þ���������ķ���
//	delete shape1;
//	shape1 = nullptr;
//	delete shape2;
//	shape2 = nullptr;
//	return 0;
//}