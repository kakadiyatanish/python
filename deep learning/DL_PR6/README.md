# PR6DL — Transformer and NLP Practical Notebook

## Overview
This repository contains a Jupyter Notebook (`PR6DL.ipynb`) exploring Transformer models and natural language processing (NLP). It combines conceptual explanations, hands-on implementations, visualizations, and experiments using pretrained models.

## Topics Covered

### Task 1: Introduction, Pipelines, and Tokenization
- Hugging Face sentiment-analysis pipeline
- Transformer history, impact, and limitations
- Tokenization, subwords, special tokens, padding, and batching
- DistilBERT model configuration and parameter inspection

### Task 2: Self-Attention
- Numerically stable softmax and scaled dot-product attention
- Attention heatmaps and scaling experiments
- Comparison with Luong dot attention
- Input order and positional information
- Verification of manually calculated attention against DistilBERT

### Task 3: Multi-Head Attention and Normalization
- Extracting and visualizing attention heads
- Attention entropy
- Sinusoidal and learned positional embeddings
- Layer normalization implemented with NumPy
- Comparison of layer normalization and batch normalization

### Task 4: Transformer Encoder and Masks
- Encoder architecture and module inspection
- Parameter counts by model component
- Masked-word prediction with DistilBERT
- Bidirectional attention and causal masking
- GPT-2 attention and padding masks

### Task 5: Transformer Decoder and Text Generation
- Decoder architecture and cross-attention
- Translation and summarization with T5
- Greedy generation, beam search, and sampling
- Key-value cache experiments
- Comparison of encoder-only, decoder-only, and encoder-decoder model families

### Task 6: Evaluation and Mini Text Toolkit
- Sentiment evaluation using IMDB reviews
- Performance comparisons for different input lengths
- Inference-time measurements
- Examination of GPT-2 factual reliability
- Building a mini text toolkit and reflecting on the experiments

## Technologies and Libraries
The notebook uses Python and includes libraries such as:
- NumPy
- pandas
- PyTorch
- Matplotlib
- Seaborn
- Hugging Face Transformers

Some tasks download pretrained models and may require an internet connection the first time they run.

## Setup

1. Install Python and Jupyter Notebook, or use JupyterLab / VS Code notebooks.
2. Install the required libraries in your active Python environment:

```bash
pip install numpy pandas torch matplotlib seaborn transformers jupyter
```

3. Open `PR6DL.ipynb` in Jupyter Notebook, JupyterLab, or VS Code.
4. Run the notebook cells from top to bottom.

If your environment does not support PyTorch or a particular model version, install a compatible version for your Python version and operating system.

## Notes
- Model downloads can take time and require internet access.
- Inference speed depends on the computer and whether a supported GPU is available.
- Some evaluation sections may use datasets or model downloads and can take longer to execute.
- Run setup/import cells before running the related task cells.

## Project Structure

```text
.
├── PR6DL.ipynb
└── README.md
```

## Purpose
The notebook is intended for practical learning and experimentation with Transformer architectures, attention mechanisms, tokenization, model inference, and basic NLP evaluation.
