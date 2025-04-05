import numpy as np
import pandas as pd
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Embedding, LSTM, Dense, Dropout
from tensorflow.keras.preprocessing.text import Tokenizer
from tensorflow.keras.preprocessing.sequence import pad_sequences
from sklearn.metrics import classification_report
from sklearn.model_selection import train_test_split

# Load AG News Dataset
from datasets import load_dataset

data = load_dataset('ag_news')
train_data = data['train']
test_data = data['test']

texts = train_data['text'] + test_data['text']
labels = np.array(train_data['label'] + test_data['label'])

# Preprocessing
max_vocab_size = 10000
max_sequence_length = 100
embedding_dim = 100

# Tokenize and pad sequences
tokenizer = Tokenizer(num_words=max_vocab_size)
tokenizer.fit_on_texts(texts)
sequences = tokenizer.texts_to_sequences(texts)
x_data = pad_sequences(sequences, maxlen=max_sequence_length)

# Split data
x_train, x_test, y_train, y_test = train_test_split(x_data, labels, test_size=0.2, random_state=42)

# Build Model
model = Sequential([
    Embedding(input_dim=max_vocab_size, output_dim=embedding_dim, input_length=max_sequence_length),
    LSTM(128, return_sequences=False),
    Dropout(0.5),
    Dense(64, activation='relu'),
    Dropout(0.5),
    Dense(4, activation='softmax')  # 4 classes for AG News
])

model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])
model.summary()

# Train Model
history = model.fit(x_train, y_train, epochs=5, batch_size=32, validation_split=0.2)

# Evaluate Model
test_loss, test_accuracy = model.evaluate(x_test, y_test)
predictions = model.predict(x_test)
y_pred = np.argmax(predictions, axis=1)

# Metrics
report = classification_report(y_test, y_pred, target_names=['Class 1', 'Class 2', 'Class 3', 'Class 4'])
print("Test Accuracy:", test_accuracy)
print("\nClassification Report:\n", report)

# Misclassified Samples
misclassified_indices = np.where(y_pred != y_test)[0]
for i in misclassified_indices[:5]:  # Show first 5 misclassified samples
    print(f"Text: {texts[i]}\nTrue Label: {y_test[i]}\nPredicted Label: {y_pred[i]}\n")
