#include <vector>
#include <cstdlib>

using namespace std;

class Perceptron{
private:
    vector<double> weights;
    double bias;
    double threshold;
    double learnc;

public:

    Perceptron(int no, double learningRate = 0.00001): learnc(learningRate), bias(1.0){
        weights.resize(no + 1);
        for(int i = 0;i<=no;i++){
            weights[i] = static_cast<double>(rand()) /RAND_MAX * 2.0 -1.0;
        }
    }

    int activate(const vector<double>& inputs){
        double sum = 0.0;
        for(size_t i = 0; i< inputs.size(); i++){
            sum += weights[i] * inputs[i];
        }
        return (sum > this->threshold) ? 1 : 0;
    
    }


    void train(vector<double> inputs, int desired){
        inputs.push_back(bias);
        int guess = activate(inputs);
        int error = desired - guess;
        if(error != 0){
            for(size_t i = 0; i < inputs.size(); i++){
                weights[i] += this->learnc * error * inputs[i];
            }
        }

    }

};