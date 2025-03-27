#include <stdio.h>
#include <math.h>

int main()
{
    // Define the inputs as a 2D array (matrix)
    float inputs[3][4] = {
        {1.0, -2.0, 0.0, -1.0},  // input1
        {0.0, 1.5, -0.5, -1.0},  // input2
        {-1.0, 1.0, 0.5, -1.0}   // input3
    };
    
    float weights[] = {1.0, -1.0, 0.0, 0.5};

    float l = 1.0;
    float c = 0.1;

    // Store targets in an array for easy access
    float targets[3] = {-1.0, -1.0, 1.0};

    // Iterate over each input
    for (int iteration = 0; iteration < 3; iteration++) {
        float net = 0.0;

        // Calculate net input for the current iteration
        for (int i = 0; i < 4; i++) {
            net += inputs[iteration][i] * weights[i];
        }
        printf("\nnet for input%d = %f", iteration + 1, net);

        //calculataion of f(net) 
        float o = (1 - exp(-l * net))/(1 + exp(-l * net));
        printf("\nf(net) for input%d = o%d = %f", iteration + 1,iteration + 1, net);

        //deriavtive of f(net)
        float der = 0.5 * (1.0 - (o*o));
        printf("\nderivative(f(net)) for input%d = %f",iteration + 1, net);

        // Update weights according to the perceptron learning rule
        for (int i = 0; i < 4; i++) {
            weights[i] += c * (targets[iteration] - o) * der * inputs[iteration][i];
        }

        // Print updated weights
        printf("\nw%d = [ ", iteration + 1);
        for (int i = 0; i < 4; i++) {
            printf("%f ", weights[i]);
        }
        printf("]");
        printf("\n");
    }

    return 0;
}