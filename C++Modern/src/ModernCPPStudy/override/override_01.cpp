
class Base
{
	virtual void funcA();
	virtual void funcB() const;
	virtual void funcC( int = 0 );
	void funcD();
	virtual int funcE();
	virtual void funcF();
};

class DerivedA : public Base
{
	virtual void funcA(); // ok, works as intended  

	virtual void funcB(); // DerivedClass::funcB() is non-const, so it does not  
						  // override BaseClass::funcB() const and it is a new member function  

	virtual void funcC( double = 0.0 ); // DerivedClass::funcC(double) has a different  
										// parameter type than BaseClass::funcC(int), so  
										// DerivedClass::funcC(double) is a new member function 
};


class DerivedB: public Base
{
	virtual void funcA() override; // ok. Base::funcA() 오버라이딩 한다  

	virtual void funcB() override; // compiler error: DerivedClass::funcB() does not   
								   // override BaseClass::funcB() const  

	virtual void funcC( double = 0.0 ) override; // compiler error:   
												 // DerivedClass::funcC(double) does not   
												 // override BaseClass::funcC(int)  

	void funcD() override; // compiler error: DerivedClass::funcD() does not   
						   // override the non-virtual BaseClass::funcD()  

	virtual void funcE() override;	// compiler error: return type 이 일치하지 않는다.
public:
	virtual void funcF() override;	// ok. access level 은 고려되지 않는다
};