#include <stdio.h>

int main()
{

    float input1[] = {1.0, -2.0, 0.0, -1.0};
    float input2[] = {0.0, 1.5, -0.5, -1.0};
    float input3[] = {-1.0, 1.0, 0.5, -1.0};
    float weights[] = {1.0, -1.0, 0.0, 0.5};

    float c = 0.1;
    float d1=-1, d2=-1, d3=1;

    //first iteration
    float net = 0.0;

    for(int i=0; i<4; i++) {
        net = (input1[i]*weights[i]) + net;
        
    }
    printf("net = %f\n", net);

    float sgn = net>0 ? 1.0:-1.0;
    for(int i=0; i<4; i++) {
            weights[i] = weights[i] + c*(d1-sgn)*input1[i];
        }

    printf("w1 = [ ");
    for(int i=0; i<4; i++) {
        printf("%f ", weights[i]);
    }
    printf("]");

    //second iteration
    net = 0.0;

    for(int i=0; i<4; i++) {
        net = (input2[i]*weights[i]) + net;
    }
    printf("\n\nnet = %f", net);

    sgn = net>0 ? 1.0:-1.0;
    for(int i=0; i<4; i++) {
            weights[i] = weights[i] + c*(d2-sgn)*input2[i];
        }

    printf("\nw2 = [ ");
    for(int i=0; i<4; i++) {
        printf("%f ", weights[i]);
    }
    printf("]");

    //third iteration
    net = 0.0;

    for(int i=0; i<4; i++) {
        net = (input3[i]*weights[i]) + net;
    }
    printf("\n\nnet = %f", net);

    sgn = net>0 ? 1.0:-1.0;
    for(int i=0; i<4; i++) {
            weights[i] = weights[i] + c*(d3-sgn)*input3[i];
        }

    printf("\nw3 = [ ");
    for(int i=0; i<4; i++) {
        printf("%f ", weights[i]);
    }
    printf("]");


    return 0;
}



// #include <stdio.h>

// int main()
// {
//     // Define the inputs as a 2D array (matrix)
//     float inputs[3][4] = {
//         {1.0, -2.0, 0.0, -1.0},  // input1
//         {0.0, 1.5, -0.5, -1.0},  // input2
//         {-1.0, 1.0, 0.5, -1.0}   // input3
//     };
    
//     float weights[] = {1.0, -1.0, 0.0, 0.5};

//     float c = 0.1;
//     float d1 = -1, d2 = -1, d3 = 1;

//     // Store targets in an array for easy access
//     float targets[3] = {d1, d2, d3};

//     // Iterate over each input
//     for (int iteration = 0; iteration < 3; iteration++) {
//         float net = 0.0;

//         // Calculate net input for the current iteration
//         for (int i = 0; i < 4; i++) {
//             net += inputs[iteration][i] * weights[i];
//         }
//         printf("\nnet for input%d = %f", iteration + 1, net);

//         // Determine the sign
//         float sgn = net > 0 ? 1.0 : -1.0;

//         // Update weights according to the perceptron learning rule
//         for (int i = 0; i < 4; i++) {
//             weights[i] += c * (targets[iteration] - sgn) * inputs[iteration][i];
//         }

//         // Print updated weights
//         printf("\nw%d = [ ", iteration + 1);
//         for (int i = 0; i < 4; i++) {
//             printf("%f ", weights[i]);
//         }
//         printf("]");
//     }

//     return 0;
// }