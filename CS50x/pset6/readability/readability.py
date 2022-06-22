from cs50 import get_string


def main():
    text = get_string("Text: ")
    countL = count_letters(text)
    countW = count_words(text) + 1
    countS = count_sentences(text)

    L = (countL * 100) / countW
    S = (countS * 100) / countW

    grade = round(0.0588 * L - 0.296 * S - 15.8)

    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade: {grade}")


def count_letters(text):
    count = 0
    for l in text:
        if l.lower() in ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']:
            count += 1
    return count


def count_words(text):
    count = 0
    for l in text:
        if l in [' ', '\n']:
            count += 1
    return count


def count_sentences(text):
    count = 0
    for l in text:
        if l in ['.', '?', '!']:
            count += 1
    return count


if __name__ == '__main__':
    main()