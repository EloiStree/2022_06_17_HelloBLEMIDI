https://forum.arduino.cc/t/pointers-to-function/58518/4



``` cpp
// Generic arithmetic funtion
typedef int (*GeneralFunction) (const int arg1, const int arg2);

int Add (const int arg1, const int arg2)
{
 return arg1 + arg2; 
} // end of Add

int Subtract (const int arg1, const int arg2)
{
 return arg1 - arg2; 
} // end of Subtract

int Divide (const int arg1, const int arg2)
{
 return arg1 / arg2; 
} // end of Divide

int Multiply (const int arg1, const int arg2)
{
 return arg1 * arg2; 
} // end of Multiply

void setup ()
{
 // make pointers to functions, put them in local variables
  GeneralFunction fAdd = Add;
  GeneralFunction fSubtract = Subtract;
  GeneralFunction fDivide = Divide;
  GeneralFunction fMultiply = Multiply;
  
  Serial.begin (115200);
  Serial.println ();
  
  //  use the function pointers
  Serial.println (fAdd (40, 2));
  Serial.println (fSubtract (40, 2));
  Serial.println (fDivide (40, 2));
  Serial.println (fMultiply (40, 2));
}  // end of setup

void loop () {}


```



``` cpp
int Add (const int arg1, const int arg2)
{
 return arg1 + arg2; 
} // end of Add

int Subtract (const int arg1, const int arg2)
{
 return arg1 - arg2; 
} // end of Subtract

int Divide (const int arg1, const int arg2)
{
 return arg1 / arg2; 
} // end of Divide

int Multiply (const int arg1, const int arg2)
{
 return arg1 * arg2; 
} // end of Multiply

int DoSomething (int (*f) (const int arg1, const int arg2), const int a, const int b)
{
 Serial.println (f (a, b));   // call the passed-in function
}

void setup ()
{
  Serial.begin (115200);
  Serial.println ();

  DoSomething (Add, 40, 2);
  DoSomething (Subtract, 40, 2);
  DoSomething (Divide, 40, 2);
  DoSomething (Multiply, 40, 2);
}  // end of setup

void loop () {}
```


``` cpp
// Generic arithmetic function
typedef int (*GeneralFunction) (const int arg1, const int arg2);

int Add (const int arg1, const int arg2)
{
 return arg1 + arg2; 
} // end of Add

int Subtract (const int arg1, const int arg2)
{
 return arg1 - arg2; 
} // end of Subtract

int Divide (const int arg1, const int arg2)
{
 return arg1 / arg2; 
} // end of Divide

int Multiply (const int arg1, const int arg2)
{
 return arg1 * arg2; 
} // end of Multiply

int DoSomething (GeneralFunction f, const int arg1, const int arg2)
{
 Serial.println ((*f) (arg1, arg2));    // call the passed-in function
}

void setup ()
{
  Serial.begin (115200);
  Serial.println ();

  DoSomething (Add, 40, 2);
  DoSomething (Subtract, 40, 2);
  DoSomething (Divide, 40, 2);
  DoSomething (Multiply, 40, 2);
}  // end of setup

void loop () {}

```
