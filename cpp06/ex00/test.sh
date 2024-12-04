!#bin/sh

echo "Starting test"

# Run the test

# int test
int_ary=("42", "-42", "0", "2147483647", "-2147483648", "2147483648", "-2147483649")

for i in ${int_ary[@]} ; do
	echo "-------Testing $i-------"
	./a.out $i
done


# char test
char_ary=(a, b, c)

# float test
float_ary=(3.14, -3.14, 0.0, 0.0f, -3.14f, inff, -inff, nanf)
float1="3.14"
float2="-3.14"
float3="0.0"
float4="0.0f"
float5="-3.14f"
float6="inff"
float7="-inff"
float8="nanf"

# double test
double1="3.14"
double2="-3.14"
double3="0.0"
double4="0.0f"
double5="-3.14f"
double6="inf"
double7="-inf"
double8="nan"

# error test
error1="3.14.3"
error2=""
error3="hello"
error4="3.14fff"


