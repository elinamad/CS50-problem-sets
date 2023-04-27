# make readability.c into python

import cs50


def main():
    # input text
    text = cs50.get_string("text:")
    letters = 0
    words = 1
    sentences = 0

    # count letters, words and sentences
    for i in range(len(text)):
        if text[i].isalpha():
            letters += 1
        if text[i].isspace():
            words += 1
        if text[i] == '!':
            sentences += 1
        if text[i] == '?':
            sentences += 1
        if text[i] == '.':
            sentences += 1

    # calculate the averages
    L = ((letters / words) * 100)
    S = ((sentences / words) * 100)

    # calculate the index
    subindex = (0.0588 * L - 0.296 * S - 15.8)
    index = round(subindex)

    # print the grade level
    if index < 0:
        print("Before Grade 1")
    if index > 0 and index < 16:
        print(f"Grade {index}")
    if index > 16:
        print("Grade 16+")


main()