****K-Nearest Neighbors (KNN) in C****

This project implements the K-Nearest Neighbors (KNN) algorithm in C for classification tasks. The KNN algorithm is a simple, yet powerful machine learning technique used to classify data points based on their proximity to labeled training data.

Features

Implementation of KNN algorithm: Classifies input data based on the majority class of its nearest neighbors.
Customizable parameters: None, user simply runs the KNN.c file which trains to fins the optimal value of K from the data

Training: The training data consists of an array of 1 for rises in the market from the previous day and 0 for a fall from the previous day.

Classification: To classify a new input, the algorithm calculates the K nearest neighbors from the recent day to predict the new input  (tomorrow).

A C compiler (e.g., GCC)
No external libraries are required.
Usage

Clone the repository:
git clone https://github.com/Johnmllr-design/KNNinC.git
cd KNNinC


**Instructions**
run the getData.py file to access the yFinance API that will provide KNN with data
compile and run KNN.c via clang -o KNN KNN.c and ./KNN to see how it thins tomorrowe will behave

running the program will train based on the data and then view the current optimized k nearest neighbors to make it's inference.


Contributing

Feel free to fork the repository and submit pull requests for any improvements or bug fixes, or email me with any additional questions millerjo2@grinnell.edu

