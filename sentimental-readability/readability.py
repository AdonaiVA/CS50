from cs50 import get_string
import math


def count_letters(text):
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return letters


def count_words(text):
    words = 1
    for char in text:
        if char.isspace():
            words += 1
    return words


def count_sentences(text):
    sentences = 0
    for char in text:
        if char == '.' or char == '!' or char == '?':
            sentences += 1
    return sentences


text = get_string("Text: ")

num_letters = count_letters(text)
num_words = count_words(text)
num_sentences = count_sentences(text)

L = (num_letters / num_words) * 100.0
S = (num_sentences / num_words) * 100.0

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
