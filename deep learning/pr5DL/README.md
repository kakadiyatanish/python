# IMDB Movie Review Sentiment Analysis

This project explores sentiment classification on IMDB movie reviews using neural networks. The notebook covers text preprocessing, recurrent neural network concepts, model training, evaluation, and sentiment prediction on custom review text.

## Project Overview

The notebook includes:

- Loading and inspecting the IMDB review dataset
- Removing duplicate rows and cleaning review text
- Analysing review lengths, tokenising text, and padding/truncating sequences
- Building an ANN baseline
- Demonstrating manual forward propagation with NumPy and verifying it with Keras
- Comparing sequence-to-sequence input/output patterns for RNNs
- Training and evaluating a SimpleRNN model
- Exploring backpropagation through time (BPTT), vanishing gradients, exploding gradients, and gradient clipping
- Building and comparing LSTM and GRU models
- Comparing model performance using metrics and plots
- Performing error analysis and predicting sentiment for custom sentences

## Dataset

The notebook expects a CSV file named `IMDB Dataset.csv` in the same directory as the notebook. It should contain these columns:

- `review`: the movie review text
- `sentiment`: the sentiment label, expected to be `positive` or `negative`

The dataset file is not included automatically. Place your dataset CSV beside the notebook before running it.

## Requirements

- Python 3.9+ (a compatible Python version for your installed TensorFlow release is recommended)
- TensorFlow
- scikit-learn
- pandas
- NumPy
- Matplotlib
- Seaborn
- Jupyter Notebook or JupyterLab

Install the main dependencies with:

```bash
pip install tensorflow scikit-learn pandas numpy matplotlib seaborn jupyter
```

## How to Run

1. Clone or download this repository/project folder.
2. Put `IMDB Dataset.csv` in the same directory as `pr_5(1).ipynb`.
3. Install the dependencies listed above.
4. Start Jupyter:

   ```bash
   jupyter notebook
   ```

5. Open `pr_5(1).ipynb` and run the cells from top to bottom.

Some later cells use trained models and variables created earlier in the notebook, so run the notebook in order. Training time depends on your hardware and dataset size.

## Text Processing

The notebook cleans reviews by converting text to lowercase, removing HTML-like tags and most non-letter characters, and normalising whitespace. It maps sentiment labels to numeric values (`positive` = `1`, `negative` = `0`), splits the data into training and testing sets, converts text to token sequences, and pads/truncates sequences to a common length.

## Models and Evaluation

The models and experiments include:

- **ANN baseline:** embedding, flattening, and dense layers
- **SimpleRNN:** recurrent model for sequence-based sentiment classification
- **LSTM:** gated recurrent model designed to retain information over longer sequences
- **GRU:** gated recurrent model with update and reset gates

The notebook evaluates models and compares their results using classification metrics such as accuracy, precision, recall, F1-score, and ROC-AUC, along with plots, confusion matrices, and error analysis where implemented. Actual scores depend on the dataset, training configuration, and runtime environment; refer to the notebook output for measured results.

## Sentiment Prediction

The notebook defines a `predict_sentiment(text)` function that cleans a sentence, tokenises and pads it, then returns a predicted label (`positive` or `negative`) and a positive-class probability. The function relies on the preprocessing objects and selected model having already been created by running the notebook.

## Output Files

The notebook creates a `plots/` directory for visualisations. It also contains a cell that writes a `requirements.txt` file listing the main Python dependencies.

## Notes

- Run all cells in sequence to ensure the tokenizer, sequence length, model objects, and evaluation results are available.
- The notebook may require substantial memory and training time when using the full dataset.
- Review the notebook outputs for the final model selection and actual performance values.
