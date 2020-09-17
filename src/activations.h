class Activation
{
public:
    static double relu(double x);
    static double softmax(double x);
    static double tanh(double x);
	static double linear(double x);
    static double relu_derative(double x);
    static double softmax_derative(double x);
    static double tanh_derative(double x);
	static double linear_derative(double x);
};
