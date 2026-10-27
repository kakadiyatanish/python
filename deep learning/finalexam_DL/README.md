# Deep Learning Practical Exam – Set A

## Overview

This project contains a Jupyter Notebook (`DLsetA.ipynb`) covering several deep learning practical tasks. It demonstrates data preparation, model building, training, evaluation, visualization, and saving trained models.

## Tasks Included

1. **Artificial Neural Network (ANN) – Diabetes Prediction**
   - Load and prepare the diabetes dataset.
   - Build and train an ANN.
   - Evaluate model performance.
   - Save the trained model as `ann_diabetes_model.h5`.

2. **Image Preprocessing**
   - Load five sample images from CIFAR-10.
   - Apply image preprocessing operations.
   - Display the processed images in a 5 × 5 grid.

3. **Convolutional Neural Network (CNN) – CIFAR-10**
   - Prepare the CIFAR-10 image dataset.
   - Build, train, and evaluate a CNN.
   - Save the trained model.

4. **Recurrent Neural Network (RNN) – Airline Passenger Prediction**
   - Prepare monthly airline passenger time-series data.
   - Build and train an RNN.
   - Evaluate predictions and visualize results.
   - Save the trained model.

5. **Transformer – Movie Review Sentiment Analysis**
   - Set up a sentiment-analysis pipeline.
   - Run inference on 25 review sentences.
   - Review predicted sentiment labels and confidence scores.
   - Plot confidence results.

6. **Results and Reflection**
   - Summarize model results.
   - Write a reflection on the practical work.
   - Review the GitHub submission checklist and report starter.

## Requirements

The notebook uses Python and may require the following packages:

- TensorFlow
- OpenCV (`opencv-python`)
- Transformers
- pandas
- NumPy
- Matplotlib
- scikit-learn

Install the dependencies in your Python environment:

```bash
pip install tensorflow opencv-python transformers pandas numpy matplotlib scikit-learn
```

Depending on your Python version and operating system, TensorFlow may require a compatible Python version.

## How to Run

1. Download or clone this repository.
2. Make sure the required packages are installed.
3. Open `DLsetA.ipynb` in Jupyter Notebook, JupyterLab, or Visual Studio Code.
4. Run the cells from top to bottom.
5. Check the generated graphs, evaluation outputs, and saved model files.

Some tasks download datasets or pretrained models from online sources, so an internet connection may be needed on the first run.

## Main File

- `DLsetA.ipynb` — notebook containing the practical tasks and code.

## Outputs

Depending on successful execution, the notebook may generate:

- Trained model files, including `ann_diabetes_model.h5`
- Sample and processed image files
- Training and evaluation plots
- Prediction and sentiment-analysis outputs

Generated files will appear in the notebook's working directory unless a different path is specified in the code.

## Notes

- Run the notebook in order because later cells may depend on variables created earlier.
- Training time and model accuracy depend on the computer, software environment, and dataset.
- Review the output of each task and complete the reflection and results sections before submission.
